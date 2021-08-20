//参考了https://blog.csdn.net/m0_37149062/article/details/105641639的代码
//我判断是否是哈夫曼树的代码写的不是特别清晰，我上文贴的链接里的解法会更清晰一点。
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MIN -1000
#define MaxSize 64

typedef struct TreeNode* HuffmanTree;
typedef struct HNode* Heap;

struct HNode
{
    HuffmanTree data[MaxSize];
    int size;
    int capacity;
};

struct TreeNode
{
    int weight;
    HuffmanTree Left, Right;
};

int a[MaxSize];
char codes[65];

bool IsFull(Heap H)
{
    return (H->size == H->capacity);
}
bool IsEmpty(Heap H)
{
    return (H->size == 0);
}
Heap BuildHeap(int N) //最小堆初始化   
{
    Heap H = (Heap)malloc(sizeof(struct HNode));
    H->data[0] = (HuffmanTree)malloc(sizeof(struct TreeNode));
    H->size = 0;
    H->capacity = MaxSize;
    H->data[0]->Left = NULL;
    H->data[0]->Right = NULL;
    H->data[0]->weight = -100;
    return H;
}
void PercDown(Heap H, int k) //下滤调整为最小堆
{
    int Parent, Child;
    HuffmanTree x;
    x = H->data[k];
    for (Parent = k; Parent * 2 <= H->capacity; Parent = Child)
    {
        Child = Parent * 2;
        if ((Child < H->size) && H->data[Child]->weight > H->data[Child + 1]->weight)
        {
            Child++;
        }
        if (x->weight <= H->data[Child]->weight)
        {
            break;
        }
        else
            H->data[Parent] = H->data[Child];
    }
    H->data[Parent] = x;
}
void BuildMinHeap(Heap H) //构建最小堆
{
    for (int i = H->size / 2; i > 0; i--)
    {
        PercDown(H, i);
    }
}
bool Insert(Heap H, HuffmanTree X)
{

    int i;
    if (IsFull(H))
        return 0;
    H->size++;
    for (i = H->size; H->data[i / 2]->weight > X->weight; i /= 2)
    {
        H->data[i] = H->data[i / 2];
    }
    H->data[i] = X;
    return 1;
}
HuffmanTree DeleteMinHeap(Heap H)
{
    HuffmanTree X;
    int Parent, Child;
    if (IsEmpty(H))
    {
        return NULL;
    }
    HuffmanTree Min = H->data[1];
    X = H->data[H->size];
    H->size--;
    for (Parent = 1; Parent * 2 <= H->size; Parent = Child)
    {
        Child = Parent * 2;
        if ((Child < H->size) && H->data[Child]->weight > H->data[Child + 1]->weight)
        {
            Child++;
        }
        if (X->weight <= H->data[Child]->weight)
        {
            break;
        }
        else
        {
            H->data[Parent] = H->data[Child];
        }
    }
    H->data[Parent] = X;
    return Min;
}

HuffmanTree CreatHuffman()
{
    HuffmanTree  T;
    T = (HuffmanTree)malloc(sizeof(struct TreeNode));
    T->Left = T->Right = NULL;
    T->weight = 0;
    return T;
}

HuffmanTree Huffman(Heap H)
{
    int i;
    HuffmanTree T;
    int S = H->size;
    for (i = 1; i < S; i++)
    {
        T = (HuffmanTree)malloc(sizeof(struct TreeNode));
        T->Left = DeleteMinHeap(H);
        T->Right = DeleteMinHeap(H);
        T->weight = 0;
        T->weight = T->Left->weight + T->Right->weight;
        Insert(H, T);
    }
    T = DeleteMinHeap(H);
    return T;
}

int WPL(HuffmanTree T, int depth)
{
    if (T->Left == NULL && T->Right == NULL)
    {
        return depth * T->weight;
    }
    else
    {
        depth++;
        return WPL(T->Left, depth) + WPL(T->Right, depth);
    }
}

int solve(int length, int N)
{
    char a1[MaxSize];
    char codes1[65];
    int flag = 1;
    Heap H = BuildHeap(N);
    HuffmanTree T, t;
    int length2;
    length2 = 0;
    t = (HuffmanTree)malloc(sizeof(struct TreeNode));
    t->Left = NULL;
    t->Right = NULL;
    t->weight = 0;
    T = t;
    for (int i = 0; i < N; i++)
    {
        scanf(" %c %s", &codes1, &a1);
        int j = 0;
        t = T;
        for (j; j < strlen(a1); j++)
        {
            HuffmanTree temp = (HuffmanTree)malloc(sizeof(struct TreeNode));
            temp->Left = NULL;
            temp->Right = NULL;
            temp->weight = 0;
            if (a1[j] == '0')
            {
                if (t->Left == NULL)
                {
                    t->Left = temp;
                }
                t->weight += t->Left->weight;
                t = t->Left;
            }
            else if (a1[j] == '1')
            {
                if (t->Right == NULL)
                {
                    t->Right = temp;
                }
                t->weight += t->Right->weight;
                t = t->Right;
            }
            if (j == strlen(a1) - 1 && t->weight != 0)
            {
                flag = 0;
            }
            if (j == strlen(a1) - 1)
            {
                t->weight = a[i];
                length2 += (j + 1) * a[i];
            }
            else
            {
                t->weight = 0;
            }
            if (j == strlen(a1) - 1 && (t->Left || t->Right) || flag == 0)
            {
                flag = 0;
                break;
            }

        }
    }
    if (length2 != length)
    {
        flag = 0;
    }
    return flag;
}

int main()
{
    int N;
    int flag;
    scanf("%d", &N);
    Heap H = BuildHeap(N);
    for (int i = 0; i < N; i++)
    {
        getchar();
        scanf("%c %d", &codes[i], &a[i]);
        HuffmanTree temp = (HuffmanTree)malloc(sizeof(struct TreeNode));
        temp->Left = NULL;
        temp->Right = NULL;
        temp->weight = a[i];
        Insert(H, temp);
    }
    int length;
    HuffmanTree T = Huffman(H);
    length = WPL(T, 0);
    int N2;
    scanf("%d", &N2);
    getchar();
    flag = 1;
    for (int i = 0; i < N2; i++)
    {
        flag = solve(length, N);
        if (flag == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}


