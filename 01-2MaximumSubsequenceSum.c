#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;                    //数组元素个数
	scanf("%d", &n);
	int i = 0;
	int first = 0;
	int last = n-1;
	int final_first = 0;
	int final_last = n - 1;
	int number[10000];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &number[i]);
	}
	int sum,result,ne_flag;
	sum = 0;
	result = 0;
	ne_flag = 0;
	for (i = 0; i < n; i++)
	{

		if (number[i]>0)
		{
			ne_flag = 1;
		}
		if (ne_flag == 0 && number[i]==0)
		{
			ne_flag = 2;
		}
		if (sum + number[i] < 0)
		{
			first = i+1;
			sum = 0;
		}
		else
		{
			last = i;
			sum += number[i];
		}
		if (result < sum)
		{
			final_first = first;
			final_last = last;
			result = sum;
		}
	}
	if (result<0)
	{
		result = 0;
		final_first = 0;
		final_last = n-1;
	}
	if (ne_flag==2)
	{
		printf("0 0 0");
	}
	else
	{
		printf("%d %d %d", result, number[final_first], number[final_last]);
	}
	return 0;
}
/*
   判定点负数和0的意思是所有序列中只有负数与0，并且输出的结果为0 0 0.
   我这里的方法算是一个比较勉强的算法，比较好的算法应该是在final_first和final_last的赋值这块进行优化。
   下面的网址是别人用不一样的赋值思路解决问题的代码，感兴趣的朋友可以看一下。
   http://www.bubuko.com/infodetail-3055362.html
 */

 /*链表算法*/
 #pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;
struct Node
{
	int number;
	List next;
};

List Create(int number);

int main()
{
	int inputnumber,max,max_1,front,rear,flag,front_1;
	List L,temp;
	scanf("%d",&inputnumber);
	L=Create(inputnumber);
	max = -1;
	max_1 = 0;
	front = 0;
	rear = 0;
	flag = 0;
	front_1 = L->number;
	front = L->number;
	for (int i = 0; i < inputnumber; i++)
	{
		temp = L;
		max_1 += temp->number;
		temp = temp->next;
		if (max_1 < 0)
		{
			max_1 = 0;
			flag=1;
		}
		else 
		{
			if (max_1 > max)
			{
				max = max_1;
				front = front_1;
				rear = L->number;
			}
		}
		if (max<0  )
		{
			rear = L->number;
		}
		L = L->next;
		if (flag==1 && L)
		{
			front_1 = L->number;
			flag = 0;
		}
	}
	if (max<0)
	{
		max = 0;
	}
	printf("%d %d %d",max,front,rear);
	return 0;
}

List Create(int number)
{
	List L,t,cycle;
	int i,data;
	L = (List)malloc(sizeof(struct Node));
	L->next = NULL;
	t = L;
	i = 0;
	for (i=0;i<number;i++)
	{
		List temp;
		temp = (List)malloc(sizeof(struct Node));
		scanf("%d",&data);
		temp->number = data;
		t->next = temp;
		t = temp;
	}
	t->next = NULL;
	cycle = L;
	L = L->next;
	free(cycle);
	return L;
}

