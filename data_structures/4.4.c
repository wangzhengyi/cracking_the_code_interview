/**
 * Given a binary search tree, design an algorithm which creates a linked list of all the
 * nodes at each depth
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct btree {
	struct btree *lchild, *rchild;
	int data;
} btree;

typedef struct queue {
	int front, rear, count;
	btree* data[1001];
} queue;

typedef struct list {
	int data;
	struct list *next;
} list;

// 全局变量
queue *q;
btree* store[1001];

/**
 * qsort比较函数
 *
 * T = O(nlogn)
 *
 */
int compare(const void *p, const void *q)
{
	const int *a = p;
	const int *b = q;

	return *a - *b;
}

/**
 * 根据有序序列arr创建最小高度的二叉树
 *
 * T = O(logn)
 *
 */
void createMinimalTree(btree **t, int *arr, int begin, int end)
{
	int mid;
	*t = NULL;

	if (begin <= end) {
		mid = (begin + end) / 2;
		*t = (btree *)malloc(sizeof(**t));
		(*t)->data = arr[mid];
		createMinimalTree(&(*t)->lchild, arr, begin, mid - 1);
		createMinimalTree(&(*t)->rchild, arr, mid + 1, end);
	}
}

/**
 * 入队函数
 *
 * T = O(1)
 *
 */
void enQueue(btree *t)
{
	q->count ++;
	q->data[q->rear ++] = t;
}

/**
 * 出队函数
 *
 * T = O(1)
 *
 */
btree* deQueue()
{
	q->count --;
	return q->data[q->front ++];
}

/**
 * 创建单链表
 *
 * T = O(n)
 *
 */
void createLink(list **l, int data)
{
	list *cur, *pre, *new;

	cur = *l;
	pre = NULL;

	while (cur != NULL) {
		pre = cur;
		cur = cur->next;
	}

	new = (list *)malloc(sizeof(list));
	new->data = data;
	new->next = NULL;

	if (pre == NULL) {
		*l = new;
	} else {
		pre->next = new;
	}
}

/**
 * 挨层构建单链表并且打印
 */
void bfsCreateList(btree *t)
{
	if (t != NULL)	enQueue(t);
	list *head;
	int i, j, level = 1;
	btree *old;

	while (q->count > 0) {
		for (i = 0; q->count > 0; i ++)
			store[i] = deQueue();
		
		// 依据层次构建链表,打印链表
		for (j = 0, head = NULL; j < i; j ++) {
			createLink(&head, store[j]->data);
		}
		
		// 打印链表
		printf("打印第%d层链表:\n", level);
		while (head->next != NULL) {
			printf("%d ", head->data);
			head = head->next;
		}	
		printf("%d\n", head->data);

		// 重新构建队列
		for (j = 0; j < i; j ++) {
			old = store[j];
			if (old->lchild != NULL)
				enQueue(old->lchild);
			if (old->rchild != NULL)
				enQueue(old->rchild);
		}
	}
}

int main(void)
{
	int i, n, *arr;
	btree *t;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);

		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);

		qsort(arr, n, sizeof(arr[0]), compare);

		createMinimalTree(&t, arr, 0, n - 1);

		q = (queue *)malloc(sizeof(queue));
		q->front = q->rear = q->count = 0;

		bfsCreateList(t);

		free(arr);
	}

	return 0;
}
