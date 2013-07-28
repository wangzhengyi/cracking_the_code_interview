/**
 * Implement an algorithm to find the nth to last element of a singly linked list
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
 * 查找单链表的第num个节点
 *
 * T = O(n)
 *
 */
link* searchNode(link *head, int num)
{
	while (-- num) {
		head = head->next;
	}
	return head;
}

/**
 * 删除指定的节点
 *
 * T = O(1)
 *
 */
void removeNode(link *del)
{
	// 删除del，可以把del->next->value给del，然后删除del->next这个节点即可

	if (del == NULL || del->next == NULL) return;

	link *post;
	post = del->next;
	del->value = post->value;
	del->next = post->next;
	free(post);
}


int main(void)
{
	int i, n, num, data;
	link *head, *del;

	while (scanf("%d", &n) != EOF) {
		for (i = 0, head = NULL; i < n; i ++) {
			scanf("%d", &data);
			createLinklist(&head, data);
		}

		// 删除节点的值
		scanf("%d", &num);
		del = searchNode(head, num);

		printLinklist(head);

		// 删除指定节点
		removeNode(del);
		printLinklist(head);
	}

	return 0;
}
