/**
 * Write a program to sort a stack in ascending order
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int top;
	int seq[1000];
} stack;

/**
 * 入栈操作
 *
 * T = O(1)
 *
 */
void pushStack(stack *s, int data)
{
	s->seq[s->top ++] = data;
}

/**
 * 两个栈模拟插入排序
 *
 * T = O(n)
 *
 */
stack* sortStack(stack *s)
{
	int indata;
	stack *t = (stack *)malloc(sizeof(stack));
	t->top = 0;
	
	while (s->top > 0) {
		if (t->top == 0) {
			t->seq[t->top ++] = s->seq[-- s->top];
		} else {
			indata = s->seq[-- s->top];
			if (t->seq[t->top - 1] >= indata) {
				t->seq[t->top ++] = indata;
			} else {
				while (t->top > 0 && t->seq[t->top - 1] < indata) {
					s->seq[s->top ++] = t->seq[-- t->top];
				}
				t->seq[t->top ++] = indata;
			}
		}
	}

	return t;
}

int main(void)
{
	int i, n, data;
	stack *s, *t;

	while (scanf("%d", &n) != EOF) {
		s = (stack *)malloc(sizeof(stack));
		s->top = 0;

		for (i = 0; i < n; i ++) {
			scanf("%d", &data);
			pushStack(s, data);
		}

		t = sortStack(s);

		while (t->top > 0) {
			printf("%d ", t->seq[-- t->top]);
		}
		printf("\n");
		free(s);
		free(t);
	}

	return 0;
}


