/**
 * Write a method to randomly generate a set of m integers from an array of size n. Each
 * element must have equal probability of being chosen
 */

#include <stdio.h>
#include <stdlib.h>

#define N 10

int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

/**
 * 使用异或进行数值交换
 */
void swap(int *a, int *b)
{
	if (*a != *b) {
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}
}

/**
 * 随机选出m个数
 *
 */
void createRandom(int m)
{
	int i, loc;

	for (i = 0; i < m; i ++) {
		loc = rand() % (N - i) + i;	// 随机生成i ～ n - 1
		swap(arr + i, arr + loc);
	}
}


int main(void)
{
	int i, j, m;

	while (scanf("%d", &m) != EOF) {
		for (i = 0; i < m; i ++) {
			createRandom(m);
			for (j = 0; j < m; j ++)
				printf("%d ", arr[j]);
			printf("\n");
		}
	}

	return 0;
}
