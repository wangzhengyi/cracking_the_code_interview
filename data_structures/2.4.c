/**
 * You have two numbers represented by a linked list, 
 * where each node contains a single digit. The digits
 * are sorted in reverse order, such that the 1's digit
 * is at the head of the list.Write a function that adds
 * the two numbers and returns the sum as a linked list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct link {
	struct link *next;
	int value;
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

	if (pre == NULL)
		*head = new;
	else
		pre->next = new;
}

/**
 * 打印单链表
 *
 * T = O(n)
 *
 */
void printLinklist(link *head)
{
	while (head->next != NULL) {
		printf("%d", head->value);
		head = head->next;
	}
	printf("%d\n", head->value);
}

/**
 * 两个单链表模拟加法运算
 *
 * T = O(n)
 *
 */
link* addLink(link *head1, link *head2)
{
	if (head1 == NULL)	return head2;
	if (head2 == NULL)	return head1;

	link *head3, *new, *pre;
	int c, index, data;

	c = 0;
	index = 0;
	while (head1 && head2) {
		data = head1->value + head2->value + c;
		c = data / 10;
		data = data % 10;
		if (index == 0) {
			head3 = (link *)malloc(sizeof(link));
			head3->value = data;
			head3->next = NULL;
			pre = head3;
			index ++;
		} else {
			new = (link *)malloc(sizeof(link));
			new->value = data;
			new->next = NULL;
			pre->next = new;
			pre = new;
		}
		head1 = head1->next;
		head2 = head2->next;
	}

	while (head1) {
		data = head1->value + c;
		c = data / 10;
		data %= 10;
		new = (link *)malloc(sizeof(link));
		new->value = data;
		new->next = NULL;
		pre->next = new;
		pre = new;
		head1 = head1->next;
	}
	
	while (head2) {
		data = head2->value + c;
		c = data / 10;
		data %= 10;
		new = (link *)malloc(sizeof(link));
		new->value = data;
		new->next = NULL;
		pre->next = new;
		pre = new;
		head2 = head2->next;
	}

	// 链表一样长,并且有进位
	if (c) {
		new = (link *)malloc(sizeof(link));
		new->value = c;
		new->next = NULL;
		pre->next = new;
	}

	return head3;
}

int main(void)
{
	int i, num1, num2, data;
	link *head1, *head2, *head3;

	while (scanf("%d %d", &num1, &num2) != EOF) {
		// 接收第一个数
		for (i = 0, head1 = NULL; i < num1; i ++) {
			scanf("%d", &data);
			createLinklist(&head1, data);
		}

		// 接受第二个数
		for (i = 0, head2 = NULL; i < num2; i ++) {
			scanf("%d", &data);
			createLinklist(&head2, data);
		}

		// 链表加法
		head3 = addLink(head1, head2);

		printLinklist(head1);
		printLinklist(head2);
		printLinklist(head3);
	}

	return 0;
}
