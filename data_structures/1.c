/**
 * Implement an algorithm to determine if a string has all unique characters
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * 判断str字符串每个字符是否唯一
 *
 * T = O(n)
 */
int isUnique(char *str, int len)
{
	int i, key, flag, hash[256];
	memset(hash, 0, sizeof(hash));

	for (i = 0, flag = 1; i < len; i ++) {
		key = (int)str[i];
		hash[key] += 1;
		if (hash[key] > 1) {
			flag = 0;
			break;
		}
	}

	return flag;
}


int main()
{
	char str[1000];
	int len, flag;
	
	while (gets(str)) {
		len = strlen(str);
		flag = isUnique(str, len);

		if (flag)
			printf("unique!\n");
		else
			printf("repeat!\n");
	}

	return 0;
}
