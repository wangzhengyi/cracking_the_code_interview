#include <stdio.h>
#include <stdlib.h>

#define N 15

/**
 * 异或交换两个数
 */
void swap(char *a, char *b)
{
	if (*a != *b) {
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}
}

/**
 * 编程实现windows平台整型转字符串代码
 */
void itoa(int value, char *str)
{
	int i, j, k;

	// 处理负数
	if (value < 0) {
		str[0] = '-';
		value *= -1;
	} else {
		str[0] = '+';
	}

	for (i = 1; value; i ++, value /= 10) {
		str[i] = value % 10 + '0';
	}

	// 字符串逆序
	for (j = 1, k = i - 1; j <= k; j ++, k --) {
		swap(str + j, str + k);
	}

	// 补字符串结束标识
	str[i] = '\0';

	// 正数前移一位
	if (str[0] != '-') {
		for (j = 1; j <= i; j ++) {
			str[j - 1] = str[j];
		}
	}
}

int main(void)
{
	int value;

	char str[N];

	while (scanf("%d", &value) != EOF) {
		itoa(value, str);
		printf("%s\n", str);
	}

	return 0;
}

