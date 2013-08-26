/**
 * Write a method to sort an array of strings so that all the anagrams are next to each
 * other
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string {
	char val[10];
	char backup[10];
} string;

/**
 * 字符串字典排序
 */
int compare_str(const void *p, const void *q)
{
	const char *a = p;
	const char *b = q;

	return *a - *b;
}

/**
 * 字符串变位词相邻同时按字典排序
 */
int compare_struct(const void *p, const void *q)
{
	const string *a = p;
	const string *b = q;

	qsort(a->val, strlen(a->val), sizeof(a->val[0]), compare_str);
	qsort(b->val, strlen(b->val), sizeof(b->val[0]), compare_str);

	return strcmp(a->val, b->val);
}

int main(void)
{
	int i, n;
	string *s;

	while (scanf("%d", &n) != EOF) {
		s = (string *)malloc(sizeof(string) * n);

		for (i = 0; i < n; i ++) {
			scanf("%s", s[i].val);
			strcpy(s[i].backup, s[i].val);
		}

		qsort(s, n, sizeof(s[0]), compare_struct);

		for (i = 0; i < n; i ++) {
			printf("%s\n", s[i].backup);
		}

		free(s);
	}

	return 0;
}
