/**
 * Design an algorithm and write code to remove the duplicate characters in a string
 * without using any additional buffer(ps:replace character with '\0')
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 就地去除字符串的重复数据，两个for循环
 *
 * T = O(n * n)
 *
 */
void removeDuplicate(char *str, int len)
{
	int i, j, index;

	index = 0;
	for (i = 0; i < len; i ++) {
		if (str[i] != '\0') {
			str[index ++] = str[i];
			for (j = i + 1; j < len; j ++) {
				if (str[j] == str[i])
					str[j] = '\0';
			}
		}
	}
	
	str[index] = '\0';
}

/**
 * 利用hash的直接寻址法去除字符串中的重复字符
 *
 * T = O(n)
 *
 */
void removeDuplicateHash(char *str, int len)
{
	int i, key, index, hash[256];

	memset(hash, 0, sizeof(hash));

	index = 0;
	for (i = 0; i < len; i ++) {
		key = (int)str[i];
		if (hash[key] == 0) {
			str[index ++] = str[i];
			hash[key] = 1;
		} else {
			continue;
		}
	}
	str[index] = '\0';
}


int main(void)
{
	int len;
	char str[200];

	while (gets(str)) {
		len = strlen(str);

		// removeDuplicate(str, len);

		removeDuplicateHash(str, len);

		puts(str);
	}

	return 0;
}
