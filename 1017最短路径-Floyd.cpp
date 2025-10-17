//���ģ����ν�ͼ�е�ÿ��������Ϊ���м�㡱ȥ������
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000//�����㷨�漰��MAX�ļӼ����ʲ�����Ϊint�������ֵ

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
		G->vertex[i] = i;//���������ִ���ÿ������
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
	int path[MAXSIZE][MAXSIZE];//��������������֮������·����ע�⣺�����е�ֵ����Ķ������յ��ǰ���㣨�յ�ǰ���Ǹ��㣩,��ά���������±��ʾ��һ�����㵽��һ������
	//path[i][j],i��ʾ��㣬j��ʾ�յ㣬�����д��ֵ��ʾ����㵽�յ�Ҫ������ǰ��
	int distance[MAXSIZE][MAXSIZE];//��������������֮������·������

	//��ʼ����D(-1)��Path(-1)
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			distance[i][j] = G->arc[i][j];
			path[i][j] = j;//
		}
	}

	// j:��ʼ���㡡i:��ת���㡡k:��ֹ����
	for (int j = 0; j < G->vertex_num; j++)
	{
		for (int i = 0; i < G->vertex_num; i++)
		{
			for (int k = 0; k < G->vertex_num; k++)
			{
				if (distance[j][k] > distance[j][i] + distance[i][k])//����distance������path
				{
					distance[j][k] = distance[j][i] + distance[i][k];
					path[j][k] = path[j][i];
				}

			}
		}
	}

	int t;// ��ʱ����������׷��·��
	for (int i = 0; i < G->vertex_num; i++) // ����������ʼ����
	{
		for (int j = i + 1; j < G->vertex_num; j++) // ����������ֹ���㣨j>i�������ظ�����Գ�·����
		{
			printf("V%d->V%d weight:%d ", i, j, distance[i][j]);// �������i��j����̾���
			t = path[i][j]; // ��ȡ·���еĵ�һ���м䶥��
			printf("path:V%d", i);// �����ʼ����

			while (t != j)// �ؼ�������·��׷�٣�ֱ�������յ�j
			{
				printf("->V%d", t);// ���·���еĶ���
				t = path[t][j];// �ƶ���·���е���һ������
			}
			printf("->V%d\n", j); // ����յ�
		}
		printf("\n");// ÿ����ʼ������������
	}
}
//�����Ҫϸ�ڣ�
//ѭ������ j = i + 1��
//��Ϊ������ͼ��distance[i][j] = distance[j][i]
//ֻ��� i < j ������������ظ�����ԳƵ�·����
//
//	·��׷���߼���
//	t = path[i][j] �õ���i�����ĵ�һ������
//	t = path[t][j] ����·��һ����ǰ��
//	�� t == j ʱ˵�������յ�
//
//	�����ʽ��
//	��������룺"V0->V1 weight:5 "
//	���������·����"path:V0->V1->V2"
int main()
{
	Mat_Graph* G = new(Mat_Graph);
	createGrph(G);
	floyd(G);
	delete G;

	return 0;
}