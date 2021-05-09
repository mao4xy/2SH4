#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	int i;
	for(i=0; i<size; i++)
	{
		//To get the sum of the elements with the same position in the 2 arrays
		vector3[i] = vector1[i]+vector2[i];
	}
	
	
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value
    int i;
	for(i=0; i<size; i++)
	{
		prod += vector1[i]*vector2[i];
	}
    

	
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
	
    
	//write your code here
    //Use the function from math library to get the  square root of the values
    L2 = sqrt(scalar_prod(vector1,vector1,size));
	// you should call function scalar_prod().
	
	//finally, return the L2 norm 
    return L2;
}
