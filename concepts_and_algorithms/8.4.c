/**
 * Write a method that returns all subsets of a set.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 字符串交换函数
 *
 * T = O(1)
 *
 */
void swap(char *str, int src, int dst)
{
	char tmp;

	tmp = str[src];
	str[src] = str[dst];
	str[dst] = tmp;
}

/**
 * 字符串全排列函数
 */
void permutationStr(char *str, int begin, int end)
{
	if (begin == end) {
		puts(str);
	} else {
		int i;
		for (i = begin; i <= end; i ++) {
			swap(str, begin, i);
			permutationStr(str, begin + 1, end);
			swap(str, begin, i);
		}
	}
}


int main(void)
{
	char str[100];

	while (scanf("%s", str) != EOF) {
		permutationStr(str, 0, strlen(str) - 1);
	}

	return 0;
}
