/**
 * You have two very large binary trees:T1, with millions of nodes, and T2,
 * with hundreds of nodes.Create an algorithm to decide if T2 is a subtree of T1.
 * 类似于九度oj的题目1520：树的子结构:http://ac.jobdu.com/problem.php?pid=1520
 * 暴力破解 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1005

typedef struct btree {
	struct btree *lchild, *rchild;
	int data;
} btree;

btree* atrees[N];
btree* btrees[N];

/**
 * 创建二叉树节点指针
 *
 * T = O(1)
 *
 */
void createBtreeNode(btree **t, int data)
{
	*t = (btree *)malloc(sizeof(btree));
	(*t)->data = data;
	(*t)->lchild = (*t)->rchild = NULL;
}

/**
 * 连接二叉树节点
 *
 * T = O(1)
 *
 */
void connectBtreeNode(btree *root, btree *left, btree *right)
{
	if (root != NULL) {
		root->lchild = left;
		root->rchild = right;
	}
}

/**
 * 递归判断左右子树是否相同
 */
int doesTree1HasTree2(btree *at, btree *bt)
{
	if (bt == NULL)
		return 1;
	if (at == NULL)
		return 0;
	if (at->data != bt->data)
		return 0;

	return doesTree1HasTree2(at->lchild, bt->lchild) && doesTree1HasTree2(at->rchild, bt->rchild);
}

/**
 * 递归判断bt是否为at的子树
 */
int isSubtree(btree *at, btree *bt)
{
	int result = 0;

	if (at != NULL && bt != NULL) {
		if (at->data == bt->data) {
			result = doesTree1HasTree2(at, bt);
		}
		if (! result) {
			result = isSubtree(at->lchild, bt);
		}
		if (! result) {
			result = isSubtree(at->rchild, bt);
		}
	}

	return result;
}

int main(void)
{
	int n, m, i, data, num, left, right;

	while (scanf("%d %d", &n, &m) != EOF) {
		// 构建A树
		for (i = 0; i < n; i ++) {
			scanf("%d", &data);
			createBtreeNode(&atrees[i], data);
		}

		for (i = 0; i < n; i ++) {
			scanf("%d", &num);
			switch (num) {
				case 2 :
					scanf("%d %d", &left, &right);
					connectBtreeNode(atrees[i], atrees[left - 1], atrees[right - 1]);
					break;
				case 1 :
					scanf("%d", &left);
					connectBtreeNode(atrees[i], atrees[left - 1], NULL);
					break;
				default :
					break;
			}
		}

		// 构建B树
		for (i = 0; i < m; i ++) {
			scanf("%d", &data);
			createBtreeNode(&btrees[i], data);
		}

		for (i = 0; i < m; i ++) {
			scanf("%d", &num);
			switch (num) {
				case 2 :
					scanf("%d %d", &left, &right);
					connectBtreeNode(btrees[i], btrees[left - 1], btrees[right - 1]);
					break;
				case 1 :
					scanf("%d", &left);
					connectBtreeNode(btrees[i], btrees[left - 1], NULL);
					break;
				default :
					break;
			}
		}

		// 判断子树
		if (m == 0 || n  == 0) {
			printf("NO\n");
			continue;
		}

		if (isSubtree(atrees[0], btrees[0])) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
