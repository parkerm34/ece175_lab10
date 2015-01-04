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

void move_function(int* min, int* array, int traverse,int len, int umm)
{
	if(*(array+traverse)>*min)
		min=array+traverse;
	swap(min, (array+umm));
	while((traverse++)!=len-1)
		move_function(min, array, traverse, len, umm);
}

void search_unsorted(int* min, int* array, int traverse, int len, int go_through_array)
{
	min=(array+traverse);
	move_function(min, array, go_through_array, len, traverse);
	while((traverse++)!=len-1)
		search_unsorted(min, array, traverse, len, go_through_array);
}

int main(void)
{
	int unsorted_array[]={12, 8, 5, 11, 9, 7, 3, -6, 31, 18};
	int *min, i=0, len=10, j=0, k=0;

	printf("Unsorted array: ");
	for(j=0; j<len; j++)
		printf("%d ", unsorted_array[j]);
	search_unsorted(min, unsorted_array, i, len, k);
	printf("\nSorted array: ");
	for(j=0; j<len; j++)
		printf("%d ", unsorted_array[j]);

	return(0);
}
