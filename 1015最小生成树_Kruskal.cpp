#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAXEDGE 200
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

typedef struct Edge
{
	int begin;
	int end;
	int weight;
}Edge;

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

void my_BubbleSort(Edge* t,int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (t[j].weight > t[j + 1].weight)
			{
				Edge tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
		}

	}

}

int find(int* parent, int index)
{
	while (parent[index] > 0)//这里parent数组中有值时，就让同一条边另一个顶点“代替一下”，类似于逻辑上的成环，形成一个整体
	{
		index = parent[index];
	}
	return index;
}

void Kruskal(Mat_Grph* G)
{
	Edge edges[MAXEDGE];//存入每条边头、尾、权值EDGE
	int k = 0;//充当数组下标,最终k的值为数组具体元素
	//根据创建的那张图去创建edges数组
	for (int i = 0; i < G->vertex_num; i++)//j从i+1开始，防止取到对角线
	{
		for (int j = i + 1; j < G->vertex_num; j++)
		{
			edges[k].begin = i;
			edges[k].end = j;
			edges[k].weight = G->arc[i][j];
			k++;
		}
		
	}

	my_BubbleSort(edges,k);//对边进行排序

	int parent[MAXSIZE];//类似于Prim算法中的vex_index,数组中的值表示一个顶点，数组下标表示与之相连的另一个顶点
	for (int i = 0; i < G->vertex_num; i++)
	{
		parent[i] = 0;
	}

	int n, m;//用于表示顶点
	for (int i = 0; i < G->edge_num; i++)//15条边，循环15次
	{
		n = find(parent, edges[i].begin);
		m = find(parent, edges[i].end);
		if (n != m)//我的理解是它在联通的路里到处转，如果形成回路了就会转回原地，n = m；不成环即n!=m就输出
		{
			parent[n] = m;//让新的结果加入到parent数组中
			printf("(%c %c) %d\n", G->vertex[edges[i].begin], G->vertex[edges[i].end],edges[i].weight);
		}

	}

}

int main()
{
	Mat_Grph* G = new(Mat_Grph);
	creatGrph(G);
	Kruskal(G);
	delete G;

	return 0;

}
