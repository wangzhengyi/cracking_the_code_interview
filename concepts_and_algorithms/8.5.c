/**
 * Implement an angorithm to print all valid(e.g, properly opened and closed) combinations
 * of n-pairs of parentheses.
 * EXAMPLE:
 * input:3(e.g, 3 pairs of parentheses)
 * output:()()(),()(()),(())(),((()))
 */

#include <stdio.h>
#include <stdlib.h>

char str[1000];

/**
 * 递归调用解决括号打印问题
 */
void printPare(int left, int right, int cnt)
{
	if (left < 0 || right < left)	return;

	if (left == 0 && right == 0) {
		for (int i = 0; i < cnt; i ++)
			printf("%c", str[i]);
		printf("\n");
	} else {
		if (left > 0) {
			str[cnt] = '(';
			printPare(left - 1, right, cnt + 1);
		}

		if (right > left) {
			str[cnt] = ')';
			printPare(left, right - 1, cnt + 1);
		}
	}
}

int main(void)
{
	int n;

	while (scanf("%d", &n) != EOF) {
		printPare(n, n, 0);
	}

	return 0;
}
