#include "tree.h"
#include <stdio.h>
void inorder(SearchTree T);
void postorder(SearchTree T);
void preorder(SearchTree T);
void Sorting(SearchTree T);
void CheckBalance(SearchTree T);
main()
{
	SearchTree T;
	Position P;
	int i;
	int j = 0;
	T = MakeEmpty(NULL);
	printf("Enter Elements:\n");
	int a;
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d ", &a);
		T = Insert(a, T);
	}
	getchar();
	printf("Preorder trasversal in BST:\n");
	preorder(T);
	printf("\nBST in descending order:\n");
	Sorting(T);
	printf("\nCheck if Tree is balanced or not:\n");
	CheckBalance(T);
	getchar();
	return 0;
}
void CheckBalance(T)  /*Check if Tree is Balanced */
{
	int lh, rh;
	lh = heightL(T);  /*Left-height of a BT */ 
	rh = heightR(T); /*Right-height of a BT*/ 
	if ((abs(lh - rh) <= 1))
	{
		printf("Tree is balanced");
		getchar();
	}
	else
	{
		printf("Tree is not balanced");
		getchar();
	}
}
	/*
	printf("Inorder trasversal in BST:\n");
	inorder(T);
	printf("Postorder trasversal in BST:\n");
	postorder(T);
	
	for (i = 0; i < 50; i++)
	{
		if ((P = Find(i, T)) == NULL || Retrieve(P) != i)
			printf("Error at %d\n", i);
	}
	for (i = 0; i < 50; i += 2)
	{
		T = Delete(i, T);
	}
	for (i = 1; i < 50; i += 2)
	{
		if ((P = Find(i, T)) == NULL || Retrieve(P) != i)
			printf("Error at %d\n", i);
	}
	for (i = 0; i < 50; i += 2)
	{
		if ((P = Find(i, T)) != NULL)
			printf("Error at %d\n", i);
	}
	/printf("Min is %d, Max is %d\n", Retrieve(FindMin(T)),Retrieve(FindMax(T)));
	*/
//}
