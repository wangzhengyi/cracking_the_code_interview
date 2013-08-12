/**
 * Given a directed graph, design an algorithm to find out whether there is a route
 * between two nodes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point {
	int x, y;
} point;

typedef struct queue {
	int front, rear, count;
	point data[10001];
} queue;

// 模拟一个图,0代表不通,1代表相通
int graph[6][6] = 
{
	{0, 1, 0, 1, 0, 0},
	{0, 1, 1, 0, 1, 0},
	{0, 0, 1, 1, 1, 1},
	{0, 1, 0, 1, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0, 1}
};

// 方向
int dir[4][2] =
{
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1}
};


// 标记数组
int mark[6][6];

// 队列指针
queue *q;

// 路径数组
int count;
point path[10001];

void enQueue(point t)
{
	q->data[q->rear ++] = t;
	q->count += 1;
}

point deQueue()
{
	q->count -= 1;
	return q->data[q->front ++];
}

int bfs(point u, point v)
{
	enQueue(u);
	int i;
	point old, new;

	while (q->count > 0) {
		old = deQueue();
		if (old.x == v.x && old.y == v.y)
			return 1;

		for (i = 0; i < 4; i ++) {
			new.x = old.x + dir[i][0];
			new.y = old.y + dir[i][1];
			if (new.x >= 0 && new.x < 6 && new.y >=0 && new.y < 6 && mark[new.x][new.y] == 0 && graph[new.x][new.y] == 1) {
				mark[new.x][new.y] = 1;
				enQueue(new);
			}
		}	
	}

	return 0;
}

int main(void)
{
	point u, v;
	int flag;
	q = (queue *)malloc(sizeof(*q));


	while (scanf("%d %d %d %d", &u.x, &u.y, &v.x, &v.y) != EOF) {
		// 查找u到v的最短路径
		q->front = q->rear = q->count = 0;
		count = 0;
		memset(mark, 0, sizeof(mark));
		flag = bfs(u, v);
		if (flag)
			printf("存在路径\n");
		else
			printf("不存在路径\n");
	}
	
	return 0;
}
