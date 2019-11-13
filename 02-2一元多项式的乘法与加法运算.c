#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>

/*输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
*/
/*
 系数: coef
 指数：expon
*/

/*指数递降*/

/*输入格式
  总数  系数 指数
  
  第一组序列
  第二组序列

  输出格式
  系数 指数

  乘积
  和
  */

typedef struct Node * List;
List Create_Node();
void Output_Node(List input);
List Add_Node(List input1 , List input2);
List Mul_Node(List input1,  List input2);

struct Node
{
	int coef;
	int expon;
	List next;
};

int main()
{
	List input1, input2,output1,output2;
	input1 = Create_Node();
	input2 = Create_Node();
	output1=Add_Node(input1,input2);
	output2 = Mul_Node(input1,input2);
	Output_Node(output2);
	printf("\n");
	Output_Node(output1);
	//system("pause");
	return 0;
}

List Create_Node()
{

	int n;
	scanf("%d",&n);
	List L,temp1,temp3;
	L = malloc(sizeof(struct Node));
	L->next = NULL;
	temp1 = L;
	int i;
	for (i=0;i<n;i++)
	{
		List temp2;
		temp2 = malloc(sizeof(struct Node));
		scanf(" %d %d", &temp2->coef, &temp2->expon);
		temp1->next= temp2;
		temp1 = temp2;
		temp2->next = NULL;
	}
	temp1->next = NULL;
	//printf("输入完成.\n");
	temp3 = L;
	L = L->next;
	free(temp3);
	return L;
}

void Output_Node(List input)
{
    if (!input)
	{
		printf("0 0");
	}
	while (input)
	{
		printf("%d %d", input->coef, input->expon);
		if (input->next)
		{
			printf(" ");
		}
		input = input->next;
	}
}

List Add_Node(List input1 , List input2)
{
	List input1_temp, input2_temp,L,L_temp,temp3;
	input1_temp = input1;
	input2_temp = input2;
	L = (List)malloc(sizeof(struct Node));
	L->next = NULL;
	L_temp = L;
	while ( input1_temp && input2_temp )
	{
		if (input1_temp->expon>input2_temp->expon) //L1>L2
		{
			List T;
			T = (List)malloc(sizeof(struct Node));
			T->coef = input1_temp->coef;
			T->expon = input1_temp->expon;
			input1_temp=input1_temp->next;
			if(T->coef!=0)
			{
				L_temp->next = T;
				L_temp = T;
			}
				T->next = NULL;
		}
		else if (input1_temp->expon < input2_temp->expon) //L1<L2
		{
			List T;
			T = (List)malloc(sizeof(struct Node));
			T->coef = input2_temp->coef;
			T->expon = input2_temp->expon;
			input2_temp = input2_temp->next;
			if (T->coef != 0)
			{
				L_temp->next = T;
				L_temp = T;
			}
			T->next = NULL;
		}
		else
		{
			List T;
			T = (List)malloc(sizeof(struct Node));
			T->coef = input2_temp->coef + input1_temp->coef;
			T->expon = input2_temp->expon;
			input1_temp = input1_temp->next;
			input2_temp = input2_temp->next;
			if (T->coef != 0)
			{
				L_temp->next = T;
				L_temp = T;
			}
			T->next = NULL;
		}
	}
	while (input1_temp)
	{
		List T;
		T = (List)malloc(sizeof(struct Node));
		T->coef = input1_temp->coef;
		T->expon = input1_temp->expon;
		input1_temp = input1_temp->next;
		L_temp->next = T;
		L_temp = T;
		T->next = NULL;
	}
	while (input2_temp)
	{
		List T;
		T = (List)malloc(sizeof(struct Node));
		T->coef = input2_temp->coef;
		T->expon = input2_temp->expon;
		input2_temp = input2_temp->next;
		L_temp->next = T;
		L_temp = T;
		T->next = NULL;
	}
	temp3 = L;
	L = L->next;
	free(temp3);
	return L;
}

List Mul_Node(List input1, List input2)
{
	List L,L_temp,temp3,input1_temp,input2_temp;
	int j;
	j = 0;
	input1_temp = input1;
	L = (List) malloc(sizeof(struct Node));
	L->next =NULL;
	while (input1_temp)
	{
		List T,T_temp;
		T = (List)malloc(sizeof(struct Node));
		T->next = NULL;
		T_temp = T;
		input2_temp = input2;
		L_temp = L;
		while (input2_temp)
		{
			List Mul_T;
			Mul_T = (List)malloc(sizeof(struct Node));
			Mul_T->coef = input1_temp->coef * input2_temp->coef;
			Mul_T->expon = input1_temp->expon + input2_temp->expon;
			T_temp->next = Mul_T;
			T_temp = Mul_T;
			Mul_T->next = NULL;
			input2_temp = input2_temp->next;
		}
		temp3 = T;
		T = T->next;
		free(temp3);
		if (j==0)
		{
			temp3 = L_temp;
			L_temp = L_temp->next;
			free(temp3);
			j = j + 1;
		}
		L = Add_Node(T,L_temp);
		input1_temp = input1_temp->next;
	}
	return L;
}
