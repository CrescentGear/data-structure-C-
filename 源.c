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
	Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
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

//���ܳ��ֵ����� fornt==last return notfound
//              middle-1
//              �ж������returnǰ�棬while����