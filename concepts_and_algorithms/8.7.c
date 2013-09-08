/**
 * Given an infinite number of quarters(25 cents), dimes(10 cents), nickels(5 cents) amd
 * pennies(1 cent), write code to calculate the number of ways of representing n cents.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int data[1000];
	int top;
} stack;
 
stack *s;

int money[4] = {25, 10, 5, 1};

void dfs(int t, int target)
{
	int i;

	if (t == target) {
		for (i = 0; i < s->top; i ++)
			printf("%d ", s->data[i]);
		printf("\n");
	} else {
		int new;
		for (i = 0; i < 4; i ++) {
			new = t + money[i];
			if (new <= target) {
				s->data[s->top ++] = money[i];
				dfs(new, target);
				s->data[-- s->top];
			}
		}
	}
}

int main(void)
{
	int n;
	s = (stack *)malloc(sizeof(stack));

	while (scanf("%d", &n) != EOF) {
		s->top = 0;

		dfs(0, n);

	}

	free(s);
	return 0;
}
