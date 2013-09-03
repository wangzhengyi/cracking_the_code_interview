/**
 * Write a method to generate the nth Fibonacci number
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * 递归实现fibonacci数列
 */
long long int recursionFib(long long int n)
{
	if (n < 1)
		return -1;
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;

	return recursionFib(n - 1) + recursionFib(n - 2);
}

/**
 * 非递归实现fibonacci数列
 *
 * T = O(n)
 *
 */
long long int nonrecursionFib(int n)
{
	if (n < -1)
		return -1;
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;

	long long int i, a, b, c;

	for (a = b = 1, i = 3; i <= n; i ++) {
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

/**
 * 矩阵乘法
 */
void multiMatrix(long long int c[2][2], long long int a[2][2], long long int b[2][2])
{
	long long int i, j, k, t[2][2];
	
	memset(t, 0, sizeof(t));


	for (i = 0; i < 2; i ++) {
		for (j = 0; j < 2; j ++) {
			t[i][j] = 0;
			for (k = 0; k < 2; k ++) {
				t[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	
	for (i = 0; i < 2; i ++) {
		for (j = 0; j < 2; j ++)
			c[i][j] = t[i][j];
	}
}

/**
 * 快速求fibonacci数列
 *
 * T = O(logn)
 *
 */
long long int quickFib(int n, long long int s[2][2], long long int f[2][2])
{
	if (n < 1)	return -1;
	if (n == 1 || n == 2)	return 1;

	n = n - 2;
	while (n) {
		if (n & 1)	multiMatrix(s, f, s);

		multiMatrix(f, f, f);

		n >>= 1;
	}

	return s[0][0] + s[0][1];
}


/**
 * 求data的n次幂
 *
 * T = O(n)
 *
 */
void numpow(long long int data, int n)
{
	long long int i, rs;

	for (i = 1, rs = 1; i <= n; i ++) {
		rs *= data;
	}

	printf("%lld\n", rs);
}

/**
 * 快速求data的n次幂
 *
 * T = O(logn)
 *
 */
void quickPow(long long int data, int n)
{
	long long int res;

	res = 1;

	while (n) {
		if (n & 1)	res *= data;

		data *= data;

		n >>= 1;
	}

	printf("%lld\n", res);
}

int main(void)
{
	long long int n, data;

	while (scanf("%lld", &n) != EOF) {
		long long int s[2][2] = {{1, 0}, {0, 1}};
		long long int f[2][2] = {{1, 1}, {1, 0}};


		data = quickFib(n, s, f);
		printf("%lld\n", data);


		data = recursionFib(n);
		printf("%lld\n", data);

		data = nonrecursionFib(n);
		printf("%lld\n", data);

	}

	return 0;
}
