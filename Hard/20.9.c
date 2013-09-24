#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 256

/**
 * 交换两个数组元素
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
 * 打印数组元素
 */
void printArray(int *a)
{
	int i, len = a[0];

	for (i = 0; i < len; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

/**
 * 维护从i位置开始的最小堆
 */
void minHeapify(int *heap, int i, int n)
{
	int loc, left, right, tmp;

	while (i <= n) {
		left = 2 * i;
		right = 2 * i + 1;
		loc = i;

		if (left <= n && heap[left] < heap[i]) {
			i = left;
		}

		if (right <= n && heap[right] < heap[i]) {
			i = right;
		}

		if (i != loc) {
			tmp = heap[i];
			heap[i] = heap[loc];
			heap[loc] = tmp;
		} else {
			break;
		}
	}
}

/**
 * 最小堆插入操作
 *
 */
void minHeapInsert(int *heap, int key)
{
	int i;

	heap[0] ++;

	heap[heap[0]] = key;

	for (i = heap[0] / 2; i >= 1; i --) {
		minHeapify(heap, i, heap[0]);
	}
}

/**
 * 维护从第i个位开始的最大堆
 */
void maxHeapify(int *arr, int i, int n)
{
	int left, right, loc, tmp;

	while (i < loc) {
		left = 2 * i;
		right = 2 * i + 1;
		loc = i;

		if (left < n && arr[left] > arr[i]) {
			i = left;
		}

		if (right < n && arr[right] > arr[i]) {
			i = right;
		}

		if (i != loc) {
			tmp = arr[i];
			arr[i] = arr[loc];
			arr[loc] = tmp;
		} else {
			break;
		}
	}
}

/**
 * 向最大堆中插入元素
 */
void maxHeapInsert(int *heap, int key)
{
	int i;

	heap[0] ++;
	heap[heap[0]] = key;

	for (i = heap[0] / 2; i >= 1; i --) {
		maxHeapify(heap, i, heap[0]);
	}
}

/**
 * 获取最大堆的堆顶元素
 */
int maxHeapPop(int *heap)
{
	int max;

	max = heap[1];
	heap[1] = heap[heap[0]];

	heap[0] --;

	maxHeapify(heap, 1, heap[0]);

	return max;
}

/**
 * 获取最小堆的堆顶元素
 */
int minHeapPop(int *heap)
{
	int min;

	min = heap[1];
	heap[1] = heap[heap[0]];

	heap[0] --;

	minHeapify(heap, 1, heap[0]);

	return min;
}


int findMediansByHeap(int *arr, int *max_heap, int *min_heap)
{
	int i, m;

	for (i = 1, m = arr[i]; i <= arr[0]; i ++) {
		if (m < arr[i])
			minHeapInsert(min_heap, arr[i]);
		else
			maxHeapInsert(max_heap, arr[i]);


		if (max_heap[0] - min_heap[0] == 2) {
			m = maxHeapPop(max_heap);
			minHeapInsert(min_heap, m);
		} else if (min_heap[0] - max_heap[0] == 2) {
			m = minHeapPop(min_heap);
			maxHeapInsert(max_heap, m);
		}
	}
	if ((max_heap[0] + max_heap[0]) % 2 == 0) {
		return (max_heap[1] + min_heap[1]) / 2;
	} else if (max_heap[0] > min_heap[0]) {
		return max_heap[0];
	} else {
		return min_heap[0];
	}
}


int main()
{
	int i, n, res, arr[MAXLINE], max_heap[MAXLINE], min_heap[MAXLINE];

	while (scanf("%d", &n) != EOF) {
		// 初始化堆的大小
		max_heap[0] = 0;
		min_heap[0] = 0;

		arr[0] = n;
		for (i = 1; i <= n; i ++)
			scanf("%d", arr + i);

		res = findMediansByHeap(arr, max_heap, min_heap);

		printf("%d\n", res);
	}


	return 0;
}


