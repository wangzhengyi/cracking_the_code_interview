/**
 * In the classic problem of the Towers of Hanoi, you have 3 rods and  N disks of different
 * sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending
 * order of size from top to bottom. You have the following constraints:
 * (A) Only one disk can be moved at a time
 * (B) A disk is slid off the top of one rod onto the next rod
 * (C) A disk can only be placed on top of a larger disk
 * Write a program to move the disks from the first rod to the last using stacks
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 递归代码
 *
 * T = O(2^n - 1) 可推导证明
 *
 * ps: 汉诺塔经典递归题目,用神马栈啊
 *
 *
 * 递归精髓: 先定义一个函数,不要去管那些实现细节,关键是明确函数功能
 */
void hanoi(char src, char mid, char dst, int n)
{
	if (n == 1) {
		printf("Move disk %d from %c to %c\n", n, src, dst);
	} else {
		hanoi(src, dst, mid, n - 1);
		printf("Move disk %d from %c to %c\n", n, src, dst);
		hanoi(mid, src, dst, n - 1);
	}
}


int main(void)
{
	int n;

	while (scanf("%d", &n) != EOF) {
		hanoi('A', 'B', 'C', n);
	}

	return 0;
}
