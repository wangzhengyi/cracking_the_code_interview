/**
 * Given an image repreented by an N * N matrix, where each pixel in the image
 * is 4 bytes,write a method to rotate the image by 90 degrees
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * 打印二维矩阵
 *
 * T = O(n * n)
 *
 */
void printMatrix(int **matrix, int n)
{
	int i, j;

	for (i = 0; i < n; i ++) {
		for (j = 0; j < n; j ++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

/**
 * 根据规律90度旋转矩阵
 *
 * T = O(n * n)
 *
 */
void transMatrix(int **matrix, int n)
{
	int i, j, **mirror;

	mirror = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i ++)
		mirror[i] = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i ++) {
		for (j = 0; j < n; j ++) {
			mirror[j][n - i - 1] = matrix[i][j];
		}
	}

	printMatrix(mirror, n);

	for (i = 0; i < n; i ++)
		free(mirror[i]);
}


int main(void)
{
	int i, j, n, **matrix;

	while (scanf("%d", &n) != EOF) {
		// 动态申请二维矩阵
		matrix = (int **)malloc(sizeof(int *) * n);
		for (i = 0; i < n; i ++)
			matrix[i] = (int *)malloc(sizeof(int) * n);

		for (i = 0; i < n; i ++)
			for (j = 0; j < n; j ++)
				scanf("%d", &matrix[i][j]);

		printMatrix(matrix, n);

		transMatrix(matrix, n);


		// 手动释放
		for (i = 0; i < n; i ++)
			free(matrix[i]);
	}

	return 0;
}
