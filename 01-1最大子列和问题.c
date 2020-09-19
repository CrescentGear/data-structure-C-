//算法2 T(N)=O(N^2)
//其实我写的这个算法已经涉及到了 sum+number[i]<0 这一概念了，这个写法反而比较累赘，官方mooc上的代码更加精简清晰。


//在进行最大值赋值之前，先进行与历史最大值的比较，可以方便最后结果的得出。

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;                    //数组元素个数
    scanf("%d",&n);
    int i=0;
    int number[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&number[i]);
    }
    int sum;
    sum=0;
    int result;
    result=0;
    int j=0;
    while(j<n)
    {
        for(i=j;i<n;i++)
        {
            if(sum+number[i]<0)
            {
                break;
            }
            else
            {
                sum+=number[i];
            }
            if(result<sum)
            {
                result=sum;
            }
        }
        sum=0;
        j=j+1;
    }
    printf("%d",result);
    return 0;
}

/*用链表写法*/
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
	int inputnumber,max,max_1;
	List L,temp;
	scanf("%d",&inputnumber);
	L=Create(inputnumber);
	max = 0;
	max_1 = 0;
	for (int i = 0; i < inputnumber; i++)
	{
		temp = L;
		max_1 += temp->number;
		temp = temp->next;
		if (max_1 < 0)
		{
			max_1 = 0;
		}
		else
		{
			if (max_1 > max)
			{
				max = max_1;
			}
		}
		L = L->next;
	}
	printf("%d",max);
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


//算法 4 ，T(N)=O(N)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;                    //数组元素个数
    scanf("%d",&n);
    int i=0;
    int number[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&number[i]);
    }
    int sum;
    sum=0;
    int result;
    result=0;
        for(i=0;i<n;i++)
        {
            if(sum+number[i]<0)
            {
                sum=0;
            }
            else
            {
                sum+=number[i];
            }
            if(result<sum)
            {
                result=sum;
            }
        }
    printf("%d",result);
    return 0;
}
