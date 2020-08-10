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
    /*
    用递归算法的时候，务必不要用新的结点指代形参。
    */
