#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){

	int i,x=0;
	//Use for loop to create the val and pos array
	for(i=0;i<size;i++)
	{
		//Select the elements which are not zero and store their value and position in the val and pos array respectively
		if(source[i]!=0)
		{
			//Get the value of the elements which are not0
			val[x]=source[i];
			pos[x]=i;
			x+=1;
		}
		else{
			continue;
		}
	}

}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

    int i,j;
    //Make all elements equal to 0 firstly, and the size of the source array is m
    for(j=0;j<m;j++)
    {
    	source[j]=0;
    }
    for(i=0;i<n;i++)
    {
    	//Change the elements to non-zero number in the source array according to the val and pos array
    	if(val[i]!=0)
    	{
    		//Change the elements whose positions are the elements in the position array to the values which are the elements in the value array. The indexes of positions and values are corresponding
    		source[pos[i]]=val[i];
    	}
    	else
    	{
    		//When the value of elements are 0, the efficient part is over
    		break;
    	}

    }

}
