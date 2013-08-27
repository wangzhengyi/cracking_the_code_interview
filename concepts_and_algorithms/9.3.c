/**
 * Given a sorted array of n integers that has been rotated an unknow number of
 * times, given an O(logn) algorithm that finds an element in the array. You may
 * assume that the array was originally sorted in increasing order
 * EXAMPLE:
 * Input:find 5 in array(15 16 19 20 25 1 3 4 5 7 10 14)
 * Output:8(the index of 5 in array)
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 模拟二分查找，考虑情况更多一些
 *
 * T = O(logn)
 *
 */
int findKey(int *arr, int begin, int end, int key)
{
	int mid;

	while (begin <= end) {
		mid = (begin + end) / 2;

		if (arr[mid] == key) {
			return mid;
		} else if (arr[mid] > key) {
			if (arr[mid] > arr[begin]) { // 前半段
				if (arr[begin] > key) {
					begin = mid + 1;
				} else {
					end = mid - 1;
				}
			} else { // 后半段
				end = mid - 1;
			}
		} else {
			if (arr[mid] > arr[begin]) {
				begin = mid + 1;
			} else {
				if (arr[end] < key) {
					end = mid - 1;
				} else {
					begin = mid + 1;
				}
			}
		}	
	}

	return -1;
}


int main(void)
{
	int i, n, key, loc, *arr;
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i ++) 
		scanf("%d", arr + i);


	while (scanf("%d", &key) != EOF) {
		loc = findKey(arr, 0, n - 1, key);
		printf("%d\n", loc);
	}

	free(arr);
	return 0;
}
