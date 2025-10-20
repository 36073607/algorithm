#include <iostream>
using namespace std;
#define MAXSIZE 100
#define MAX 0x7fffffff
typedef int VertextType;
typedef int EdgeType;

typedef struct Mat_Graph//邻接矩阵
{
	VertextType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

typedef struct EdgeNode
{
	int edge_vex;
	int weight;
	EdgeNode* next;
}EdgeNode;

typedef struct VertextNode
{
	int in;
	VertextType data;
	EdgeNode* next;
}VertextNode;

typedef VertextNode Adj_List[MAXSIZE];

typedef struct Adj_Graph//邻接表
{
	Adj_List adj_list;
	int vertex_num;
	int edge_num;
}Adj_Graph;

typedef struct Adj_Graph* Adj_List_Graph;

void creatGraph(Mat_Graph* G)
{
	G->vertex_num = 10;
	G->edge_num = 13;

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;
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

	G->arc[0][1] = 3;
	G->arc[0][2] = 4;
	G->arc[1][3] = 5;
	G->arc[1][4] = 6;
	G->arc[2][3] = 8;
	G->arc[2][5] = 7;
	G->arc[3][4] = 3;
	G->arc[4][6] = 9;
	G->arc[4][7] = 4;
	G->arc[5][7] = 6;
	G->arc[6][9] = 2;
	G->arc[7][8] = 5;
	G->arc[8][9] = 3;

}

void creat_adj_graph(Mat_Graph* G, Adj_List_Graph* ALG)
{
	(*ALG)->vertex_num = G->vertex_num;
	(*ALG)->edge_num = G->edge_num;
	for (int i = 0; i < (*ALG)->vertex_num; i++)
	{
		(*ALG)->adj_list[i].data = G->vertex[i];
		(*ALG)->adj_list[i].in = 0;
		(*ALG)->adj_list[i].next = NULL;
	}

	for (int i = 0; i < (*ALG)->vertex_num; i++)
	{
		for (int j = 0; j < (*ALG)->vertex_num; j++)
		{
			if (G->arc[i][j] != 0 && G->arc[i][j] < MAX)
			{
				EdgeNode* e = new(EdgeNode);
				e->edge_vex = j;
				e->weight = G->arc[i][j];

				e->next = (*ALG)->adj_list[i].next;
				(*ALG)->adj_list[i].next = e;
				(*ALG)->adj_list[j].in++;
			}
		}

	}
}

void critical_path(Adj_List_Graph ALG)
{
	int top1 = -1;
	int top2 = -1;
	int stack1[MAXSIZE];//正常做事顺序，用来做拓扑排序或计算最早发生时间
	int stack2[MAXSIZE];//倒着的顺序，用来计算最晚发生时间
	//最晚发生时间是从后往前算的，做拓扑排序是从前往后的
	//每一次拓扑排序出栈后压入另一个栈
	//最后将另一个栈中的内容挨个出栈，达到逆序的效果
	int etv[MAXSIZE];//最早发生时间    etv[i] 表示事件i的最早发生时间，i通常是拓扑排序中的顶点序号
	int ltv[MAXSIZE];//最晚发生时间
	int curr = 0;//保存出栈的内容
	int k = 0;//k当作下标用

	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (ALG->adj_list[i].in == 0)
		{
			stack1[++top1] = i;
		}
	}
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		etv[i] = 0;
	}
	printf("toop: ");
	while (top1 != -1)
	{
		curr = stack1[top1--];
		printf("V%d - > ", ALG->adj_list[curr].data);

		top2++;
		stack2[top2] = curr;

		EdgeNode* e;
		e = ALG->adj_list[curr].next;
		while (e != NULL)
		{
			k = e->edge_vex;//k：由当前事件curr通过边e指向的下一个事件
			ALG->adj_list[k].in--;
			if (ALG->adj_list[k].in == 0)
			{
				stack1[++top1] = k;
			}

			if (etv[curr] + e->weight > etv[k])//curr最早发生时间+通过边e指向的下一个事件(顶点)k的时间，与 事件(顶点)k的最早发生时间比较
			{
				etv[k] = etv[curr] + e->weight;
				//etv[curr]：事件curr的最早发生时间
				//e->weight：从curr到k的活动的持续时间（权重）
				//etv[k]：事件k的最早发生时间
			}

			e = e->next;
		}
	}
	printf("End\n");
	printf("etv: ");
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", etv[i]);
	}
	printf("End\n");


	for (int i = 0; i < ALG->vertex_num; i++)
	{
		ltv[i] = etv[ALG->vertex_num - 1];
	}
	while (top2 != -1)
	{
		curr = stack2[top2--];
		EdgeNode* e;
		e = ALG->adj_list[curr].next;
		while (e != NULL)
		{
			k = e->edge_vex;
			if (ltv[curr] > ltv[k] - e->weight)
			{
				ltv[curr] = ltv[k] - e->weight;
			}
			e = e->next;
		}
	}
	printf("ltv: ");
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", ltv[i]);
	}
	printf("End\n");

	int flag = 1;
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (etv[i] == ltv[i])
		{
			if (!flag)
			{
				printf(" -> ");
			}
			printf("%d", i);
			flag = 0;
		}
	}

}

int main()
{
	Mat_Graph* G = new(Mat_Graph);
	creatGraph(G);

	Adj_List_Graph ALG = new(Adj_Graph);
	creat_adj_graph(G, &ALG);

	critical_path(ALG);

	delete ALG;
	delete G;

	return 0;
}