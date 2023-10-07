#pragma warning(disable : 4996)
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 图的邻接表表示法 */

#define MaxVertexNum 100 /* 最大顶点数设为100 */
typedef int Vertex;      /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;  /* 边的权值设为整型 */
typedef char DataType;   /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode {
  Vertex V1, V2;     /* 有向边<V1, V2> */
  WeightType Weight; /* 权重 */
};
typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
  Vertex AdjV;        /* 邻接点下标 */
  WeightType Weight;  /* 边权重 */
  PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode {
  PtrToAdjVNode FirstEdge; /* 边表头指针 */
  DataType Data;           /* 存顶点的数据 */
  /* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */
} AdjList[MaxVertexNum]; /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode {
  int Nv;    /* 顶点数 */
  int Ne;    /* 边数   */
  AdjList G; /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

LGraph CreateGraph(
    int VertexNum) { /* 初始化一个有VertexNum个顶点但没有边的图 */
  Vertex V;
  LGraph Graph;

  Graph = (LGraph)malloc(sizeof(struct GNode)); /* 建立图 */
  Graph->Nv = VertexNum;
  Graph->Ne = 0;
  /* 初始化邻接表头指针 */
  /* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
  for (V = 0; V < Graph->Nv; V++) Graph->G[V].FirstEdge = NULL;

  return Graph;
}

void InsertEdge(LGraph Graph, Edge E) {
  PtrToAdjVNode NewNode;

  /* 插入边 <V1, V2> */
  /* 为V2建立新的邻接点 */
  NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
  NewNode->AdjV = E->V2;
  NewNode->Weight = E->Weight;
  /* 将V2插入V1的表头 */
  NewNode->Next = Graph->G[E->V1].FirstEdge;
  Graph->G[E->V1].FirstEdge = NewNode;

  // 这道题需要双向边
  // 不然会需要多做一些操作
  
  /* 若是无向图，还要插入边 <V2, V1> */
  /* 为V1建立新的邻接点 */
  NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
  NewNode->AdjV = E->V1;
  NewNode->Weight = E->Weight;
  /* 将V1插入V2的表头 */
  NewNode->Next = Graph->G[E->V2].FirstEdge;
  Graph->G[E->V2].FirstEdge = NewNode;
}

int Visited[100] = {0};
int jumpLength;          // 跳跃的长度
double jumpFirstLength;  // 第一次跳跃的长度
int crocodileNumber;     // 鳄鱼的数量
bool flag;
float calP2PDistance(int x1, int y1, int x2, int y2) {
  return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

struct crocodilPos {
  int x;
  int y;
};
struct crocodilPos crocodileSum[100] = {0};



void isEscapeSuccess(LGraph LG, int i) {
  PtrToAdjVNode temp = LG->G[i].FirstEdge;
  if (50 - abs(crocodileSum[i].x) <= jumpLength ||
      50 - abs(crocodileSum[i].y) <= jumpLength) {
    printf("Yes");
    flag = true;
    return;
  }
  Visited[i] = 1;
  while (temp) {
    if (flag == true) {
      return;
    }
    int index = temp->AdjV;
    if (Visited[index]!=1) {
      isEscapeSuccess(LG, index);
    }
    temp = temp->Next;
  }
}

int main() {
  flag = false;
  scanf("%d %d", &crocodileNumber, &jumpLength);

  // 输入鳄鱼的坐标

  for (int i = 0; i < crocodileNumber; i++) {
    scanf("%d %d", &crocodileSum[i].x, &crocodileSum[i].y);
  }
  jumpFirstLength = jumpLength + 7.5;

  LGraph LG = CreateGraph(crocodileNumber);
  Edge E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
  /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
  for (int i = 0; i < crocodileNumber; i++) {
    float crocodileDistance;  // 鳄鱼之间的距离

    for (int j = i; j < crocodileNumber; j++) {
      crocodileDistance = calP2PDistance(crocodileSum[i].x, crocodileSum[i].y,
                                         crocodileSum[j].x, crocodileSum[j].y);
      if (crocodileDistance <= jumpLength && crocodileDistance > 0) {
        E->V1 = i;
        E->V2 = j;
        E->Weight = 0;
        InsertEdge(LG, E);
      }
    }
  }
  for (int i = 0; i < crocodileNumber; i++) {
    if (flag == true) {
      break;
    }
      int crocodileDistance;
    crocodileDistance =
        calP2PDistance(crocodileSum[i].x, crocodileSum[i].y, 0, 0);
    if (crocodileDistance <= jumpFirstLength) {
      isEscapeSuccess(LG, i);
     // printf("%d\n",i);
    }
  }
  if (flag == false) {
    printf("No");
  }
  return 0;
}