/**
 * Write code to remove duplicates from an unsorted linked list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
	int value;
	struct link *next;
} link;

/**
 * 创建无序单链表
 *
 * T = O(n)
 *
 */
void createSingleList(link **head, int data)
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
 * 打印链表
 *
 * T = O(n)
 */
void printLinklist(link *head)
{
	link *cur = head;

	while (cur->next != NULL) {
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("%d\n", cur->value);
}

/**
 * 删除链表中重复的元素
 *
 * T = O(n * n)
 *
 */
void removeDuplicate(link *head)
{
	if (head == NULL) return;

	link *cur, *pre, *post;

	cur = head;

	while (cur != NULL) {
		post = cur->next;
		pre = cur;
		while (post != NULL) {
			if (post->value != cur->value) {
				pre = post;
				post = post->next;
			} else { // 删除重复节点
				pre->next = post->next;
				free(post);
				post = pre->next;
			}
		}
		cur = cur->next;
	}
}


int main(void)
{
	int i, n, data;
	link *head;

	while (scanf("%d", &n) != EOF) {
		for (i = 0, head = NULL; i < n; i ++) {
			scanf("%d", &data);
			createSingleList(&head, data);
		}
		printLinklist(head);

		removeDuplicate(head);

		printLinklist(head);
	}

	return 0;
}
