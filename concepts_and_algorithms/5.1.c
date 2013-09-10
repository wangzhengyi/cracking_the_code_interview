/**
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a
 * method to set all bits between i and j in N equals to M
 */

#include <stdio.h>

/**
 * 将n的i-j位替换为m，注意j-i+1一定为m可用位数的长度
 *
 */
void updateBits(int n, int m, int i, int j)
{
	int ret;

	// 保留0-i-1位
	ret = (1 << i) - 1;
	ret = ret & n;

	// 将n的0到j位清空
	n >>= j + 1;
	n <<= j + 1;

	// 将i到j位替换为m
	n = n | m << i;

	// 补全0-i-1位
	n = n | ret;
	
	printf("%d\n", n);
}


int main(void)
{
	int i, j, n, m;

	while (scanf("%d %d %d %d", &n, &m, &i, &j) != EOF) {
		updateBits(n, m, i, j);
	}

	return 0;
}
