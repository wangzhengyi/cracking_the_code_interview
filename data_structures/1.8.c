/**
 * Assume you have a method isSubstring which checks if one word is a substring of
 * another.Given two strings, s1 and s2, write code to check if s2 is a rotation of 
 * s1 using only one call to isSubstring
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 朴素字符串匹配，判断s2是否为s1子串
 *
 * T = O(n * n)
 *
 */
int isSubstringNaive(char *s1, char *s2)
{
	int i, j, k, flag, len1, len2;

	len1 = strlen(s1);
	len2 = strlen(s2);

	for (i = 0, flag = 0; i <= len1 - len2; i ++) {
		for (j = 0, k = i; j < len2 && k < len1; j ++, k ++) {
			if (*(s2 + j) == *(s1 + k))
				continue;
			else
				break;
		}
		if (j == len2) {
			flag = 1;
			break;
		}
	}

	return flag;
}	

/**
 * 判断s2是否是s1的rotation
 *
 * T = O(n * n)
 *
 */
int isRotation(char *s1, char *s2)
{
	int flag, len = strlen(s1);
	char *s3 = (char *)malloc(2 * len);

	s3 = strcat(s1, s1);

	flag = isSubstringNaive(s3, s2);

	return flag;
}


int main(void)
{
	char *s1, *s2;
	s1 = (char *)malloc(200);
	s2 = (char *)malloc(200);


	while (scanf("%s %s", s1, s2) != EOF) {
		if (isRotation(s1, s2)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	free(s1);
	free(s2);

	return 0;
}
