/**
 * Implement a MyQueue class which implements a queue using two stacks
 * 九度oj:http://ac.jobdu.com/problem.php?pid=1512
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	int top;
	int seq[10000];
} stack;

/**
 * 入队操作
 *
 * T = O(1)
 *
 */
void pushQueue(stack *s1, int data)
{
	s1->seq[s1->top ++] = data;
}

/**
 * 出队操作
 *
 * T = O(n)
 *
 */
void popQueue(stack *s1, stack *s2)
{
	if (s2->top > 0) {
		printf("%d\n", s2->seq[-- s2->top]);
	} else {
		while (s1->top > 0) {
			s2->seq[s2->top ++] = s1->seq[-- s1->top];
		}

		if (s2->top > 0) 
			printf("%d\n", s2->seq[-- s2->top]);
		else
			printf("-1\n");
	}

}


int main(void)
{
	int data, n;
	stack *s1, *s2;
	char str[5];

	while (scanf("%d", &n) != EOF) {
		// 初始化  
		s1 = (stack *)malloc(sizeof(stack));
		s2 = (stack *)malloc(sizeof(stack));
		s1->top = s2->top = 0;

		while (n --) {
			scanf("%s", str);

			if (strcmp(str, "PUSH") == 0) {	// 入队列
				scanf("%d", &data);
				pushQueue(s1, data);
			} else {	// 出队列
				popQueue(s1, s2);
			}
		}

		free(s1);
		free(s2);
	}

	return 0;
}
