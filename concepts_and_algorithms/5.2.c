/**
 * Given a (decimal -e.g.3.72) number that is passed in as a string, print the binary
 * representation. If the number can not be represented accurately in binary, print "ERROR"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 获取小数点的位置
 * 
 * T = O(n)
 */
int findPosition(char *str)
{
	int loc = 0;

	while (*(str + loc) != '.') {
		loc ++;
	}

	return loc;
}


int main(void)
{
	char str[100], *intstr, *decimalstr;
	int i, intpart, pos, len, leni, lenf, flag;
	double decimalpart;

	while (scanf("%s", str) != EOF) {
		// 标记字段
		flag = 1;

		// 字符串转整数
		pos = findPosition(str);
		len = strlen(str);
			
		intstr = (char *)malloc(pos + 1);
		decimalstr = (char *)malloc(len - pos + 2);
		decimalstr[0] = '0';

		intstr = strncpy(intstr, str, pos);

		decimalstr = strcat(decimalstr, str + pos);

		intpart = atoi(intstr);
		decimalpart = atof(decimalstr);

		// 整数部分转二进制
		leni = 0;
		while (intpart) {
			if (intpart & 1) {	
				intstr[leni] = '1';
			} else {
				intstr[leni] = '0';
			}

			leni ++;
			intpart >>= 1;
		}

		// 小数部分转二进制,最长支持32bit
		lenf = 0;
		while (decimalpart > 0) {
			if (lenf > 32) {
				printf("ERROR\n");
				flag = 1;
				break;
			}
			
			decimalpart *= 2;

			if (decimalpart >= 1) {
				decimalstr[lenf] = '1';
				decimalpart -= 1;
			} else {
				decimalstr[lenf] = '0';
			}
			lenf ++;
		}

		if (flag) {
			// 打印整数部分
			for (i = leni - 1; i >= 0; i --) {
				printf("%c", intstr[i]);
			}
			printf(".");
			for (i = 0; i < lenf; i ++) {
				printf("%c", decimalstr[i]);
			}
			printf("\n");
		}

	}

	return 0;
}
