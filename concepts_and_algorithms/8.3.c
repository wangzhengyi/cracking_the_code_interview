/**
 * Write a method that returns all subsets of a set
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 通过0到2^-1来标识子集
 *
 * T = (n * 2^n)
 *
 */
void getSubset(char *str, int len)
{
	int i, max, index, j;

	max = 1 << len;

	for (i = 1; i < max; i ++) {
		j = i;
		index = 0;

		while (j) {
			if (j & 1) {
				printf("%c", str[index]);
			}
			j >>= 1;
			index ++;
		}
		printf("\n");
	}
}

int main(void)
{
	char str[1000];

	while (scanf("%s", str) != EOF) {
		getSubset(str, strlen(str));

	}

	return 0;
}
