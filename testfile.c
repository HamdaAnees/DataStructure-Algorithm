

/******************************************************************/ 
/* File Name:  testlist.c  File Purpose: this file has implementation of the main method   
for the lists ... */ 
/******************************************************************/
/*
// File Start ..
#include <stdio.h>
#include <conio.h>
#include "list.h" 
#include<stdlib.h>        
#include <ctype.h>

void PrintList(const List L) 
{
	Position P = Header(L);    
	if (IsEmpty(L))        
		printf("Empty list\n");   
	else {
		do { 
			P = Advance(P);            
			printf("%d ", Retrieve(P));
		} while (!IsLast(P, L));    
		printf("\n");
	}
}

int pr(char symbol);

int main() {  
	// Declaring the List object and its Pointer ...  
	List L;    
	Position P;   
	int i; //  Initializing the declared List object and pointing its  pointer towards the header of that List ... //   
	L = MakeEmpty( NULL );   
	P = Header( L );   
	PrintList( L );


	char infix[50];
	printf("Enter Infix Expression:\n");
	scanf_s("%s", infix);



	int pr(char symbol)   // Function for precedence 
	{                 
		if (symbol == '^')// exponent operator, highest precedence
		{
			return(3);
		}
		else if (symbol == '*' || symbol == '/')
		{
			return(2);
		}
		else if (symbol == '+' || symbol == '-')          // lowest precedence 
		{
			return(1);
		}
		else
		{
			return(0);
		}
	}
	getchar();    
	return 0;
}
// File End ... 

*/

#include<stdio.h>
#include<stdlib.h>

char op[50];

struct node
{
	char data;
	struct node *next;
} *l1 = NULL;

void push(char x)         // pushes char into the linkedlist
{
	if (l1 == NULL)
	{
		l1 = (struct node *)malloc(sizeof(struct node));
		l1->data = x;
		l1->next = NULL;
	}
	else
	{
		struct node *p;
		p = (struct node *)malloc(sizeof(struct node));
		p->data = x;
		p->next = l1;
		l1 = p;
	}
}

char pop()           // pops char outof linkedlist
{
	char c;
	struct node *p;
	if (l1 == NULL)
	{
		printf("the stack is empty\n");
		// exit(1);
	}
	else
	{
		c = l1->data;
		p = l1->next;
		free(l1);
		l1 = p;
	}
	return c;
}

void display(struct node *start)
{
	{
		//int i=0;
		struct node *p;
		p = start;
		if (p == NULL)
			printf("Empty list");
		else
		{
			while (p != NULL)
			{
				printf("%c->", p->data);
				p = p->next;
			}
			printf("NULL\n");
		}
	}
}


int prior(char s, char c)
{
	if ((c == '^' && s == '+') || s == '-' || s == '/' || s == '*')
		return 1;
	else if (c == '*' || c == '/')
	{
		if (s == '+' || s == '-')
			return 1;
		else
			return 0;
	}
	else if (c == '+' || c == '-')
		return 0;
	return -1;
}

void cnvrt(char s[], int n)       // convert infix to postfix
{
	//char g;
	int i, j;//,x;
	for (i = 0, j = 0; i < n; i++)
	{

		if ((s[i] >= '0'&&s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			op[j] = s[i];
			j++;
		}
		else if (s[i] == '(')
		{
			push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '/' || s[i] == '-' || s[i] == '*' || s[i] == '^')
		{

			if (l1 == NULL)
				push(s[i]);
			else if (l1->data == '(')
				push(s[i]);
			else if (prior(l1->data, s[i]) != 1)
				push(s[i]);
			else
				op[j] = pop();
				j++;
				push(s[i]);
			}
		}
		else if (s[i] == ')')
		{
			while (l1 != NULL && l1->data != '(')
			{
				op[j] = pop();
				j++;
			}
			pop();
		}
		else 
			break;
	}
	while (l1 != NULL)
	{
		op[j] = pop();
		j++;
	}
}


int main()
{
	int i, n;
	char c[50];
	printf(" enter the no of characters in infix string\n ");
	scanf("%d", &n);
	printf(" enter the infix string\n");
	//for(i=0;i<n;i++)
	scanf("%s", c);

	cnvrt(c, n);
	printf("the postfix string is \n");
	for (i = 0; i < n; i++)
	{
		printf("%c", op[i]);
	}

	return 0;
}