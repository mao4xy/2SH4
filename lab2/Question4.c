#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	int i,j,k,x;
	//The for loop is to get the elements belong to the string
	for(i=0;word[i]!='\0';i++)
	{
		x = word[i];
		//To get the lower letters whose ASCII values are between 97 and 122
		if(97<=x<=122)
		{
			for(j=97;j<=122;j++)
			{
				//To check what is the ASCII value of the element in this loop
				if(x==j)
				{
					//The indexes of the letters in the freq array should be the ASCII values minus 97
					freq[j-97]+=1;
				}
				else
					//If the ASCII value are not in the range, this element is upper letter
					continue;
			}
		}
		//To get the upper letters whose ASCII values are between 65 and 90
		if(65<=x<=90)
		{
			for(k=65;k<=90;k++)
			{
				//To check what is the ASCII value of the element in this loop
				if(x==k)
				{
					//The indexes of the letters in the freq array should be the ASCII values minus 65
					freq[k-65]+=1;
				}
				else
					//If the ASCII value are not in the range, this element is upper letter, but the lower letters should be operated in the above loop.This is to check the arrary again
					continue;
			}
		}
	}

	

   
}
