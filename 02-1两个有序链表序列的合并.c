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
/*
 第25行到第41行，其实可以直接写成 
  if(T_L1)
  {
    temp->Next = T_L1;
  }
  else
  {
   temp->Next = T_L2;
  }
  虽然后续操作中 L1->Next = NULL；
  但是原来的链表并没有被释放掉，所以不影响。
*/
