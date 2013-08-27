/**
 * Given a sorted array of strings which is interspersed with empty strings, write a
 * method to find the location of a given string.
 *
 * 用“#”代替empty strings, 程序如何接收空字符串呢
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string {
	char val[10];
} string;

/**
 * 二分查找字符串
 *
 * T = O(logn)
 *
 */
int findString(string *s, int begin, int end, char *key)
{
	int mid, tmp;

	while (begin <= end) {
		mid = (begin + end) / 2;
		
		tmp = mid;

		while (strcmp(s[tmp].val, "#") == 0 && tmp <= end)
			tmp ++;

		if (tmp > end) {
			end = mid - 1;
		} else {
			if (strcmp(s[tmp].val, key) == 0) {
				return tmp;
			} else if (strcmp(s[tmp].val, key) > 0) {
				end = mid - 1;
			} else {
				begin = tmp + 1;
			}
		}
	}

	return -1;
}

int main(void)
{
	int i, n, loc;
	char key[10];
	string s[100];

	
	for (i = 0, scanf("%d", &n); i < n; i ++) {
		getchar();
		scanf("%s", s[i].val);
	}

	printf("输入字符串结束!\n");	
	/* 打印测试
	for (i = 0; i < n; i ++) {
		printf("%s\n", s[i].val);
	}
	*/

	while (scanf("%s", key) != EOF) {

		loc = findString(s, 0, n - 1, key);

		printf("%d\n", loc);
	}

	return 0;
}
