/**
 * Write a method to shuffle a deck of cards.It must be a perfect shuffle-in other words,
 * each N! permutations of the deck has to be equally likely. Assume that you are given
 * a random number generator which is prefect.
 */

#include <stdio.h>
#include <stdlib.h>

#define N 52

int cards[N];

/**
 * 预处理数组
 */
void preProcess()
{
	int i;
	for (i = 0; i < N; i ++)
		cards[i] = i + 1;
}

/**
 * 洗牌算法
 *
 */
void randomShuffle()
{
	int i, j, tmp;

	for (i = 0; i < N; i ++) {
		j = rand() % (N - i) + i;
		tmp = cards[i];
		cards[i] = cards[j];
		cards[j] = tmp;
	}
}

int main(void)
{
	preProcess();

	int i, j, n;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i ++) {
			randomShuffle();
			for (j = 0; j < N; j ++)
				printf("%d ", cards[j]);
			printf("\n");
		}
	}

	return 0;
}
