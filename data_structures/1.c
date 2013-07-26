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
 *
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

/**
 * bitmap判断str字符串每个字符是否唯一
 *
 * T = O(n)
 *
 */
int isUniqueBitmap(char *str, int len)
{
	int index_loc, bit_loc, num, flag, arr[8];
	char *p = str;

	memset(arr, 0, sizeof(arr));

	flag = 1;
	while (*p != '\0') {
		num = (int)*p;
		index_loc = num / 32;
		bit_loc = num % 32;
		
		if (arr[index_loc] & (1 << bit_loc)) {
			flag = 0;
			break;
		} else {
			arr[index_loc] |= 1 << bit_loc;
			p ++;
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


		flag = isUniqueBitmap(str, len);
		if (flag)
			printf("unique!\n");
		else
			printf("repeat!\n");
		
		memset(str, '\0', sizeof(str));
	}

	return 0;
}
