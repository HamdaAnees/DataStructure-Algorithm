        #include "tree.h"
        #include <stdlib.h>
        #include "fatal.h"
		#define bool int

        struct TreeNode
        {
            ElementType Element;
            SearchTree  Left;
            SearchTree  Right;
        };

/* START: fig4_17.txt */
        SearchTree
        MakeEmpty( SearchTree T )
        {
            if( T != NULL )
            {
                MakeEmpty( T->Left );
                MakeEmpty( T->Right );
                free( T );
            }
            return NULL;
        }
/* END */
/* START: fig4_18.txt */
        Position
        Find( ElementType X, SearchTree T )
        {
            if( T == NULL )
                return NULL;
            if( X < T->Element )
                return Find( X, T->Left );
            else
            if( X > T->Element )
                return Find( X, T->Right );
            else
                return T;
        }
/* END */

/* START: fig4_19.txt */
        Position
        FindMin( SearchTree T )
        {
            if( T == NULL )
                return NULL;
            else
            if( T->Left == NULL )
                return T;
            else
                return FindMin( T->Left );
        }
/* END */

/* START: fig4_20.txt */
        Position
        FindMax( SearchTree T )
        {
            if( T != NULL )
                while( T->Right != NULL )
                    T = T->Right;

            return T;
        }
/* END */

/* START: fig4_22.txt */
        SearchTree
        Insert( ElementType X, SearchTree T )
        {
/* 1*/      if( T == NULL )
            {
                /* Create and return a one-node tree */
/* 2*/          T = malloc( sizeof( struct TreeNode ) );
/* 3*/          if( T == NULL )
/* 4*/              FatalError( "Out of space!!!" );
                else
                {
/* 5*/              T->Element = X;
/* 6*/              T->Left = T->Right = NULL;
                }
            }
            else
/* 7*/      if( X < T->Element )
/* 8*/          T->Left = Insert( X, T->Left );
            else
/* 9*/      if( X > T->Element )
/*10*/          T->Right = Insert( X, T->Right );
            /* Else X is in the tree already; we'll do nothing */

/*11*/      return T;  /* Do not forget this line!! */
        }
/* END */

/* START: fig4_25.txt */
        SearchTree
        Delete( ElementType X, SearchTree T )
        {
            Position TmpCell;

            if( T == NULL )
                Error( "Element not found" );
            else
            if( X < T->Element )  /* Go left */
                T->Left = Delete( X, T->Left );
            else
            if( X > T->Element )  /* Go right */
                T->Right = Delete( X, T->Right );
            else  /* Found element to be deleted */
            if( T->Left && T->Right )  /* Two children */
            {
                /* Replace with smallest in right subtree */
                TmpCell = FindMin( T->Right );
                T->Element = TmpCell->Element;
                T->Right = Delete( T->Element, T->Right );
            }
            else  /* One or zero children */
            {
                TmpCell = T;
                if( T->Left == NULL ) /* Also handles 0 children */
                    T = T->Right;
                else if( T->Right == NULL )
                    T = T->Left;
                free( TmpCell );
            }

            return T;
        }
/* END */

        ElementType
        Retrieve( Position P )
        {
            return P->Element;
        }

		void preorder(SearchTree T)
		{
			if (T == NULL)
			{
				return 0;
			}
			else 
			{
				printf("%d", T->Element);
				preorder(T->Left);
				//recursive function is used to implement traversal techniques
				preorder(T->Right);
			}
		}
		void postorder(SearchTree T)
		{
			if (T == NULL)
			{
				return 0;
			}
			else
			{
				//recursive function is used to implement traversal techniques
				postorder(T->Left);
				postorder(T->Right);
				printf("%d", T->Element);
			}
		}
		void inorder(SearchTree T)
		{
			if (T == NULL)
			{
				return 0;
			}
			else
			{
				//recursive function is used to implement traversal techniques
				inorder(T->Left);
				printf("%d", T->Element);
				inorder(T->Right);
			}
		}
		void Sorting(SearchTree T)
		{
			if (T == NULL)
			{
				return 0;
			}
			else
			{
				//recursive function is used to implement traversal techniques
				inorder(T->Right);
				printf("%d", T->Element);
				inorder(T->Left);
			}
		}

		/* Returns true if binary tree with root as root is height-balanced */
		//bool CheckBalance(SearchTree T)
		//{
		//	int lh; /* for height of left subtree */
		//	int rh; /* for height of right subtree */
		//	lh = height(T->Left);
		//	rh = height(T->Right);
		//	/* If tree is empty then return true */
		//	if (T == NULL)
		//	{
		//		return 2;
		//	}
		//	/* Get the height of left and right sub trees */
		//	if (abs(lh - rh) <= 1 && CheckBalance(T->Left) && CheckBalance(T->Right))
		//	{
		//		return 1;
		//	}
		//	/* If we reach here then tree is not height-balanced */
		//	return 0;
		//}
		//int maxi(int a, int b)
		//{
		//	return (a >= b) ? a : b;
		//}
		///*  The function Compute the "height" of a tree. Height is the
		//	number of nodes along the longest path from the root node
		//	down to the farthest leaf node.*/
		int heightL(SearchTree T)
		{
			int hl = 0;
			T = T->Left;
			while (T != NULL)
			{
				hl++;
				T = T->Left;
			}
			return hl;
		}
		int heightR(SearchTree T)
		{
			int hr = 0;
			T = T->Right;
			while (T != NULL)
			{
				hr++;
				T = T->Right;
			}
			return hr;
		}