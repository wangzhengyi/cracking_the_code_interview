/**
 * You are given a binary tree in which each node contains a value. Design an algorithm
 * to print all paths which sum up to that value. Note that it can by any path in the tree
 * -it does not have to start at the root.
 * 类似九度二叉树中和为某一值的路径:http://ac.jobdu.com/problem.php?pid=1368
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10005

typedef struct btree {
	struct btree *lchild, *rchild;
	int data, loc;
} btree;

typedef struct node {
	int value, lchild, rchild;
} node;

typedef struct stack {
	int top;
	btree* data[N];
} stack;

btree* bt[N];
node arr[N];
stack *s;

/**
 * 创建二叉树节点 
 *
 * T = O(1)
 *
 */
void createBtree(btree **t, int data, int loc)
{
	*t = (btree *)malloc(sizeof(btree));
	(*t)->data = data;
	(*t)->loc = loc;
	(*t)->lchild = (*t)->rchild = NULL;
}

/**
 * 连接二叉树节点
 *
 * T = O(1)
 *
 */
void connectBtree(btree *root, int lchild, int rchild)
{
	if (root != NULL) {
		root->lchild = (lchild == -1) ? NULL : bt[lchild - 1];
		root->rchild = (rchild == -1) ? NULL : bt[rchild - 1];
	}
}

/**
 * 递归打印序列
 */
void printSumPath(btree *root, int k)
{
	int i, sum;
	btree *left, *right;
	if (root == NULL)	return;

	s->data[s->top ++] = root;
	left = root->lchild;
	right = root->rchild;

	// 叶子节点
	if (left == NULL && right == NULL) {
		for (i = sum = 0; i < s->top; i ++) {
			sum += s->data[i]->data;
		}
		if (sum == k) {
			printf("A path is found: ");
			for (i = 0; i < s->top; i ++) {
				if (i == s->top - 1)
					printf("%d\n", s->data[i]->loc);
				else
					printf("%d ", s->data[i]->loc);
			}
		}
	}

	printSumPath(root->lchild, k);
	printSumPath(root->rchild, k);

	s->top --;
}


int main(void)
{
	int i, n, k;
	
	while (scanf("%d %d", &n, &k) != EOF) {
		// 构建二叉树
		for (i = 0; i < n; i ++) {
			scanf("%d %d %d", &arr[i].value, &arr[i].lchild, &arr[i].rchild);
			createBtree(&bt[i], arr[i].value, i + 1);
		}
		
		for (i = 0; i < n; i ++) {
			connectBtree(bt[i], arr[i].lchild, arr[i].rchild);
		}

		// 遍历二叉树
		s = (stack *)malloc(sizeof(stack));
	   	s->top = 0;

		printf("result:\n");
		printSumPath(bt[0], k);
	}

	return 0;
}
