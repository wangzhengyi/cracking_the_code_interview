/**
 * Implement an algorithm to find the nth to last element of a singly linked list
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
	link *pre, *cur, *new;
	cur = *head;
	pre = NULL;

	while (cur != NULL) {
		pre = cur;
		cur = cur->next;
	}

	new = (link *)malloc(sizeof(link));
	new->value = data;

	if (pre == NULL)
		*head = new;
	else
		pre->next = new;
}

/**
 * 打印单链表
 *
 * T = O(n)
 */
void printLinklist(link *head)
{
	while (head->next != NULL) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("%d\n", head->value);
}

/**
 * 寻找单链表倒数第m个节点
 *
 * T = O(n)
 *
 */
void findMthToLast(link *head, int m)
{
	if (head == NULL) return;
	link *s1, *s2;
	int i;
	// s1指向表头,s2指向从s1开始后m个元素的位置，然后s1与s2同时后移，到s2为NULL时停止，s1为mth to last
	s1 = s2 = head;

	for (i = 0; i < m; i ++) {
		s2 = s2->next;
	}

	while (s2 != NULL) {
		s1 = s1->next;
		s2 = s2->next;
	}

	printf("%d\n", s1->value);
}

int main(void)
{
	int i, n, m, data;
	link *head;

	while (scanf("%d", &n) != EOF) {
		for (i = 0, head = NULL; i < n; i ++) {
			scanf("%d", &data);
			createLinklist(&head, data);			
		}	

		// 接收mth to last
		scanf("%d", &m);
		
		if (m > n) {
			printf("输入数据有误！\n");
		} else {
			printLinklist(head);
			findMthToLast(head, m);
		}
	}

	return 0;
}



