/*	Author: Parker Mathewson					*
 *	Date: 4/18/12							*
 *	Comments: This is a program to help us practice using structs	*
 *			and linked lists. We will then print out in	*
 *			reverse.					*/

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

typedef struct node_s
{
	int data;
	struct node_s* next;
} node_t;

void print_function(node_t* pt)
{
	if(pt->next == NULL)
; //printf("%d ", pt->data);
	else
	{
	print_function(pt->next);
	printf("%d ", pt->data);
	}
}

int main(void)
{
	int data_insert = 0;
	node_t *headp, *temp, *current=NULL;

	for(data_insert = 0; data_insert < 5; data_insert++)
	{
		temp =(node_t*)malloc(sizeof(node_t));
		temp->data=data_insert;
		temp->next = NULL;

		if(current == NULL) headp=temp;
		else current->next=temp;
		current = temp;
	}

	print_function(headp);

	return(0);
}
