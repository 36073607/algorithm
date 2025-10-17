//���㷨���������·�������·���������ڲ��ϵ�ȥ�۲�ÿһ������
//Ȼ��ȥ�ҳ�ʼ���㵽ÿһ��������̵�Ȩֵ�Ƕ���
//ͬʱҲ�ҵ�����ÿһ�������������һ��������˭
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

int choose(int* found, int* distance,Mat_Graph* G)//��������������ǣ���δ���ʵĶ����У�ѡ��ǰ�����������Ķ��㡣
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
	int found[MAXSIZE];//��¼�����Ƿ��Ѿ��߹�
	int	path[MAXSIZE];//���ڼ�¼�������������·��������ֵ���ֵ��Ӧ���±�ֱ��ʾ�������㡣���磺path[0]=1,��ʾ����V0������������ΪV1
	int distance[MAXSIZE];//���ڼ�¼��ʼ����begin����ÿһ���������̾���,�����±��ʾ����

	for (int i = 0; i < G->vertex_num; i++)
	{
		found[i] = 0;
		path[i] = -1;//������-1��ʾ��ʼ����
		distance[i] = G->arc[begin][i];//�Ȱ����ʼ����ֱ�������ıߵľ��루ÿ���ߵ�Ȩֵ������������
	}
	found[begin] = 1;
	distance[begin] = 0;

	int next;//���ڼ�¼��һ��Ҫ�۲�Ķ���
	for (int i = 0; i < G->vertex_num; i++)//ѭ�����ҳ����н�����Ҫ�۲�Ķ��㣬�����к�������
	{
		next = choose(found, distance,G);//�ҵ�Ҫ�۲�Ķ���
		if (next == -1) 
			break; // ���û�пɴﶥ�㣬��ǰ����
		found[next] = 1;//��Ҫ�۲�����������Ϊ"�ѹ۲�"

		for (int j = 0; j < G->vertex_num; j++)//���� Ҫ�۲�Ķ��� �Ƿ�������ŵ�·��
		{
			// �������������Ŀ�궥��j�Ƿ�δ���ʣ�����ͨ��next����j��·������
			if (found[j] == 0 && G->arc[next][j] != MAX && distance[next] + G->arc[next][j] < distance[j])
			{
				distance[j] = distance[next] + G->arc[next][j];
				path[j] = next;
			}
			//G->arc[next][j] != MAX ���壺����next�Ͷ���j֮�����ֱ�ӱߣ�������������ã�ȷ��������������ͨ��
			//��ֹ�ظ���������1��ȷ��·�����ڣ�����2����֤�����ԣ�����3��
		}
	}

	// ��ӡ���
	for (int i = 0; i < G->vertex_num; i++)// ��ÿ������i����������begin��i�����·����Ϣ
	{
		printf("V%d -> V%d : ", begin, i);
		if (distance[i] == MAX)
		{
			printf("Unreachable\n");
		}
		else
		{
			printf("%d\n", distance[i]);

			// ��ӡ·��
			if (i != begin)
			{
				printf("Path: V%d", i);
				int j = i;
				while (path[j] != -1)//-1�����
				{
					printf(" <- V%d", path[j]);
					j = path[j];
				}
				printf(" <- V%d\n", begin);
			}
			else//��i == beginʱ����㵽������ֱ�������㣬����Ҫ���ݡ�
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
