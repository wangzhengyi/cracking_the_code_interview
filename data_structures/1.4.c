/**
 * write a method to decide if two string are anagrams or not
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 快排比较函数
 */
int compare(const void *p, const void *q)
{
	const char *a = p;
	const char *b = q;

	return (int)*a - (int)*b;
}


/**
 * 排序判断两个字符串是否为anagrams
 *
 * T = O(nlogn)
 *
 */
void isAnagramsWithSort(char *str1, char *str2)
{
	qsort(str1, strlen(str1), sizeof(str1[0]), compare);
	qsort(str2, strlen(str2), sizeof(str2[0]), compare);

	if (strcmp(str1, str2) == 0) {
		printf("anagrams yes !\n");
	} else {
		printf("anagrams no !\n");
	}
}

/**
 * hash思想判断两个字符串是否为anagrams
 *
 * T = O(n)
 *
 */
void isAnagramsWithHash(char *str1, char *str2)
{
	int i, flag, key, hash[256];

	memset(hash, 0, sizeof(hash));

	while (*str1 != '\0') {
		key = (int)*str1;
		hash[key] += 1;
		str1 ++;
	}

	while (*str2 != '\0') {
		key = (int)*str2;
		hash[key] -= 1;
		str2 ++;
	}

	for (i = 0, flag = 1; i < 256; i ++) {
		if (hash[i] != 0) {
			flag = 0;
			break;
		}
	}

	if (flag) {
		printf("anagrams yes !\n");
	} else {
		printf("anagrams no !\n");
	}
}


int main(void)
{
	char str1[200], str2[200];

	while (scanf("%s %s", str1, str2) != EOF) {
		isAnagramsWithSort(str1, str2);
		isAnagramsWithHash(str1, str2);
	}

	return 0;
}
