/**
 * Given a matrix in which each row and each column is sorted, write a method to find
 * an element in it
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 有序矩阵查找
 *
 * T = O(n + n)
 *
 */
void findKey(int **matrix, int n, int m, int key)
{
	int row, col;

	for (row = 0, col = m - 1; row < n && col >= 0;) {
		if (matrix[row][col] == key) {
			printf("第%d行，第%d列\n", row + 1, col + 1);
			break;
		} else if (matrix[row][col] > key) {
			col -= 1;
		} else {
			row += 1;
		}
	}
	printf("不存在!\n");
}

int main(void)
{
	int i, j, key, n, m, **matrix;
	
	// 构造矩阵
	scanf("%d %d", &n, &m);
	matrix = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i ++)
		matrix[i] = (int *)malloc(sizeof(int) * m);

	for (i = 0; i < n; i ++) {
		for (j = 0; j < m; j ++)
			scanf("%d", &matrix[i][j]);
	}

	// 查询数据
	while (scanf("%d", &key) != EOF) {
		findKey(matrix, n, m, key);		
	}
	
	return 0;
}
