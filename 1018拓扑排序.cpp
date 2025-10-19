#include <iostream>
using namespace std;
typedef int VertextType;
typedef int EdgeType;
#define MAXSIZE 100

typedef struct Mat_Graph//�ڽӾ���
{
	VertextType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

typedef struct EdgeNode
{
	int edge_vex;//Ŀ�궥����±�
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertextNode
{
	int in;//���������Ǽ�
	VertextType data;
	EdgeNode* next;
}VertextNode;

typedef VertextNode Adj_List[MAXSIZE];//adjacency�����ڽӣ�ע�������֪ʶ��
//���д������˼�ǣ�����һ��������Adj_List������һ������MAXSIZE��VertextNodeԪ�ص��������͡�
//Adj_List graph;  �ȼ��� VertexNode graph[MAXSIZE];

typedef struct Adj_Graph//�ڽӱ�
{
	Adj_List adj_list;
	int vertex_num;
	int edge_num;
}Adj_Graph;

typedef Adj_Graph* Adj_List_Graph;

void createGraph(Mat_Graph* G)//�����ڽӾ���
{
	G->vertex_num = 14;
	G->edge_num = 20;

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;
	}
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	//�ڽӾ����У�i��ʾ��ʼ���㣬j��ʾ��ֹ����
	G ->arc[0][4] = 1;
	G ->arc[0][5] = 1;
	G ->arc[0][11] = 1;
	G ->arc[1][2] = 1;
	G ->arc[1][4] = 1;
	G ->arc[1][8] = 1;
	G ->arc[2][5] = 1;
	G ->arc[2][6] = 1;
	G ->arc[2][9] = 1;
	G ->arc[3][2] = 1;
	G ->arc[3][13] = 1;
	G ->arc[4][7] = 1;
	G ->arc[5][8] = 1;
	G ->arc[5][12] = 1;
	G ->arc[6][5] = 1;
	G ->arc[8][7] = 1;
	G ->arc[9][10] = 1;
	G ->arc[9][11] = 1;
	G ->arc[10][13] = 1;
	G ->arc[12][9] = 1;

}

void creat_adj_graph(Mat_Graph* G, Adj_List_Graph* ALG)
{
	*ALG = new(Adj_Graph);
	(*ALG)->vertex_num = G->vertex_num;
	(*ALG)->edge_num = G->edge_num;

	for (int i = 0; i < G->vertex_num; i++)//���ڽӱ�򵥴���
	{
		(*ALG)->adj_list[i].in = 0;
		(*ALG)->adj_list[i].data = G->vertex[i];
		(*ALG)->adj_list[i].next = NULL;
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (G->arc[i][j] == 1)
			{
				EdgeNode* e = new(EdgeNode);
				e->edge_vex = j;

				//�������ͷ�巨:
				e->next = (*ALG)->adj_list[i].next;
				(*ALG)->adj_list[i].next = e;
				//i ��ʾ�ߵ���㣨Դ���㣩
				//���д��뽫�´����ı߽ڵ� e ���뵽���� i ���ڽ�������

				(*ALG)->adj_list[j].in++;
				//j ��ʾ�ߵ��յ㣨Ŀ�궥�㣩
				//���д������Ӷ��� j ����ȣ�in - degree��
				//��ʾ"���� j �������������1"
			}

		}
	}

}

int top = -1;
int stack[MAXSIZE];

void push(int e)
{
	if (top >= MAXSIZE)
	{
		printf("����\n");
		return;
	}
	top++;
	stack[top] = e;
}

int pop()
{
	if (top == -1)
	{
		printf("�յ�\n");
		return 0;
	}
	int ret = stack[top];
	top--;
	return ret;
}

int is_empty()
{
	if (top == -1)
	{
		return 0;
	}
	return 1;
}

void topological_sort(Adj_List_Graph ALG)//������������
{
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (ALG->adj_list[i].in == 0)
		{
			push(i);
		}
	}

	while (::is_empty())
	{
		int curr = pop();
		printf("V%d -> ", ALG->adj_list[curr].data);
		EdgeNode* e = ALG->adj_list[curr].next;

		while (e != NULL)
		{
			int k = e->edge_vex;
			ALG->adj_list[k].in--;
			if (ALG->adj_list[k].in == 0)
			{
				push(k);
			}
			e = e->next;
		}
		
	}

}

int main()
{
	Mat_Graph* G = new(Mat_Graph);
	createGraph(G);

	Adj_List_Graph* ALG = new(Adj_List_Graph);
	creat_adj_graph(G, ALG);

	topological_sort(*ALG);

	delete G;
	delete ALG;

	return 0;
}