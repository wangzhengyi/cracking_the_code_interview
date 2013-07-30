/**
 * Describe how you could use a single array to implement three stacks
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ptop[3];
int cur;

typedef struct node {
	int val, preidx;
} node;

/**
 * 第stackNum个栈执行入栈操作
 *
 * T = O(1)
 *
 */
void pushStack(node *buf, int data, int stackNum)
{
	buf[cur].val = data;
	buf[cur].preidx = ptop[stackNum];
	ptop[stackNum] = cur;
	cur ++;
}

/**
 * 第stackNum个栈执行出栈操作
 *
 * T = O(1)
 *
 */
void popStack(node *buf, int stackNum)
{
	if (ptop[stackNum] == -1) return;

	int loc = buf[ptop[stackNum]].preidx;

	ptop[stackNum] = loc;
}

/**
 * 获取第stackNum个栈的栈顶元素
 *
 * T = O(1)
 *
 */
int topStack(node *buf, int stackNum)
{
	if (ptop[stackNum] != -1) {
		return buf[ptop[stackNum]].val;
	}

	return -1;
}

/**
 * 判断第stackNum个栈是否为空栈
 *
 * T = O(1)
 *
 */
int emptyStack(node *buf, int stackNum)
{
	if (ptop[stackNum] == -1)
		return 1;
	else
		return 0;
}

int main(void)
{
	node *buf;
	int i, data, totalsize;

	while (scanf("%d", &totalsize)) {
		// 初始化
		buf = (node *)malloc(sizeof(node) * totalsize);
		ptop[0] = ptop[1] = ptop[2] = -1;
		cur = 0;

		// 测试用例
		for (i = 0; i < 10; i ++) {
			pushStack(buf, i, 0);
		}

		for  (i = 10; i < 20; i ++) {
			pushStack(buf, i, 1);
		}

		for (i = 20; i < 30; i ++) {
			pushStack(buf, i, 2);
		}

		for (i = 0; i < 3; i ++) {
			data = topStack(buf, i);
			printf("第%d个栈顶元素为: %d\n", i, data);
			popStack(buf, i);
		}

		free(buf);
	}	

	return 0;
}
