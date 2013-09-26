/**
 * n选m组合算法
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 递归法解决组合问题
 */
void combine(int *arr, int n, int m, int *tmp, const int M)
{
	int i, j;

	for (i = n; i >= m; i --) {
		tmp[m] = i;
		if (m == 0) {	// 选出m个数
			for (j = 0; j < M; j ++) {
				printf("%d ", arr[tmp[j]]);
			}
			printf("\n");
		} else {
			combine(arr, i - 1, m - 1, tmp, M);
		}
 	}
}

void init(int *tmp, int m)
{
	int i;

	for (i = 0; i < m; i ++) {
		tmp[i] = i;
	}
}

void printTmp(int *tmp, int m)
{
	int i;

	for (i = 0; i < m; i ++) {
		printf("%d ", tmp[i] + 1);
	}
	printf("\n");
}

/**
 * 非递归解决组合问题
 */
void bitCombine(int *arr, int n, int m, int *tmp)
{
	init(tmp, m);

	while (1) {
		tmp[m - 1] = tmp[m - 2] + 1;

		while (tmp[m - 1] < n) {
			printTmp(tmp, m);
			tmp[m - 1] ++;			
		}

		int t, cnt;
		t = m - 2;
		cnt = 1;

		while (t >= 0 && tmp[t] + cnt == n - 1) {
			cnt ++;
			t --;
		}

		if (t < 0)	return;
		tmp[t] ++;
		t += 1;

		while (t <= m - 2) {
			tmp[t] = tmp[t - 1] + 1;
			t ++;
		}
	}
}



int main(void)
{
	int i, n, m, *arr, *tmp;

	while (scanf("%d %d", &n, &m) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		tmp = (int *)malloc(sizeof(int) * m);

		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);

		// combine(arr, ddn - 1, m - 1, tmp, m);
		
		bitCombine(arr, n, m, tmp);
	}

	return 0;
}
