/**
 * write an algorithm such that if an element in an M * N matrix is 0,
 * its entrie row and column is set to 0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 将0所在的行，列置为0
 *
 * T = O(m * n)
 *
 */
void zeroMatrix(int **matrix, int m, int n)
{
	int i, j, *row, *column;
	row = (int *)malloc(sizeof(int) * m);
	column = (int *)malloc(sizeof(int) * n);
	memset(row, 0, sizeof(row));
	memset(column, 0, sizeof(column));

	// 找出0元素的位置
	for (i = 0; i < m; i ++) {
		for (j = 0; j < n; j ++) {
			if (*(*(matrix + i) + j) == 0) {
				row[i] = 1;
				column[j] = 1;
			}
		}
	}

	// 置0
	for (i = 0; i < m; i ++) {
		for (j = 0; j < n; j ++) {
			if (row[i] || column[j])
				matrix[i][j] = 0;
		}
	}
}

/**
 * 打印矩阵
 *
 * T = O(m * n)
 */
void printMatrix(int **matrix, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i ++) {
		for (j = 0; j < n; j ++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

}

int main(void)
{
	int i, j, m, n, **matrix;

	while (scanf("%d %d", &m, &n) != EOF) {
		// 动态申请二维数组内存空间
		matrix = (int **)malloc(sizeof(int *) * m);
		for (i = 0; i < m; i ++)
			matrix[i] = (int *)malloc(sizeof(int) * n);


		// 接收矩阵元素
		for (i = 0; i < m; i ++)
			for (j = 0; j < n; j ++)
				scanf("%d", &matrix[i][j]);

		printMatrix(matrix, m, n);

		zeroMatrix(matrix, m, n);

		printMatrix(matrix, m, n);

		// 手动释放
		for (i = 0; i < m; i ++)
			free(matrix[i]);
	}

	return 0;
}
