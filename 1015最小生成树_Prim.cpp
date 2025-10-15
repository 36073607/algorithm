#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "1015��С������_Prim.h"
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
	G ->arc[0][1] = 10;
	G ->arc[0][5] = 11;

	//B-C B-G B-I
	G ->arc[1][2] = 18;
	G ->arc[1][6] = 16;
	G ->arc[1][8] = 12;

	//C-D C-I
	G ->arc[2][3] = 22;
	G ->arc[2][8] = 8;

	//D-E D-G D-H D-I
	G ->arc[3][4] = 20;
	G ->arc[3][6] = 24;
	G ->arc[3][7] = 16;
	G ->arc[3][8] = 21;

	//E-F E-H
	G ->arc[4][5] = 26;
	G ->arc[4][7] = 7;

	//F-G
	G ->arc[5][6] = 17;

	//G-H
	G ->arc[6][7] = 19;

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
	int i, j, k;//i,j��ѭ��ʱ�õģ�k���ڼ�¼�±�
	int min;//�������̨���ҳ���СȨֵ��
	int weight[MAXSIZE];//��ʾ��ѡ�ߵ�Ȩֵ
	int vex_index[MAXSIZE];//ֵ��ʾ�����㣬�±��ʾ�����

	//�ȴӵ�һ�����㿪ʼ
	weight[0] = 0;
	vex_index[0] = 0;

	for (i = 1; i < G->vertex_num; i++)//����i=0�����ǰ���Ѿ�˵���ˣ����д˴���1��ʼ
	{
		weight[i] = G->arc[0][i];
		vex_index[i] = 0;
	}

	for (i = 1; i < G->vertex_num; i++)//�ҵ���С�ģ���֮����    ע��˴�i��1��ʼ����Ϊ�����Ѿ������ˣ�ֻ��ѭ��n-1�μ���
	{
		min = MAX;
		j = 0;
		k = 0;
		for (j = 0; j < G->vertex_num; j++)
		{
			if (weight[j] != 0 && weight[j]<min)
			{
				min = weight[j];
				k = j;//��k��¼����Ҫ�����һ��������±�
			}
			
		}
		//printf("(%d %d)\n", vex_index[k], k);
		printf("(%c %c)\n", G->vertex[vex_index[k]],G->vertex[k]);

		weight[k] = 0;//�ö����Ѿ���ѡ���ˣ���������Ϊ��ѡ��

		//�������ӽ��Ĵ�ѡ·��
		for (j = 0; j < G->vertex_num; j++)
		{
			if (weight[j] > G->arc[k][j] && weight[j] != 0)//�����k��������ӵĶ�����±�ֵ�����ù�-1������
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