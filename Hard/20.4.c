/**
 * Write a method to count the number of 2s between 0 and n
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 暴力法求解
 *
 * T = O(nlogn)
 *
 */
int count2(int n)
{
	int count = 0;

	while (n) {
		if (n % 10 == 2)	count ++;

		n /= 10;
	}

	return count;
}

int calViolentTwo(int n)
{
	int i, num;

	for (i = 0, num = 0; i <= n; i ++) {
		num += count2(i);
	}

	return num;
}


/**
 * 数学方法
 *
 * T = O(lnN/ln10)
 */ 
int calTwo(int n)
{
	int low, high, cur, factor = 1, num = 0;

	while (n / factor) {
		cur = (n / factor) % 10;
		low = n - (n / factor) * factor;
		high = n / (factor * 10);

		switch (cur) {
			case 0 :
			case 1 :
				num += high * factor;
				break;
			case 2 :
				num += high * factor + low + 1;
				break;
			default :
				num += (high + 1) * factor;
				break;
		}

		factor *= 10;
	}

	return num;
}


int main(void)
{
	int n, num;

	while (scanf("%d", &n) != EOF) {
		num = calTwo(n);

		printf("%d\n", num);

		num = calViolentTwo(n);
		printf("%d\n", num);
	}

	return 0;
}
