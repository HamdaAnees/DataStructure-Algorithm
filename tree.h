        typedef int ElementType;

/* START: fig4_16.txt */
        #ifndef _Tree_H
        #define _Tree_H
		typedef struct TreeNode *Position;
        typedef struct TreeNode *SearchTree;
        SearchTree MakeEmpty( SearchTree T );
        Position Find( ElementType X, SearchTree T );
        Position FindMin( SearchTree T );
        Position FindMax( SearchTree T );
        SearchTree Insert( ElementType X, SearchTree T );
        SearchTree Delete( ElementType X, SearchTree T );
        ElementType Retrieve( Position P );
		
		void inorder(SearchTree T);
		void postorder(SearchTree T);
		void preorder(SearchTree T);
		void Sorting(SearchTree T); /*Returns decreasing-order of a binary tree */
		int heightL(SearchTree T);  /*Returns the Left-height of a binary tree */ 
		int heightR(SearchTree T);/*Returns the Right-height of a binary tree */
		            

        #endif  /* _Tree_H */

/* END */
