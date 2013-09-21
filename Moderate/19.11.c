/**
 * Design an algorithm to find all pairs of integers within an array which sum to a 
 * specified value.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 首尾指针计算等于specified的整数对
 *
 * T = O(n)
 *
 */
int calculate(int *arr, int n, int specified)
{
	int bt, ed, count, value;

	for (bt = 0, ed = n - 1, count = 0; bt < ed;) {
		value = arr[bt] + arr[ed];

		if (value > specified) {
			ed --;
		} else if (value < specified) {
			bt ++;
		} else {
			count ++;
			bt ++;
		}
	}

	return count;
}

/**
 * 快排比较函数
 */
int compare(const void *a, const void *b)
{
	const int *p = a;
	const int *q = b;

	return *p - *q;
}

int main(void)
{
	int i, n, specified, count, *arr;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);

		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);

		scanf("%d", &specified);

		qsort(arr, n, sizeof(arr[0]), compare);

		count = calculate(arr, n, specified);

		printf("%d\n", count);
	}

	return 0;
}
