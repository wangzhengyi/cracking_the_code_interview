/**
 * A circus is designing a tower routine consisting of people standing atop one another's
 * shoulders. For practical and aesthetic reasons, each person must be both shorter and
 * lighter than the person below him or her. Given the heights and weights of each person
 * int the circus, write a method to compute the largest possible number of people in such
 * a tower.
 * EXAMPLE:
 * Input(ht,wt):(65,100) (70,150) (56,90) (75,190) (60,95) (68,110)
 * Output:The longest tower is length 6 and includes from top to bottom: (56,90) (60,95) (65,100)
 * (68,110) (70,150) (75,190)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people {
	unsigned int ht, wt;
} people;

int hloc, wloc;

/**
 * 按照高度从高到低排序
 */
int cmp_height(const void *p, const void *q)
{
	const people *a = p;
	const people *b = q;

	return b->ht - a->ht;
}

/**
 * 按照体重从高到低排序
 */
int cmp_weight(const void *p, const void *q)
{
	const people *a = p;
	const people *b = q;

	return b->wt - a->wt;
}

/**
 * 动态规划求最长递增子序列
 * type = 1 按身高
 * type = 2 按体重
 *
 * T = O(n^2)
 *
 */
int lds(people *p, int n, int type)
{
	int i, j, max, *dp;

	dp = (int *)malloc(sizeof(int) * n);
	dp[0] = 1;
	max = 1;

	for (i = 1; i < n; i ++) {
		for (j = 0, dp[i] = 1; j < i; j ++) {
			switch (type) {
				case 1 :
					// 按身高
					if (p[j].ht > p[i].ht) {
						dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
					}
					break;
				case 2:
					// 按体重
					if (p[j].wt > p[i].wt) {
						dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
					}
					break;
			}
		}

		if (max < dp[i]) {
			max = dp[i];
			switch (type) {
				case 1 :
					hloc = i;
					break;
				case 2 :
					wloc = i;
					break;
			}
		}
	}

	return max;
}

int main(void)
{
	int i, n, hmax, wmax, max, flag;
	people *p;

	while (scanf("%d", &n) != EOF) {
		p = (people *)malloc(sizeof(people) * n);

		for (i = 0; i < n; i ++) {
			scanf("%d %d", &p[i].ht, &p[i].wt);
		}

		// 按身高排序,按体重动态规划
		qsort(p, n, sizeof(p[0]), cmp_height);
		wmax = lds(p, n, 2);

		// 按体重排序，按身高动态规划
		qsort(p, n, sizeof(p[0]), cmp_weight);
		hmax = lds(p, n, 1);

		if (hmax > wmax) {
			max = hmax;
			flag = 1;
		} else {
			max = wmax;
			flag = 2;
		}

		printf("The longest tower is length %d and includes from top to bottom: \n", max);
		switch (flag) {
			case 1 :
				qsort(p, n, sizeof(p[0]), cmp_height);
				for (i = 0; i < hloc; i ++) {
					if (p[i].ht > p[hloc].ht) {
						printf("(%d, %d) ", p[i].ht, p[i].wt);
					}
				}
				printf("(%d, %d)\n", p[hloc].ht, p[hloc].wt);
				break;
			case 2 :
				qsort(p, n, sizeof(p[0]), cmp_weight);
				for (i = 0; i < wloc; i ++) {
					if (p[i].wt > p[wloc].wt)
						printf("(%d, %d) ", p[i].ht, p[i].wt);
				}
				printf("(%d, %d)\n", p[wloc].ht, p[wloc].wt);
				break;
		}

		free(p);
	}

	return 0;
}
