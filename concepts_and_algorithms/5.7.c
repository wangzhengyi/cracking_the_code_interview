/**
 * An array A[1..n] contains all the integers from 0 to n expect for one number which is
 * missing. In this problem, we cannot access an entire integer in A with a single opreation.
 * The elements of A are represented in binary, and the only opreation we can use to access
 * them is "fetch the jth bit of A[i]", which takes constant time. Write code to find the missing
 * integer. Can you do it in O(n) time?
 *
 * Solution:
 * 这个问题里明确我们唯一能使用的操作是fetch(a, i, j),即获取a[i]的第j位。不用在意实现细节，这是提供
 * 给我们调用的api
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 防止编译报错，模拟实现
 */
int fetch(int *a, int i, int j)
{
	return 1;
}

/**
 * 获取arr的第i位数
 */
int getArri(int *arr, int i)
{
	int ret = 0;

	for (int j = 31; j >= 0; j --) {
		ret |= fetch(arr, i, j);
		ret <<= 1;
	}
	ret >>= 1;

	return ret;
}

/**
 * 获取丢失的数据
 */
int missing(int *arr, int n)
{	
	int value, sum, mis;

	// 求arr总和
	value = 0;
	for (int i = 0; i < n; i ++) {
		value += getArri(arr, i);
	}

	// 等差公式求和
	sum = (n + 1) * (0 + n) / 2;

	// 丢失数据
	mis = sum - value;

	return mis;
}

int main(void)
{
	int mis, A[11] = {0,2,3,4,5,6,7,8,10};

	mis = missing(A, 10);

	printf("%d\n", mis);

	return 0;
}
