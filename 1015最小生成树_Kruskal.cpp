#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAX 0x7fffffff //int�������ֵ��ʾ����
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
				G->arc[i][j] = 0;//�Խ����ϵ�ȨֵΪ0���Ͼ��Լ����Լ����γɲ���һ����
			}
			else
			{
				G->arc[i][j] = MAX;//����ı��ȸ�������
			}
		}
	}

	//��ÿ���߸�Ȩ��ֵ
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
	while (parent[index] > 0)//����parent��������ֵʱ������ͬһ������һ�����㡰����һ�¡����������߼��ϵĳɻ����γ�һ������
	{
		index = parent[index];
	}
	return index;
}

void Kruskal(Mat_Grph* G)
{
	Edge edges[MAXSIZE];//����ÿ����ͷ��β��Ȩֵ
	int k = 0;//�䵱�����±�,����k��ֵΪ�������Ԫ��
	//���ݴ���������ͼȥ����edges����
	for (int i = 0; i < G->vertex_num; i++)//j��i+1��ʼ����ֹȡ���Խ���
	{
		for (int j = i + 1; j < G->vertex_num; j++)
		{
			edges[k].begin = i;
			edges[k].end = j;
			edges[k].weight = G->arc[i][j];
			k++;
		}
		
	}

	my_BubbleSort(edges,k);//�Ա߽�������

	int parent[MAXSIZE];//������Prim�㷨�е�vex_index,�����е�ֵ��ʾһ�����㣬�����±��ʾ��֮��������һ������
	for (int i = 0; i < G->vertex_num; i++)
	{
		parent[i] = 0;
	}

	int n, m;//���ڱ�ʾ����
	for (int i = 0; i < G->edge_num; i++)//15���ߣ�ѭ��15��
	{
		n = find(parent, edges[i].begin);
		m = find(parent, edges[i].end);
		if (n != m)//�ҵ������������ͨ��·�ﵽ��ת������γɻ�·�˾ͻ�ת��ԭ�أ�n = m�����ɻ���n!=m�����
		{
			parent[n] = m;//���µĽ�����뵽parent������
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