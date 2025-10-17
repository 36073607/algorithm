//此算法不是走最短路径的这个路径，而是在不断的去观察每一个顶点
//然后去找初始顶点到每一个顶点最短的权值是多少
//同时也找到达离每一个顶点最近的那一个顶点是谁
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000//下面算法涉及到MAX的加减，故不能设为int类型最大值

typedef int VertexType;
typedef int EdgeType;
typedef struct
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

void createGrph(Mat_Graph* G)
{
	G->vertex_num = 9;
	G->edge_num = 16;

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;//这里用数字代表每个顶点
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = MAX;
			}

		}
	}

	G ->arc[0][1] = 1;
	G ->arc[0][2] = 5;

	G ->arc[1][2] = 3;
	G ->arc[1][3] = 7;
	G ->arc[1][4] = 5;

	G ->arc[2][4] = 1;
	G ->arc[2][5] = 7;

	G ->arc[3][4] = 2;
	G ->arc[3][6] = 3;

	G ->arc[4][5] = 3;
	G ->arc[4][6] = 6;
	G ->arc[4][7] = 9;

	G ->arc[5][7] = 5;

	G ->arc[6][7] = 2;
	G ->arc[6][8] = 7;

	G ->arc[7][8] = 4;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

int choose(int* found, int* distance,Mat_Graph* G)//这个函数的作用是：在未访问的顶点中，选择当前距离起点最近的顶点。
{
	int min = MAX;
	int minPos = -1;
	for (int i = 0; i < G->vertex_num; i++)
	{
		if (distance[i] < min && found[i] == 0)
		{
			min = distance[i];
			minPos = i;
		}

	}
	return minPos;
}

void dijkstra(Mat_Graph* G, int begin)
{
	int found[MAXSIZE];//记录顶点是否已经走过
	int	path[MAXSIZE];//用于记录两个顶点间的最短路径：数组值与该值对应的下标分别表示两个顶点。例如：path[0]=1,表示到达V0顶点的最近顶点为V1
	int distance[MAXSIZE];//用于记录初始顶点begin到达每一个顶点的最短距离,数组下标表示顶点

	for (int i = 0; i < G->vertex_num; i++)
	{
		found[i] = 0;
		path[i] = -1;//这里用-1表示初始顶点
		distance[i] = G->arc[begin][i];//先把与初始顶点直接相连的边的距离（每条边的权值）放入数组中
	}
	found[begin] = 1;
	distance[begin] = 0;

	int next;//用于记录下一个要观察的顶点
	for (int i = 0; i < G->vertex_num; i++)//循环，找出所有接下来要观察的顶点，并进行后续操作
	{
		next = choose(found, distance,G);//找到要观察的顶点
		if (next == -1) 
			break; // 如果没有可达顶点，提前结束
		found[next] = 1;//将要观察的这个顶点设为"已观察"

		for (int j = 0; j < G->vertex_num; j++)//查找 要观察的顶点 是否带来更优的路径
		{
			// 修正条件：检查目标顶点j是否未访问，并且通过next到达j的路径更短
			if (found[j] == 0 && G->arc[next][j] != MAX && distance[next] + G->arc[next][j] < distance[j])
			{
				distance[j] = distance[next] + G->arc[next][j];
				path[j] = next;
			}
			//G->arc[next][j] != MAX 含义：顶点next和顶点j之间存在直接边（不是无穷大）作用：确保两个顶点是连通的
			//防止重复处理（条件1）确保路径存在（条件2）保证最优性（条件3）
		}
	}

	// 打印输出
	for (int i = 0; i < G->vertex_num; i++)// 对每个顶点i，输出从起点begin到i的最短路径信息
	{
		printf("V%d -> V%d : ", begin, i);
		if (distance[i] == MAX)
		{
			printf("Unreachable\n");
		}
		else
		{
			printf("%d\n", distance[i]);

			// 打印路径
			if (i != begin)
			{
				printf("Path: V%d", i);
				int j = i;
				while (path[j] != -1)//-1是起点
				{
					printf(" <- V%d", path[j]);
					j = path[j];
				}
				printf(" <- V%d\n", begin);
			}
			else//当i == begin时（起点到自身），直接输出起点，不需要回溯。
			{
				printf("Path: V%d\n", begin);
			}
		}
		printf("\n");
	}

}

int main()
{
	Mat_Graph* G = new(Mat_Graph);
	createGrph(G);
	int begin = 0;
	dijkstra(G, begin);

	return 0;
}
