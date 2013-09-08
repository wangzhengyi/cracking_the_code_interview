/**
 * Imageine a robot sitting on the upper left hand corner of an N*N grid. The robot can
 * only move in two directions:right and down.How many possible paths are there for
 * the robot?
 * FOLLOW UP
 * Imagine cretain squares are "off limits", such that the robot can not step on them.
 * Design an algorithm to get all possible paths for the robot.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 5
#define COL 5

// 标记数组
int mark[ROW][COL];

// 定义迷宫，1能走，0不能走
int matrix[ROW][COL] = 
{
	{1, 0, 1, 1, 0},
	{1, 1, 1, 1, 0},
	{0, 1, 0, 1, 1},
	{1, 1, 1, 1, 1},
	{1, 0, 1, 0, 1},
};

// 方向
int direction[2][2] = 
{
	{0, 1},
	{1, 0},
};

int step;

/**
 * 判断是否越界
 *
 * T = O(1)
 *
 */
int overmap(int x, int y)
{
	if (x >= 0 && x < ROW && y >= 0 && y < COL)
		return 0;
	else
		return 1;
}

/**
 * 深度优先搜索所有可能的路径
 *
 */
void dfs(int t, int srcx, int srcy, int dstx, int dsty)
{
	if (srcx == dstx && srcy == dsty) { // 终点
		int i, k, j;
		for (i = 1; i <= step + 1; i ++) {
			for (j = 0; j < ROW; j ++) {
				for (k = 0; k < COL; k ++) {
					if (mark[j][k] == i) {
						printf("(%d, %d) ", j + 1, k + 1);
						break;
					}
				}
			}
		}
		printf("\n");
	} else {
		int i, newx, newy;
		for (i = 0; i < 2; i ++) {
			newx = srcx + direction[i][0];
			newy = srcy + direction[i][1];

			if (overmap(newx, newy) == 0 && mark[newx][newy] == 0 && matrix[newx][newy] == 1) {
				mark[newx][newy] = t;
				dfs(t + 1, newx, newy, dstx, dsty);
				mark[newx][newy] = 0;
			}
		}
	}
}


int main(void)
{
	int srcx, srcy, dstx, dsty;

	while (scanf("%d %d %d %d", &srcx, &srcy, &dstx, &dsty) != EOF) {
		memset(mark, 0, sizeof(mark));
		mark[srcx][srcy] = 1;
	
		step = dstx - srcx + dsty - srcy;

		dfs(2, srcx, srcy, dstx, dsty);
	}

	return 0;
}
