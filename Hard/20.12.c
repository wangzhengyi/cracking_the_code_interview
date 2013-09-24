/** 
 * Given an N*N matrix of positive and negative integers, write code to find the
 * submatrix with the largest possible sum
 *
 * 九度oj：http://ac.jobdu.com/problem.php?pid=1139
 */

#include <stdio.h>
#include <stdlib.h>

#define N 101

/**
 * 动态规划求解最大子矩阵
 *
 *
 */
void dynamicLis(int matrix[N][N], int n)
{
	int i, j, h, k, cur, sum, max;

	max = matrix[0][0];

	for (i = 0; i < n; i ++) {
		for (j = i; j < n; j ++) {
			// 初始化
			for (h = i, sum = 0; h <= j; h ++) {
				sum += matrix[h][0];
			}		

			if (sum > max)	max = sum;

			// lis
			for (h = 1; h < n; h ++) {
				for (k = i, cur = 0; k <= j; k ++) {
					cur += matrix[k][h];
				}
				if (sum >= 0)	sum += cur;
				else			sum = cur;

				if (sum > max)	max = sum;
			}

		}
	}

	printf("%d\n", max);
}


int main(void)
{
	int i, j, n, matrix[N][N];

	while (scanf("%d", &n) != EOF) {
		// 接收矩阵
		for (i = 0; i < n; i ++) {
			for (j = 0; j < n; j ++) 
				scanf("%d", &matrix[i][j]);
		}

		// 动态规划
		dynamicLis(matrix, n);
	}

	return 0;
}


