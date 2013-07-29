/**
 * Given a circular linked list, implement an algorithm which returns
 * node at the begining of the loop
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct link {
	int value;
	struct link *next;
} link;

/**
 * 创建单链表
 *
 * T = O(n)
 *
 */
void createLinklist(link **head, int data)
{	
	link *cur, *pre, *new;

	cur = *head;
	pre = NULL;

	while (cur != NULL) {
		pre = cur;
		cur = cur->next;
	}

	new = (link *)malloc(sizeof(link));
	new->value = data;
	new->next = cur;

	if (pre == NULL) {
		*head = new;
	} else {
		pre->next = new;
	}
}

/**
 * 从m个节点开始构建循环链表
 *
 * T = O(n)
 *
 */
void initLoopList(link *head, int m)
{
	link *cur, *pre, *target;
	cur = head;

	while (-- m && cur != NULL) {
		cur = cur->next;
	}
	target = cur;

	while (cur != NULL) {
		pre = cur;
		cur = cur->next;
	}
	pre->next = target;
}

/**
 * 寻找循环开始点的value
 *
 * T = O(n)
 *
 */
void loopStart(link *head)
{
	link *fast, *slow, *p, *q;
	int i, len;

	for (slow = head, fast = slow->next->next; fast != slow;) {
		slow = slow->next;
		fast = fast->next->next;
	}

	for (len = 1, slow = slow->next; slow != fast; slow = slow->next) {
		len += 1;
	}

	p = q = head;
	for (i = 0; i < len; i ++) {
		q = q->next;
	}

	while (p != q) {
		p = p->next;
		q = q->next;
	}	
	printf("%d\n", q->value);
}

int main(void)
{
	link *head;
	int i, n, m, data;

	while (scanf("%d", &n) != EOF) {
		// 创建单链表
		for (i = 0, head = NULL; i < n; i ++) {
			scanf("%d", &data);
			createLinklist(&head, data);
		}

		// 第m个点开始循环
		scanf("%d", &m);
		if (m > n) continue;
		initLoopList(head, m);
		
		// 查找循环起始节点(只提供头节点)
		loopStart(head);
	}

	return 0;
}
