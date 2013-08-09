/**
 * Imagine a literal stack of plates.If the stack gets to high,it might topple.
 * Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
 * Implement a function popAt(in index) which performs a pop operation on a specific sub-stack
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACKSIZE 10
#define STACKNUM 4

typedef struct stack {
	int top;
	int data[STACKSIZE];
} stack;


int cur;
stack* setStacks[STACKNUM];

/**
 * 初始化子栈
 *
 * T = O(1)
 *
 */
stack* initStack()
{
	stack *s = (stack *)malloc(sizeof(stack));
	s->top = 0;
	return s;
}

/**
 * 栈push操作
 *
 * T = O(1)
 *
 */
void push(int data)
{
	if (setStacks[cur]->top == STACKSIZE) {	// 超过子栈限制,启用新的子栈
		setStacks[++ cur] = initStack();
		setStacks[cur]->data[setStacks[cur]->top ++] = data;
	} else {
		setStacks[cur]->data[setStacks[cur]->top ++] = data;
	}
}

/**
 * 栈pop操作
 *
 * T = O(1)
 *
 */
int pop()
{
	// 判空操作
	while (setStacks[cur]->top == 0 && cur != -1)
		cur --;

	if (cur == -1)
		return -1;
	else
		return setStacks[cur]->data[-- setStacks[cur]->top];
}

/**
 * 获取栈最大值
 *
 * T = O(1)
 */
int top()
{
	// 判空操作
	while (setStacks[cur]->top == 0 && cur != -1)
		cur --;

	if (cur == -1)
		return -1;	
	else
		return setStacks[cur]->data[setStacks[cur]->top - 1];
}

/**
 * 指定子栈首元素出栈
 *
 * T = O(n)
 *
 */
int popAt(index)
{
	if (index > cur) return -1;

	while (setStacks[index]->top == 0)
		index --;
	
	if (index == -1)
		return -1;
	else
		return setStacks[index]->data[-- setStacks[index]->top];
}

int main(void)
{
	int i;
	cur = 0;
	setStacks[0] = initStack();

	for (i = 0; i < 30; i ++) {
		push(i);
	}

	int topdata;

	topdata = top();
	printf("%d\n", topdata);

	for (i = 0; i < 3; i ++) {
		pop();
	}

	topdata = popAt(0);
	printf("%d\n", topdata);

	topdata = popAt(1);
	printf("%d\n", topdata);

	topdata = popAt(2);
	printf("%d\n", topdata);

	topdata = top();
	printf("%d\n", topdata);

	return 0;
}


