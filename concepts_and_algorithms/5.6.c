/**
 * Write a program to swap odd and even bits in an integer with as few instructions as
 * possible(e.g.,bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc)
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 打印整数n的bit位
 *
 * T = O(logn)
 *
 */
void printBit(int n)
{
	char str[100];
	int i;

	for (i = 0; n != 0 || i < 32; i ++, n >>= 1) {
		if (n & 1)	str[i] = '1';
		else	str[i] = '0';
	}

	// 打印
	for (int j = i - 1; j >= 0; j --) {
		printf("%c", str[j]);
	}
	printf("\n");
}

int main(void)
{
	int n;

	while (scanf("%d", &n) != EOF) {
		// 交换前
		printBit(n);

		// 交换
		n = (n & 0x55555555) << 1 | (n & 0xAAAAAAAA) >> 1;

		// 交换后
		printBit(n);
	}

	return 0;
}
