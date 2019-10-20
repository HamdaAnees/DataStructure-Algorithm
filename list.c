/******************************************************************/
/* File Name:  list.c  File Purpose: the following file provides the implementation     
of all the declared functionalities in '.h'       file. */
/******************************************************************/

// File Begin ... 
#include "list.h"
#include <stdlib.h>
#include "fatal.h" 

/* Place in the interface file */
struct Node 
{ 
	ElementType Element;  
	Position    Next; 
};

/* Deleting Junk Data from List */
List MakeEmpty(List L) { 
	if (L != NULL)                 
		DeleteList(L);           
	L = (List)malloc(sizeof(struct Node));     
	if (L == NULL)                
		FatalError("Out of memory!");   
	L->Next = NULL;             
	return L;
}

/* START: fig3_8.txt */       
/* Return true if L is empty */

int         
IsEmpty(List L)
{
	return L->Next == NULL;
} 
/* END */

/* START: fig3_9.txt */     
/* Return true if P is the last position in list L */   
/* Parameter L is unused in this implementation */

int IsLast(Position P, List L)
{ 
	return P->Next == NULL; 
}
/* END */

/* START: fig3_10.txt */    
/* Return Position of X in L; NULL if not found */


/* Function to find aan element from the list */
Position        
Find(ElementType X, List L)
{
	Position P;

	/* 1*/      P = L->Next;
	/* 2*/      while (P != NULL && P->Element != X)
		/* 3*/          P = P->Next;
	/* 4*/      return P;
} /* END */

/* START: fig3_11.txt */     
/* Delete from a list */       
/* Cell pointed to by P->Next is wiped out */       
/* Assume that the position is legal */       
/* Assume use of a header node */

void       
Delete(ElementType X, List L) 
{
	Position P, TmpCell;

	P = FindPrevious(X, L);

	if (!IsLast(P, L)) 
		/* Assumption of header use */
	{                     
		/* X is found; delete it */     
		TmpCell = P->Next;                
		P->Next = TmpCell->Next;  
		/* Bypass deleted cell */     
		free(TmpCell);
	}
}
/* END */

/* START: fig3_12.txt */      
/* If X is not found, then Next field of returned value is NULL */       
/* Assumes a header */

Position        
FindPrevious(ElementType X, List L)
{
	Position P;

	/* 1*/      P = L;
	/* 2*/      while (P->Next != NULL && P->Next->Element != X) 
		/* 3*/          P = P->Next;
	/* 4*/      return P;
} /* END */

/* START: fig3_13.txt */        
/* Insert (after legal position P) */       
/* Header implementation assumed */       
/* Parameter L is unused in this implementation */

void        
Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	/* 1*/      TmpCell = (Position)malloc(sizeof(struct Node));
	/* 2*/      if (TmpCell == NULL) 
		/* 3*/          FatalError("Out of space!!!");
	/* 4*/      TmpCell->Element = X; 
	/* 5*/      TmpCell->Next = P->Next; 
	/* 6*/      P->Next = TmpCell;
} 
/* END */

#if 0 
/* START: fig3_14.txt */      
/* Incorrect DeleteList algorithm */ 

void        
DeleteList(List L) {
	Position P;

	/* 1*/      P = L->Next;  /* Header assumed */
	/* 2*/      L->Next = NULL;
	/* 3*/      while (P != NULL)
	{
		/* 4*/          free(P); 
		/* 5*/          P = P->Next; 
	}
} 
/* END */ 
#endif

/* START: fig3_15.txt */    
/* Correct DeleteList algorithm */

void        
DeleteList(List L)
{
	Position P, Tmp;

	/* 1*/      P = L->Next;  /* Header assumed */ 
	/* 2*/      L->Next = NULL;
	/* 3*/      while (P != NULL) 
	{ 
		/* 4*/          Tmp = P->Next; 
		/* 5*/          free(P);
		/* 6*/          P = Tmp;
	}
} /* END */

Position        
Header(List L)
{
	return L;
}

Position         
First(List L)
{
	return L->Next; 
}

Position        
Advance(Position P)
{
	return P->Next;
}

ElementType         
Retrieve(Position P) 
{ 
	return P->Element;
} 
// File End ... 
