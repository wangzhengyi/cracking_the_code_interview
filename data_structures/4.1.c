/**
 * Implement a function to check if a tree is balanced. For the purpose of this question,
 * a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
 * from the root by more than one.
 */

#include <stdio.h>
#include <stdlib.h>

#define NODENUM 1000

typedef struct btree {
	struct btree *lchild, *rchild;
	char item;
} btree;

typedef struct stack {
	int top;
	btree* data[NODENUM];
} stack;


char str[NODENUM];
int count;
int depth[NODENUM];
int len;

/**
 * 根据完整前序遍历序列构建二叉树
 *
 * T = O(n)
 *
 */
void createBtree(btree **t)
{
	if (str[count ++] == '#' || str[count - 1] == '\0') {
		*t = NULL;
	} else {
		// ->优先级高于*
		*t = (btree *)malloc(sizeof(btree));
		(*t)->item = str[count - 1];
		createBtree(&(*t)->lchild);
		createBtree(&(*t)->rchild);
	}
}

/**
 * 后序遍历求叶子节点的深度
 *
 * T = O(n)
 *
 */
void postTraverse(btree *t)
{
	stack *s = (stack *)malloc(sizeof(stack));
	s->top = 0;

	btree *pre = NULL;

	while (s->top > 0 || t != NULL) {
		if (t) {
			s->data[s->top ++] = t;
			t = t->lchild;
		} else {
			t = s->data[-- s->top];
			if (t->rchild == NULL || t->rchild == pre) {
				if (t->lchild == NULL && t->rchild == NULL) {	// 叶子节点
					depth[len ++] = s->top + 1;
					// 打印测试
					printf("叶子节点为%c, 深度为%d\n", t->item, s->top + 1);
				}
				pre = t;
				t = NULL;
			} else {	// 相对根节点
				s->data[s->top ++] = t;
				t = t->rchild;
			}
		}
	}
}

/**
 * 快排调用功能函数
 *
 */
int compare(const void *p, const void *q)
{
	const int *a = p;
	const int *b = q;

	return *a - *b;
}

int main(void)
{
	btree *t;

	while (scanf("%s", str) != EOF) {
		count = 0;
		createBtree(&t);
		len = 0;
		postTraverse(t);
		qsort(depth, len, sizeof(depth[0]), compare);
		
		if (depth[len - 1] - depth[0] > 1) 
			printf("不平衡!\n");
		else
			printf("平衡!\n");
	}

	return 0;
}
