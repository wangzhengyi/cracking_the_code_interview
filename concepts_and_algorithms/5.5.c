/**
 * Write a function to determine the number of bits required to convert integer A to integer B
 * Input: 31, 14
 * Output:2
 */

#include <stdio.h>
#include <stdlib.h>

int hash[32];

/**
 * n异或m的c，求出c二进制1的个数即为需要转换的位数
 * 
 * T = O(n)
 *
 */
int calUpdatebit(int n, int m)
{
	int count = 0, c = n ^ m;

	while (c) {
		if (c & 1)	count ++;
		c >>= 1;
	}

	return count;
}

int main(void)
{
	int n, m;

	while (scanf("%d %d", &n, &m) != EOF) {
		printf("%d\n", calUpdatebit(n, m));
	}

	return 0;
}
