BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST)
	{
		BinTree temp;
		temp = (BinTree)malloc(sizeof (struct TNode));
		temp->Left = NULL;
		temp->Right = NULL;
		temp->Data = X;
		return temp;
	}
	else 
	{
		if (X<BST->Data)
		{
			BST->Left = Insert(BST->Left,X);
		}
		else if(X>BST->Data)
		{
			BST->Right = Insert(BST->Right,X);
		}
	}
	return BST;
}


Position FindMin(BinTree BST)
{
	BinTree t;
	t = BST;
	if (t)
	{
	while (t->Left)
	{
		t = t->Left;
	}
	}

	return t;
}

Position FindMax(BinTree BST)
{
	BinTree t;
	t = BST;
	if(t)
	{
		while (t->Right)
	{
		t = t->Right;
	} 
	}
	return t;
}
Position Find(BinTree BST, ElementType X) {
	if (!BST)
	{
		return NULL;
	}
	else if(X>BST->Data)
	{
		return Find(BST->Right,X);
	}
	else if (X<BST->Data)
	{
		return Find(BST->Left,X);
	}
    else
    {
	    return BST;
    }
}
BinTree Delete(BinTree BST, ElementType X) {
	BinTree p;
	if (!BST) {
		printf("Not Found\n");
		return BST;
	}
	if (X < BST->Data) {
		BST->Left = Delete(BST->Left, X);
	}
	else if (X > BST->Data) {
		BST->Right = Delete(BST->Right, X);
	}
	else {
		if (BST->Left && BST->Right) {
			p = FindMax(BST->Left);
			BST->Data = p->Data;
			BST->Left = Delete(BST->Left, BST->Data);
		}
		else {
			p = BST;
			if (!BST->Left) {
				BST = BST->Right;
			}
			else if (!BST->Right) {
				BST = BST->Left;
			}
			free(p);
		}
	}
	return BST;
}
    /*
    用递归算法的时候，务必不要用新的结点指代形参。
    
    */
