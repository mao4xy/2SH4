#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){

	//Set these integers for the use of for loop and indexes
	int i=0,j=0,k=0,s,q,d;
	//The indexes should not be larger than or equal to the size of the array
	while(i<k1&&j<k2)
	{
		//To compare the value of elements in the 2 position arrays
		//The values whose positions are smaller should be in the front of the val3 and pos3 arrays
		if(pos1[i]<pos2[j])
		{
			pos3[k]=pos1[i];
		    val3[k]=val1[i];
		    //When the elements in the pos1 and val1 arrays are chosen and copied, the i should be added 1
			i++;
			//k is the indexes of val3 and pos3 arrays
			k+=1;
		}
		else if(pos1[i]>pos2[j])
		{
			pos3[k]=pos2[j];
		    val3[k]=val2[j];
		    //When the elements in the pos2 and val2 arrays are chosen and copied, the j should be added 1
			j++;
			k+=1;
		}
		//When the elements in the position arrays are equal, that means they are in the same position in the initial vectors, they should be added up together with each other
		 else
		 {
			 //When their sum is not zero
			 if(val1[i]+val2[j]!=0)
			 {
				 //The new value is the sum of the 2 values from the val arrays whose positions are the same
				 pos3[k]=pos1[i];
			     val3[k]=val1[i]+val2[j];
			     k+=1;
			     //The 2 elements can be across after the two elements are added together, so i and j both add 1
			     i++;
			     j++;
			 }
			 //When their sum are 0
			 else
			 {
				 //Ignore the two elements and their positions and across them when their sum is 0
				 i++;
				 j++;
				 continue;
			 }
		 }

	}
	//If we go through the whole elements in the val1 and pos1, but some elements in val2 and pos2 are left
	if(i==k1&&j<k2)
	{
		//The rest elements in val2 can be copied to val3 directly and their positions are equal to the corresponding elements in the pos2
		d=j;
		for(s=d;s<k2;s++)
		{
			pos3[k]=pos2[j];
			val3[k]=val2[j];
			j+=1;
			k+=1;
		}
	}
	//If we go through the whole elements in the val2 and pos2, but some elements in val1 and pos1 are left
	else if(i<k1&&j==k2)
	{
		//The rest elements in val1 can be copied to val3 directly and their positions are equal to the corresponding elements in the pos1
		q=i;
		for(s=q;s<k1;s++)
		{
			pos3[k]=pos1[i];
			val3[k]=val1[i];
			i+=1;
			k+=1;
		}
	}
}
