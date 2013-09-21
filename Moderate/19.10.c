/**
 * Write a method to generate a random number between 1 and 7, given a method
 * that generates a random number between 1 and 5.(i.e., implement rand7() using
 * rand5())
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * 产生1-5的随机函数
 */
int rand5()
{
	return rand() % 5 + 1;
}

/**
 * 利用rand5产生rand7
 */
int rand7()
{
	int x = 5 * (rand5() - 1) + rand5();

	while (x > 7) {
		x = 5 * (rand5() - 1) + rand5();
	}

	return x;
}

int main(void)
{
	int i, n;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i ++) {
			// 测试rand5
			printf("%d\n", rand5());
		}

		for (i = 0; i < n; i ++) {
			// 测试rand7
			printf("%d\n", rand7());
		}
	}

	return 0;
}
