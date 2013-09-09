/**
 * Write an algorithm to print all ways of arranging eight queens on a chess board so
 * that none of them share the same row, column or diagonal.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM 8

typedef struct point {
	int x, y;
} point;

point points[1000];

int matrix[92][8];

int count;

/**
 * 判断是否符合不在同一行，同一列，同一对角线
 */
int judge(int n, int x, int y)
{
	int i;

	for (i = 1; i <= n - 1; i ++) {
		if (points[i].y == y || abs(points[i].y - y) == abs(points[i].x - x)) {
			return 0;
		}
	}
	return 1;
}

/**
 * 深度优先遍历解决八皇后问题
 */
void dfsQueue(int n, int x)
{
	if (n == NUM + 1) {
		// 得到八皇后序列
		for (int i = 0; i < 8; i ++) {
			matrix[count][i] = points[i + 1].y;
		}
		count ++;
		return;
	} else {
		int y;
		for (y = 1; y <= NUM; y ++) {
			if (judge(n, x, y)) {
				points[n].x = x;
				points[n].y = y;
				dfsQueue(n + 1, x + 1);
			}
		}
	}
}

int main(void)
{
	int i, j, n, *index;
	count = 0;
	
	dfsQueue(1, 1);

	while (scanf("%d", &n) != EOF) {
		index = (int *)malloc(sizeof(int) * n);

		for (i = 0; i < n; ++ i) {
			scanf("%d", index + i);
		}

		for (i = 0; i < n; i ++) {
			for (j = 0; j < NUM; j ++) {
				if (j == NUM - 1) {
					printf("%d\n", matrix[index[i]][j]);
				} else {
					printf("%d ", matrix[index[i]][j]);
				}
			}
		}
	}

	return 0;
}
