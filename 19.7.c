/**
 * You are given an array of integers (both positive and negative). Find the continuous
 * sequence with the largest sum. Return the sum
 */

#include <stdio.h>
#include <stdlib.h>

void maxSum(int *arr, int n)
{
	int i, bt, cur, ed, max, *dp;

	dp = (int *)malloc(sizeof(int) * n);
	dp[0] = max = arr[0];

	// 动态规划
	bt = ed = cur = 0;

	for (i = 1; i < n; i ++) {
		if (dp[i - 1] >= 0) {
			dp[i] = dp[i - 1] + arr[i];
		} else {
			dp[i] = arr[i];
			cur = i;
		}

		if (dp[i] > max) {
			max = dp[i];
			ed = i;
			bt = cur;
		}
	}

	// 打印输出
	printf("%d(i.e.,{", max);
	for (i = bt; i <= ed; i ++) {
		printf("%d,", arr[i]);
	}
	printf("})\n");
}

int main(void)
{
	int i, n, *arr;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);

		maxSum(arr, n);
	}

	return 0;
}
