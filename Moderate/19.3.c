/**
 * Write an algorithm which computes the number of trailing zeros in n factorial
 * n的阶乘取决于n中5的个数
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 通过5的数量计算N阶乘中0的数量
 */
int numZeros(int n)
{
	int count = 0;

	while (n) {
		count += n / 5;
		n /= 5;
	}

	return count;
}

/**
 * 计算5的数量方法2
 *
 */
int numZeros2(int n)
{
	int i, j, count = 0;

	for (i = 1; i <= n; i ++) {
		j = i;

		while (j % 5 == 0) {
			count ++;
			j /= 5;
		}
	}

	return count;
}


/**
 * 计算阶乘，取余求0的数量
 */
long long int calNumZeros(int n)
{
	long long int count, sum;

	// 计算n的阶乘
	for (sum = 1; n; n --) {
		sum *= n;
	}

	// 计算sum中0的个数
	count = 0;
	while (sum) {
		if (sum % 10 == 0) {
			count ++;
		} else {
			break;
		}
		sum /= 10;
	}

	return count;
}

int main(void)
{
	int n;

	while (scanf("%d", &n) != EOF) {
		printf("%d\n", numZeros(n));

		printf("%d\n", numZeros2(n));

		printf("%lld\n", calNumZeros(n));
	}

	return 0;
}


