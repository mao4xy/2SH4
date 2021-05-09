#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){
	int i,x=0;
	//To get all the elements in the string except the null character
	for(i=0;source[i]!='\0';i++)
	{
		//To get the length of the string in the source array
		x+=1;
	}
	// To compare length of the source array with the length of the destination array
	//If the length of the source array is shorter than the size of the destination
	if(x<n-1)
	{
		//if so, all the elements in the source can be copy and paste to the destination array
		for(i=0;i<x;i++)
		{
			destination[i]=source[i];
		}
		destination[n-1]='\0';
	}
	//If the length of the source array is longer than the size of the destination
	else
	{
		//if so, we should choose the n-1 elements from the source array to copy and paste to the destination array
		for(i=0;i<n-1;i++)
		{
			destination[i]=source[i];
		}
		//The last element of the destination array must be the null character which can make the array be a string
		destination[n-1]='\0';
	}


}
