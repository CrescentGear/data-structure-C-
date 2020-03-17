#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
	List L;
	ElementType X;
	Position P;

	L = ReadInput();
	scanf("%d", &X);
	P = BinarySearch(L, X);
	printf("%d\n", P);

	return 0;
}

法一：
Position BinarySearch(List L, ElementType X)
{
	int middle = 0;
	int front = 1;
	int last = L->Last;
	middle = (last + front) / 2;
	while(L->Data[middle]!=X)
	{
		if(L->Data[middle] > X)
		{
			last = middle - 1;
		}
		else if (L->Data[middle] < X)
		{
			front = middle + 1;
		}
		middle = (front + last) / 2;
		if(front>=last && L->Data[middle] != X)
		{
			return NotFound;
		}
	}
	return middle;
}

法二：
Position BinarySearch(List L, ElementType X)
{
	int position;
	int i;
	int end;
	int now;
	position = NotFound;
	i = 1;
	end = L->Last;
	now = (i + end) / 2;
	while (i < end)
	{
		if (X == L->Data[now])
		{
			position = now;
			break;
		}
		else if (X > L->Data[now])
		{
			i = now + 1;
			now = (i + end) / 2;
		}
		else
		{
			end = now;
			now = (i + end) / 2;
		}
	}
	if (X == L->Data[now])
	{
		position = now;
	}
	return position;
}


/*可能出现的问题 为什么第50行 是if(front>=last && L->Data[middle] != X)
                          而不是if(front==last && L->Data[middle] != X)
               为什么last = middle - 1
	       而不是last = middle
               为什么第50行判断语句在while（）函数的里面而不是外面。
*/
