/**
 * Write an algorithm to find the 'next' node(i.e, in-order successor) of a given node in
 * a binary search tree where each node has a link to its parent.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag, found;

typedef struct btree {
	struct btree *lchild, *rchild;
	int data;
} btree;

typedef struct stack {
	int top;
	btree* data[1000];
} stack;

stack *s;

/**
 * 根据完整的前序遍历序列构建二叉树
 */
void createBtree(btree **t)
{
	int tmp;

	scanf("%d", &tmp);

	if (tmp == 0) {
		*t = NULL;
	} else {
		*t = (btree *)malloc(sizeof(btree));
		(*t)->data = tmp;
		createBtree(&(*t)->lchild);
		createBtree(&(*t)->rchild);
	}
}

/**
 * 二叉树中查找指定节点的中序遍历的后继节点
 *
 * T = O(n)
 *
 */
void searchKey(btree *t, int key)
{
	s = (stack *)malloc(sizeof(stack));
	s->top = 0;

	while (s->top || t) {
		if (t) {
			s->data[s->top ++] = t;
			t = t->lchild;
		} else {
			t = s->data[-- s->top];
			if (found == 1) {
				flag = 1;
				printf("%d\n", t->data);
				break;
			}
			if (t->data == key) {
				found = 1;
			}
			t = t->rchild;
		}
	}
}


int main(void)
{
	int key;
	btree *t;
	createBtree(&t);

	while (scanf("%d", &key) != EOF) {

		flag = found = 0;
		searchKey(t, key);
		if (flag == 0)
			printf("无next节点!\n");
	}	

	return 0;
}
