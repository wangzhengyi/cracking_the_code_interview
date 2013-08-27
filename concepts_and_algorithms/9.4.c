/**
 * Given a sorted array of strings which is interspersed with empty strings, write a
 * method to find the location of a given string.
 * 我理解：类似求最小的k个数，用堆排序实现即可
 */

#include <stdio.h>
#include <stdlib.h>

void heapSort(int *arr, int n);
void maxHeapIfy(int *arr, int i, int n);

int main(void)
{
	int i, n, tmp, arr[101];

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);

		heapSort(arr, n);

		// 调整序列
		for (i = n - 1; i >= 1; i --) {
			tmp = arr[i];
			arr[i] = arr[0];
			arr[0] = tmp;
			maxHeapIfy(arr, 0, i);
		}

		// 打印输出
		for (i = 0; i < n; i ++)
			printf("%d ", arr[i]);
		printf("\n");
	}

	return 0;
}

/**
 * 构建大根堆
 *
 * T = O(nlogn)
 *
 */
void heapSort(int *arr, int n)
{
	int i;

	for (i = (n - 2) / 2; i >= 0; i --)
		maxHeapIfy(arr, i, n);
}

/**
 * 维护i开始的大根堆
 *
 * T = O(logn)
 *
 */
void maxHeapIfy(int *arr, int i, int n)
{
	int left, right, loc, tmp;

	while (i < n) {
		loc = i;
		left = i * 2 + 1;
		right = i * 2 + 2;
		
		if (left < n && arr[left] > arr[i])
			i = left;

		if (right < n && arr[right] > arr[i])
			i = right;

		if (i != loc) {
			tmp = arr[i];
			arr[i] = arr[loc];
			arr[loc] = tmp;
		} else {
			break;
		}
	}
}
