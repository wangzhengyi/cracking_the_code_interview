/**
 * Write a function to swap a number in place without temporary variables
 */

#include <stdio.h>

/**
 * 采用异或的方法实现a和b之间的swap
 */
void swapBit(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

/**
 * 通过加减运算实现a和b之间的swap
 *
 */
void swapOpe(int *a, int *b)
{
	*b = *a - *b;
	*a = *a - *b;
	*b = *a + *b;
}

int main(void)
{
	int a, b;

	while (scanf("%d %d", &a, &b) != EOF) {
		printf("%d %d\n", a, b);

		swapBit(&a, &b);
		printf("%d %d\n", a, b);

		swapOpe(&a, &b);
		printf("%d %d\n", a, b);
	}

	return 0;
} 

