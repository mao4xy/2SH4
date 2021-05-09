#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;
	
	//write your code below
	double sum;
	//The number of rows satisfy the requirement
	int correct=0;
	int i,j;
	for(i=0; i<N2; i++)
	{
		//Set the value of the absolute sum of all the elements except the diagonal one when operating a new row every time
		sum = 0;
		for(j=0; j<N2; j++)
		{
			//Get the absolute sum of all of the elements except the diagonal element
			if(j!=i)
			{
				sum+=fabs(mat[i][j]);
			}
			else
			{
				continue;
			}
		}
		//Check how many rows in the array where the absolute sum of other elements is larger than the absolute value of diagonal element
		if(sum < fabs(mat[i][i]))
		{
			correct+=1;
		}
	}
	//If all absolute diagonal elements are the largest value in their row, the matrix is diagonally dominant.
	if(correct==N2)
		isDiag=1;
	else
		isDiag=0;
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	
	


    return isDiag;
}
