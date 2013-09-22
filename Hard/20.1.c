/**
 * Write a function that adds two numbers. You shoule not use + or any arithmetic operators
 */

#include <stdio.h>

/**
 * 通过位运算求两数加法
 */
int add(int a, int b)
{
	int sum, c;

	while (b != 0) {
		sum = a ^ b;
		c = (a & b) << 1;
		a = sum;
		b = c;
	}

	return a;
}

int main(void)
{
	int a, b, sum;

	while (scanf("%d %d", &a, &b) != EOF) {
		if (b == 0) {
			printf("Sum is %d\n", a);
		} else {
			sum = add(a, b);
			printf("Sum is %d\n", sum);
		}
	}

	return 0;
}
