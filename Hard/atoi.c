#include <stdio.h>
#include <stdlib.h>

#define INT_MAX  2147483647
#define INT_MIN  -2147483648

int myatoi(const char *s)
{
	int val, flag;
	unsigned int cutlim, cutoff;
	
	// 判断是否为空
	if (s == NULL)	return 0;

	// 去除空格和制表符
	while (*s == ' ' || *s == '\t')
		s ++;

	// 判断符号
	if (*s == '-') {
		flag = 1;
		s ++;
	} else {
		flag = 0;
		if (*s == '+')
			s ++;
	}

	// 注意越界
	cutoff = flag ? (unsigned int) INT_MAX + 1 : INT_MAX;
	cutlim = cutoff % 10;
	cutoff /= 10;

	for (val = 0; *s >= '0' && *s <= '9'; s ++) {
		if (val > cutoff || (val == cutoff && *s - '0' > cutlim)) {
			return flag ? INT_MIN : INT_MAX;
		}
		val = 10 * val + *s - '0';
	}

	if (flag)
		return val * -1;
	else
		return val;
}

int main(void)
{
	char str[100];
	int num;

	while (scanf("%s", str) != EOF) {
		num = myatoi(str);
		printf("%d\n", num);
	}

	return 0;
}
