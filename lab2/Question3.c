#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){
	//Set some integers for the use of indexes and for loops, f is the index of the result array
	int i,j,k,a,b,c,f=0;
	//Get the elements of the first part of the square array
	for(i=0; i < N3; i++)
	{
		//k is refreshed to 0 in each loop to get the elements in the first column
		k=0;
		//In the first part of the elements, the new elements always start from the elements in the first column
		for(j=i;j>=0;j--)
		{
			//The sequence of the new element is on the right and above the one before untill to the element in the first row
			arr[f]=mat[j][k];
			k+=1;
			f+=1;
		}
	}
	for(a=1;a<N3;a++)
	{
		//The rest elements start from the last rows of the mat array, the c is refreshed to N3-1 which is the index of the last row
		c=N3-1;
		for(b=a;b<N3;b++)
		{
			arr[f]=mat[c][b];
			c-=1;
			f+=1;
		}
	}

	
}
