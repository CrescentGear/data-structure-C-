#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node * List;

struct Node
{
	int data;
	List next;
};

List Crea_1(int N);
int Is(List L1,List L,int N);

int main()
{
	int N, L;  //N：插入元素的个数  L：序列个数
	scanf("%d %d",&N,&L);
	List L1;
	int result;
	result = 0;
	while (N!=0)
	{
		L1 = Crea_1(N);                //被判断的链表
		for (int i=0;i<L;i++) //L个序列待判断
		{
			List L2;//新建链表
			L2 = Crea_1(N);
			result = Is(L2,L1,N);		//判断是否符合
			if (result==1)  //输出结果
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");  
			}
			
		}

		scanf(" %d",&N);
		if (N!=0)
		{
			scanf(" %d",&L);
		}
	}
	return 0;
}


List Crea_1(int N)
{
	List L, t, cycle;
	L = (List)malloc(sizeof(struct Node));
	L->next = NULL;
	t = L;
	int number;
	int count;
	int user[1025];
	int data[1025];
	for (int i=0;i<1025;i++)
	{
		data[i] = -1;
		user[i] = -1;
	}
	for (int i=0;i<N;i++)
	{
		scanf("%d",&user[i]);
	}
	count = 0;
	for (int i=1;i<1025;i++)
	{
		number = user[count];
		if (i==1)
		{
			data[i] = number;
		}
		else
		{
			if (number<data[i/2])
			{
				if (data[i-1]==-1)
				{
					data[i - 1] = number;
				}
				else
				{
					data[i] = number;
				}
			}
			if(number>data[i/2]&& data[i/2]>0)
			{
				if (i % 2!=0)
				{
					data[i] = number;
				}
				else
				{
					data[i + 1] = number;
				}
			}
		}
		count++;
		if (count>N)
		{
			break;
		}
	}
	for (int i = 1; i < 2048; i++)
	{
		List temp;
		temp = (List)malloc(sizeof(struct Node));
		temp->next = NULL;
		temp->data = data[i];
		t->next = temp;
		t = temp;
	}
	cycle = L;
	L = L->next;
	free(cycle);
	return L;
}


int Is(List L1,List L,int N)
{
	int result,count;
	List t1, t;
	t = L;
	t1 = L1;
	result = 1;
	count = 0;
	while (t)
	{
		if (t->data==t1->data)
		{
			t1 = t1->next;
		}
		else
		{
			return 0;
		}
		t = t->next;
		count++;
		if (count>N)
		{
			break;
		}
	}
	return result;
}
