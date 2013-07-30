/**
 * 类似于九度oj:http://ac.jobdu.com/problem.php?pid=1522
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct sdata {
	int val, min;
} sdata;

typedef struct stack {
	int top;
	sdata values[10000];
} stack;

/**
 * 栈顶压入元素
 *
 * T = O(1)
 *
 */
void pushStack(stack *s, int data)
{
	s->values[s->top].val = data;
	if (s->top == 0) {
		s->values[s->top].min = data;
	} else {
		s->values[s->top].min = data < s->values[s->top - 1].min ? data : s->values[s->top - 1].min;
	}
	// 打印当前最小值
	printf("%d\n", s->values[s->top].min);
	s->top ++;
}

/**
 * 栈顶弹出元素
 *
 * T = O(1)
 *
 */
void popStack(stack *s)
{
	if (s->top > 0)
		s->top -= 1;
	if (s->top <= 0) {
		printf("NULL\n");
		return;
	} else {
		printf("%d\n", s->values[s->top - 1].min);
	}
}


int main(void)
{
	int i, n, data;
	stack *s;
	char ci[2];

	while (scanf("%d", &n) != EOF) {
		s = (stack *)malloc(sizeof(stack));
		s->top = 0;
		
		getchar();
		for (i = 0; i < n; i ++) {
			scanf("%s", ci);
			switch (ci[0]) {
				case 's' :
					scanf("%d", &data);
					pushStack(s, data);
					break;
				case 'o' :
					popStack(s);
					break;
			}
		}

		free(s);
	}

	return 0;
}
