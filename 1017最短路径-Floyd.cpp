//核心：依次将图中的每个顶点作为“中间点”去做更新
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

	G->arc[0][1] = 1;
	G->arc[0][2] = 5;

	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;

	G->arc[3][4] = 2;
	G->arc[3][6] = 3;

	G->arc[4][5] = 3;
	G->arc[4][6] = 6;
	G->arc[4][7] = 9;

	G->arc[5][7] = 5;

	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

void floyd(Mat_Graph* G)
{
	int path[MAXSIZE][MAXSIZE];//保存任意两个点之间的最短路径，注意：数组中的值代表的顶点是终点的前驱点（终点前面那个点）,二维数组两个下标表示从一个顶点到另一个顶点
	//path[i][j],i表示起点，j表示终点，数组中存的值表示从起点到终点要经过的前驱
	int distance[MAXSIZE][MAXSIZE];//保存任意两个点之间的最短路径长度

	//初始化，D(-1)和Path(-1)
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			distance[i][j] = G->arc[i][j];
			path[i][j] = j;//
		}
	}

	// j:起始顶点　i:中转顶点　k:终止顶点
	for (int j = 0; j < G->vertex_num; j++)
	{
		for (int i = 0; i < G->vertex_num; i++)
		{
			for (int k = 0; k < G->vertex_num; k++)
			{
				if (distance[j][k] > distance[j][i] + distance[i][k])//根据distance来更新path
				{
					distance[j][k] = distance[j][i] + distance[i][k];
					path[j][k] = path[j][i];
				}

			}
		}
	}

	int t;// 临时变量，用于追踪路径
	for (int i = 0; i < G->vertex_num; i++) // 遍历所有起始顶点
	{
		for (int j = i + 1; j < G->vertex_num; j++) // 遍历所有终止顶点（j>i，避免重复输出对称路径）
		{
			printf("V%d->V%d weight:%d ", i, j, distance[i][j]);// 输出顶点i到j的最短距离
			t = path[i][j]; // 获取路径中的第一个中间顶点
			printf("path:V%d", i);// 输出起始顶点

			while (t != j)// 关键：沿着路径追踪，直到到达终点j
			{
				printf("->V%d", t);// 输出路径中的顶点
				t = path[t][j];// 移动到路径中的下一个顶点
			}
			printf("->V%d\n", j); // 输出终点
		}
		printf("\n");// 每组起始顶点输出完后换行
	}
}
//输出重要细节：
//循环条件 j = i + 1：
//因为是无向图，distance[i][j] = distance[j][i]
//只输出 i < j 的情况，避免重复输出对称的路径对
//
//	路径追踪逻辑：
//	t = path[i][j] 得到从i出发的第一个顶点
//	t = path[t][j] 沿着路径一步步前进
//	当 t == j 时说明到达终点
//
//	输出格式：
//	先输出距离："V0->V1 weight:5 "
//	再输出完整路径："path:V0->V1->V2"
int main()
{
	Mat_Graph* G = new(Mat_Graph);
	createGrph(G);
	floyd(G);
	delete G;

	return 0;
}