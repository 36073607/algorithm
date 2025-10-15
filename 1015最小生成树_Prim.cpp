#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAX 0x7fffffff //int类型最大值表示无穷
typedef char VertexType;
typedef int EdgeType;

typedef struct Mat_Grph
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;

void creatGrph(Mat_Grph* G)
{
	G->vertex_num = 9;
	G->edge_num = 15;

	G->vertex_num = 9;
	G->edge_num = 15;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;//对角线上的权值为0，毕竟自己跟自己都形成不了一条边
			}
			else
			{
				G->arc[i][j] = MAX;//其余的边先赋成无限
			}
		}
	}

	//给每条边赋权重值
	//A-B A-F
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;

	//B-C B-G B-I
	G->arc[1][2] = 18;
	G->arc[1][6] = 16;
	G->arc[1][8] = 12;

	//C-D C-I
	G->arc[2][3] = 22;
	G->arc[2][8] = 8;

	//D-E D-G D-H D-I
	G->arc[3][4] = 20;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][8] = 21;

	//E-F E-H
	G->arc[4][5] = 26;
	G->arc[4][7] = 7;

	//F-G
	G->arc[5][6] = 17;

	//G-H
	G->arc[6][7] = 19;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

void prim(Mat_Grph* G)
{
	int i, j, k;//i,j是循环时用的，k用于记录下标
	int min;//经典打擂台，找出最小权值边
	int weight[MAXSIZE];//表示侯选边的权值
	int vex_index[MAXSIZE];//值表示出发点，下标表示到达点

	//先从第一个顶点开始
	weight[0] = 0;
	vex_index[0] = 0;

	for (i = 1; i < G->vertex_num; i++)//由于i=0的情况前面已经说明了，所有此处从1开始
	{
		weight[i] = G->arc[0][i];//其他顶点到A的权重
		vex_index[i] = 0;//都是从A出发
	}

	for (i = 1; i < G->vertex_num; i++)//找到最小的，与之连接    注意此处i从1开始，因为顶点已经加入了，只需循环n-1次即可
	{
		min = MAX;
		j = 0;
		k = 0;
		for (j = 0; j < G->vertex_num; j++)
		{
			if (weight[j] != 0 && weight[j] < min)
			{
				min = weight[j];
				k = j;//用k记录符合要求的下一个顶点的下标
			}

		}
		//printf("(%d %d)\n", vex_index[k], k);
		printf("(%c %c)\n", G->vertex[vex_index[k]], G->vertex[k]);

		weight[k] = 0;//该顶点已经被选完了，不能再作为侯选边

		//找新连接结点的待选路径，更新侯选边权重
		for (j = 0; j < G->vertex_num; j++)
		{
			if (weight[j] > G->arc[k][j] && weight[j] != 0)//这里的k就是新添加的顶点的下标值，不用管-1的问题
			{
				weight[j] = G->arc[k][j];
				vex_index[j] = k;
			}
		}
	}
}

int main()
{
	//Mat_Grph* G = (Mat_Grph*)malloc(sizeof(Mat_Grph));
	Mat_Grph G;
	creatGrph(&G);
	prim(&G);

	return 0;
}
