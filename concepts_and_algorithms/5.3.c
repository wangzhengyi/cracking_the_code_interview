/**
 * Given an integer, print the next smallest and next largest number that have the same
 * number of 1 bits in their binary representations.
 */

#include <stdio.h>

/**
 * 计算二进制数中1的个数
 *
 * T = O(logn)
 *
 */
int calculateOne(int n)
{
	int count = 0;

	while (n) {
		if (n & 1)	count ++;
		n >>= 1;
	}

	return count;
}

int main(void)
{
	int n, large, small, one;

	while (scanf("%d", &n) != EOF) {
		one = calculateOne(n);
		
		large = n + 1;
		
		while (calculateOne(large) != one) {
			large ++;
		}

		printf("最大为%d\n", large);

		small = n - 1;

		while (calculateOne(small) != one && small >= 0)
			small --;

		printf("最小为%d\n", small);
	}

	return 0;
} 
