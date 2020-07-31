#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;

struct Node
{
	int data;
	List next;
};

void push_Q(int n, List L); //压入队列
int pop_Q(List L);          //输出队列
List create(int root);      //创造一个队列
int find_root(int number[], int number_left[], int number_right[],int inputnumber);//找根节点
int Is(int number_left[], int number_right[],int i);//判断是不是叶节点

int main()
{
	int  root;
	int number[10];
	int number_left[10];
	int number_right[10];
	int inputnumber;
	int flag;
	List L;
	root = 0;
	flag = 0;
	for (int i = 0; i < 10; i++) //初始化
	{
		number[i] = -1;
		number_left[i] = -1;
		number_right[i] = -1;
	}

	scanf("%d", &inputnumber);
	root = find_root(number,number_left,number_right,inputnumber);
	for (int i = 0; i < inputnumber; i++)
	{
		number[i] = i; //让数组的下标就是数组的值
	}
	int a;
	int tep;
	L = create(root);
	tep = root;
	while (L)
	{
		if (number_left[tep]!=-1)
		{
			push_Q(number_left[tep],L);
		}
	
		if (number_right[tep] != -1)
		{
			push_Q(number_right[tep], L);
		}
		a=Is(number_left, number_right, tep);
		
		if (a!=-1)
		{
			if (flag==0)
			{
				printf("%d",a);
				flag = 1;
			}
			else
			{
				printf(" %d",a);
			}
		}
		L = L->next;
		if(L)
		{
			tep = pop_Q(L);
		}
		
	}
	return 0;
}

int find_root(int number[], int number_left[], int number_right[],int inputnumber)
{
	for (int i = 0; i < inputnumber; i++)
	{
		char left;
		char right;
		int temp;
		scanf(" %c %c", &left, &right);
		if (left != '-')
		{
			temp = left - '0';
			number[temp] = 1;
			number_left[i] = temp;
		}
		if (right != '-')
		{
			temp = right - '0';
			number[temp] = 1;
			number_right[i] = temp;
		}
	}
	for (int i = 0; i < inputnumber; i++)
	{
		if (number[i] == -1)
		{
			return i;
		}	
	}
	return 0;
}
List create(int root)
{
	List L,t,cycle;
	L= (List)malloc(sizeof(struct Node));
	t = L;
	L->next = NULL;
	List temp;
	temp = (List)malloc(sizeof(struct Node));
	temp->data = root;
	temp->next = t->next;
	t->next = temp;
	cycle = L;
	L = L->next;
	free(cycle);
	return L;
}

void push_Q(int n, List L)
{
	List t;
	t = L;
	while (t->next)
	{
		if (t->next)
		{
			t = t->next;
		}
	}
	List temp;
	temp= (List)malloc(sizeof(struct Node));
	temp->data = n;
	temp->next = NULL;
	t->next = temp;
	t = temp;
}

int pop_Q( List L)
{
	int number;
	number =L->data;
	return number;
}

int Is(int number_left[], int number_right[],int i)
{
	if (number_left[i]==-1 && number_right[i] == -1)
	{
		return i;
	}
	return -1;
}
/*
   在压入队列和出队列的时候，如果先出队列，再压入队列，假设队列里只剩下一个元素，那会变成空节点的连接，处理起来需要多加小心。
   而如果先压入队列，再出队列的话，可以解决这个问题。
*/
