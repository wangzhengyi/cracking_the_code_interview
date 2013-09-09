/**
 * Implement the "paint fill" function that one might see on many image editing programs.
 * That is, given a screen (represented by a 2 dimensional array of colors), a point, and
 * a new color, fill in the surrounding area until you hit a border of that color.
 *
 * 解题思路：
 * bfs思想，我就写一道bfs题目代替好了：http://acm.hdu.edu.cn/showproblem.php?pid=1242
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point {
	int x, y, time;
} point;

typedef struct queue {
	int front, rear, count;
	point data[40000];
} queue;

queue *q;

int direction[4][2] =
{
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0},
};

char matrix[201][201];
int mark[201][201];

int row, col;


/**
 * 入队
 */
void enqueue(point new)
{
	q->data[q->rear ++] = new;
	q->count ++;
}

/**
 * 出队
 */ 
point dequeue()
{
	point new = q->data[q->front ++];
	q->count --;
	return new;
}

int overmap(int x, int y)
{
	if (x >= 0 && x < row && y >= 0 && y < col)
		return 0;
	else
		return 1;
}


void bfs(point src)
{
	q = (queue *)malloc(sizeof(queue));
	q->rear = q->front = q->count = 0;
	mark[src.x][src.y] = 1;

	enqueue(src);

	while (q->count) {
		point old = dequeue();

		if (matrix[old.x][old.y] == 'r') {
			printf("%d\n", old.time);
			return;
		}

		point new;
		for (int i = 0; i < 4; i ++) {
			new.x = old.x + direction[i][0];
			new.y = old.y + direction[i][1];

			if (matrix[new.x][new.y] == '#' || overmap(new.x, new.y) ||  mark[new.x][new.y]){
				continue;
			}
			if (matrix[new.x][new.y] == '.')
				new.time = old.time + 1;
			else
				new.time = old.time + 2;
			mark[new.x][new.y] = 1;
			enqueue(new);
		}
	}

	printf("Poor ANGEL has to stay in the prison all his life.\n");
}

int main(void)
{
	int i, j;
	point src;

	while (scanf("%d %d", &row, &col) != EOF) {
		// 接收矩阵, 记录起始和结束点
		for (i = 0; i < row; i ++) {
			getchar();
			for (j = 0; j < col; j ++) {
				scanf("%c", &matrix[i][j]);
				if (matrix[i][j] == 'a') {
					src.x = i;
					src.y = j;
					src.time = 0;
				}
			}
		}

		// 广度优先遍历
		memset(mark, 0, sizeof(mark));
		bfs(src);		
	}

	return 0;
}
