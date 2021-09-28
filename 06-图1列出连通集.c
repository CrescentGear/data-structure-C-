//17/25 
//测试点1	第1个是单独点，最大N	答案错误
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#pragma warning(disable:4996)
#define MaxVertexNum 100


//边
typedef struct ENode* PtrToENode;
typedef PtrToENode Edge;
struct ENode
{
	int V1;
	int	V2;
	int weight;
};

//邻接点
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	int weight;
	int AdjV;
	PtrToAdjVNode Next;
};

//顶点表头结点
typedef struct VNode
{
	int weight;
	PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];

//图结点的定义
typedef struct GNode* PtrToGNode;
typedef PtrToGNode LGraph;
struct GNode
{
	int Nv;
	int Ne;
	AdjList G;
};

PtrToAdjVNode CreateQueue(PtrToAdjVNode data);
void addq(PtrToAdjVNode Q, PtrToAdjVNode data);
PtrToAdjVNode deleteq(PtrToAdjVNode Q);
bool IsEmpty(PtrToAdjVNode Q);
void Insert(LGraph Graph, Edge E);
void DFS(LGraph G, int W, int V[]);
void BFS(LGraph G, int W, int V[]);

int main()
{
	int N, E;
	scanf("%d %d", &N, &E);
	LGraph G = (LGraph)malloc(sizeof(struct GNode));
	G->Ne = E;
	G->Nv = N;
	Edge E1 = (Edge)malloc(sizeof(struct ENode));
	PtrToAdjVNode r = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	int V[MaxVertexNum];
	for (int i = 0; i < N; i++)
	{
		G->G[i].weight = -1;
		G->G[i].FirstEdge = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
		G->G[i].FirstEdge->AdjV = i;
		G->G[i].FirstEdge->weight = -1;
		G->G[i].FirstEdge->Next = NULL;
		V[i] = 0;
	}
	for (int i = 0; i < E; i++)
	{
		scanf(" %d %d", &(E1->V1), &(E1->V2));
		Insert(G, E1);
	}
	for (int i = 0; i < N; i++)
	{
		if (V[i] != 1)
		{
			printf("{ ");
			DFS(G, i, V);
			printf("}\n");
		}
	}
	for (int i = 0; i < N; i++)
	{
		V[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		if (V[i] != 1)
		{
			printf("{ ");
			BFS(G, i, V);
			printf("}\n");
		}
	}
	return 0;
}

PtrToAdjVNode CreateQueue(PtrToAdjVNode data)
{
	PtrToAdjVNode Q = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	Q->AdjV = data->AdjV;
	Q->Next = data->Next;
	Q->weight = data->weight;
	return Q;
}
void addq(PtrToAdjVNode Q, PtrToAdjVNode data)
{
	PtrToAdjVNode Q1 = Q;
	PtrToAdjVNode temp = CreateQueue(data);
	if (Q1 == NULL)
	{
		Q = data;
	}
	else
	{
		while (Q1->Next != NULL)
		{
			Q1 = Q1->Next;
		}
		Q1->Next = temp;
		Q1 = temp;
	}

}
PtrToAdjVNode deleteq(PtrToAdjVNode Q)
{
	PtrToAdjVNode temp = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	temp->AdjV = Q->AdjV;
	temp->weight = Q->weight;
	temp->Next = Q->Next;
	return temp;
}
bool IsEmpty(PtrToAdjVNode Q)
{
	return Q->Next == NULL;
}

void Insert(LGraph Graph, Edge E)
{
	PtrToAdjVNode temp = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	PtrToAdjVNode Gtemp;
	if (E->V2 > E->V1) //换成E->V1 比E->V2大
	{
		int t;
		t = E->V1;
		E->V1 = E->V2;
		E->V2 = t;
	}
	Gtemp = Graph->G[E->V2].FirstEdge;
	while (Gtemp->Next != NULL)
	{
		if (Gtemp->Next->AdjV > E->V1)
		{
			break;
		}
		else
		{
			Gtemp = Gtemp->Next;
		}
	}
	temp->AdjV = E->V1;
	temp->Next = Gtemp->Next;
	Gtemp->Next = temp;
	Graph->G[E->V2].weight += -1;
	Graph->G[E->V1].weight = E->V2;
}

void DFS(LGraph G, int W, int V[])
{
	PtrToAdjVNode temp = G->G[W].FirstEdge;
	printf("%d ", temp->AdjV);
	V[temp->AdjV] = 1;
	while (temp)
	{
		if (!V[temp->AdjV])
		{
			DFS(G, temp->AdjV, V);
		}
		temp = temp->Next;
	}
}

void BFS(LGraph G, int W, int V[])
{
	PtrToAdjVNode Q = CreateQueue(G->G[W].FirstEdge);
	while (Q)
	{
		PtrToAdjVNode temp;
		temp = deleteq(Q);
		Q = Q->Next;
		if (V[temp->AdjV] != 1)
		{
			printf("%d ", temp->AdjV);
			V[temp->AdjV] = 1;
		}
		if (G->G[temp->AdjV].FirstEdge->Next != NULL)
		{
			int t;
			t = G->G[temp->AdjV].FirstEdge->Next->AdjV;
			if (G->G[t].FirstEdge->Next)
				addq(Q, G->G[t].FirstEdge->Next);
		}
	}
}