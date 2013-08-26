/**
 * You are given two sorted arrays, A and B, and A has a large enough buffer at the end
 * to hold B. Write a method to merge B into A in sorted order.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int *a, int *b, int size_a, int size_b)
{
	int i, j, k, len;

	len = size_b + size_a - 1;

	for (i = size_a - 1, j = size_b - 1, k = len; i >= 0 && j >= 0; k --) {
		if (a[i] >= b[j])
			a[k] = a[i --];
		else
			a[k] = b[j --];
	}	

	while (j >= 0)	a[k --] = b[j --];
}

int main(void)
{
	int a[15] = {1, 3, 7, 8, 9};
	int b[] = {2, 4, 5, 6, 10};
	int i;

	merge(a, b, 5, 5);

	for (i = 0; i < 10; i ++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
