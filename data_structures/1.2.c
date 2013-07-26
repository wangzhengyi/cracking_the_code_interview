/**
 * write code to reverse a C-style string
 */

#include <stdio.h>
#include <string.h>

/**
 * 指针首尾交换翻转字符串
 *
 * T = O(n)
 *
 */
void reverse(char *str, int len)
{
	char tmp, *p, *q;
	
	p = str;
	q = str + len - 1;

	while (p <= q) {
		tmp = *p;
		*p = *q;
		*q = tmp;

		p ++;
		q --;
	}
}

int main(void)
{
	char str[100];
	int len;

	while (gets(str)) {
		len = strlen(str);
		reverse(str, len);

		puts(str);
	}

	return 0;
}
