/*
13/25
测试点 1 2 4 错误
*/
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node *List;

struct Node
{
	int data;
	List next;
};

List Crea();
void Push(int data,List L);
int Pop(List L);
int IsEmp(List L);

int main()
{
	int n;
	scanf("%d", &n);
	char type[31][4];
	int number,flag,count,vol;
	int temp[31];
	int data[31];
	List L;
	L = Crea();
	flag = 0;
	count = 0;
	vol = 0;
	for (int i=0;i<31;i++)
	{
		temp[i] = 0;
		data[i] = 0;
	}
	for (int i = 0; i < 2 * n; i++)
	{
		scanf(" %s", type[i]);
		if (strcoll(type[i], "Push") == 0)
		{
			scanf(" %d",&number);
			Push(number, L);
			temp [i] = 0;
		}
		else
		{
			temp[i] = Pop(L);			
		}
	}
	for (int i=0;i<n*2+1;i++)
	{
		if (flag=0 && temp[i]!=0)
		{
			flag = 1;
		}
		else
		{
			data[count] = temp[i];
			count++;
		}
	}
	L = Crea();
	flag = 0;
	for (int i = 0; i < count + 2; i++)
	{

		if (data[i]!=0 && data[i+1]==0)
		{
			if (flag == 0)
			{
				flag = 1;
			}
			
				if (vol < 2)
				{
					Push(data[i], L);
					vol++;

				}
				else if (vol == 2)
				{
					printf("%d ", Pop(L));
					printf("%d ", Pop(L));
					Push(data[i], L);
					vol = 1;
				}

			
		}
		else if (data[i]!=0)
		{
			printf("%d ",data[i]);
			if (flag == 1)
			{
				printf("%d ",Pop(L));
				vol = 0;
				flag = 2;
			}

		}			if (i == count)
				{
					while (!IsEmp(L))
					{
						printf("%d", Pop(L));
						if (L->next!=NULL)
						{
							printf(" ");
						}
					}

				}
	}

	return 0;
}

List Crea( )
{
	List L;
	L = (List)malloc(sizeof(struct Node));
	L->next = NULL;
	return L;
}

int IsEmp(List L)
{
	if (L->next==NULL)
	{
		return 1;
	}
	return 0;
}

int Pop(List L)
{
	if (IsEmp(L))
	{
		return 0;
	}
	int number;
	List temp;
	temp= L->next;
	number = temp->data;
	L->next = temp->next;
	free(temp);
	return number;
}

void Push(int data, List L)
{
	List temp;
	temp = (List)malloc(sizeof (struct Node));
	temp->data = data;
	temp->next = L->next;
	L->next = temp;
}
