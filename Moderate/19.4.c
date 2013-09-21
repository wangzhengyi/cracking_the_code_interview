/**
 * Write a method which finds the maxinum of two numbers. You should not use 
 * if-else or any other conparison operator
 *
 * 思路：z = a - b,判断z的符号位（负数补码存储），为0则a大于b，为1则a小于b，
 * 然后将a和b放在一个两个元素的数组里
 */

#include <stdio.h>

int arr[2];

int main(void)
{
	int a, b, z;

	while (scanf("%d %d", &a , &b) != EOF) {
		arr[0] = a;
		arr[1] = b;

		z = a - b;

		if (z >> 31 & 1) {
			printf("Max is %d\n", arr[1]);
		} else {
			printf("Max is %d\n", arr[0]);
		}
	}

	return 0;
}


