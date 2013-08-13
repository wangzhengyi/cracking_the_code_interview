/**
 * Given a sorted(increasing order)array, write an algorithm to create a binary tree with minimal height
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct btree {
	struct btree *lchild, *rchild;
	int data;
} btree;

/**
 * qsort比较函数
 *
 * T = O(nlogn)
 *
 */
int compare(const void *p, const void *q)
{
	const int *a = p;
	const int *b = q;

	return *a - *b;
}

/**
 * 根据有序序列arr创建最小高度的二叉树
 *
 * T = O(logn)
 *
 */
void createMinimalTree(btree **t, int *arr, int begin, int end)
{
	int mid;
	*t = NULL;

	if (begin <= end) {
		mid = (begin + end) / 2;
		*t = (btree *)malloc(sizeof(**t));
		(*t)->data = arr[mid];
		createMinimalTree(&(*t)->lchild, arr, begin, mid - 1);
		createMinimalTree(&(*t)->rchild, arr, mid + 1, end);
	}
}

/**
 * 二叉树的递归前序遍历
 */
void preTraverse(btree *t)
{
	if (t) {
		printf("%d ", t->data);
		preTraverse(t->lchild);
		preTraverse(t->rchild);
	}
}


int main(void)
{
	int i, n, *arr;
	btree *t;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);

		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);

		qsort(arr, n, sizeof(arr[0]), compare);

		createMinimalTree(&t, arr, 0, n - 1);

		preTraverse(t);
		printf("\n");

		free(arr);
	}

	return 0;
}
