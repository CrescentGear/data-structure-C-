List Merge(List L1,List L2)
{
	List L,T_L1,T_L2;
	L = malloc(sizeof(struct Node));
	List temp;
	T_L1 = L1->Next;
	T_L2 = L2->Next;
	temp = L;
	while (T_L1 && T_L2)
	{

		if(T_L1->Data <= T_L2->Data)  //L1>L2
		{
			temp->Next = T_L1;
			temp = T_L1;
			T_L1 = T_L1->Next;
		}
		else 
		{
			temp->Next = T_L2;
			temp = T_L2;
			T_L2 = T_L2->Next;
		}
	}
	while (T_L1)
	{
		temp->Next = T_L1;
		temp = T_L1;
		T_L1 = T_L1->Next;

	}
	while(T_L2)
	{
		temp->Next = T_L2;
		temp = T_L2;
		T_L2 = T_L2->Next;
	}
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}
