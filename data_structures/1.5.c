/**
 * write a method to replace all spaces in a string with '%20'
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 简单的空格替换，注意新串空间的申请，节省空间newlen = len + 2 × spacenum
 *
 * T = O(n)
 */
char* replaceSpace(char *str)
{
	if (str == NULL) return NULL;
	
	int i, j, len, snum, newlen;
	if ((len = strlen(str)) == 0) return NULL;

	for (i = 0, snum = 0; i < len; i ++) {
		if (str[i] == ' ')
			snum ++;
	}

	newlen = len + 2 * snum;
	char *newstr;
	newstr = (char *)malloc(newlen);

	for (i = j = 0; i < len; i ++) {
		if (str[i] != ' ') {
			newstr[j] = str[i];
			j ++;
		} else {
			newstr[j] = '%';
			newstr[j + 1] = '2';
			newstr[j + 2] = '0';
			j += 3;
		}
	}

	return newstr;
}


int main(void)
{
	char str[200], *newstr;

	while (gets(str)) {
		newstr = replaceSpace(str);

		puts(newstr);

		free(newstr);
	}
	
	return 0;
}

