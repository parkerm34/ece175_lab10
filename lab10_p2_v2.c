/*	Author: Parker Mathewson					*
 *	Date: 4/18/12							*
 *	Comments: Using recursion, create a selection sort of a 10 int	*
 *			array. Print out the unsorted and sorted array.	*/

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

void swap(int* a, int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int move_function(int* min, int* array, int traverse,int len, int umm)
{
	if(traverse == 9)return(0);
	else
	{
		if(*(array+traverse)>*min)
			min=array+traverse;
		swap(min, (array+umm));
		traverse+=move_function(min, array, traverse, len, umm);
		return(1);
	}
}

int search_unsorted(int* min, int* array, int traverse, int len, int go_through_array)
{
	if(traverse == 9)return(0);
	else
	{
		min=(array+traverse);
		move_function(min, array, go_through_array, len, traverse);
		traverse+=search_unsorted(min, array, traverse, len, go_through_array);
		return(1);
	}
}

int main(void)
{
	int unsorted_array[]={12, 8, 5, 11, 9, 7, 3, -6, 31, 18};
	int *min, i=0, len=10, j=0, k=0, foo=0;

	printf("Unsorted array: ");
	for(j=0; j<len; j++)
		printf("%d ", unsorted_array[j]);
	foo=search_unsorted(min, unsorted_array, i, len, k);
	printf("\nSorted array: ");
	for(j=0; j<len; j++)
		printf("%d ", unsorted_array[j]);

	return(0);
}
