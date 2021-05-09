#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/
	//set some integers for the use of length variable and index
	int a,b;
	int total_size;
	int i,j,k=0;
	//get the length of the 2 string parameter
	a=strlen(str1);
	b=strlen(str2);
	//the total size should plus 1 because the strlen() function only return the length of the string without the null character, we should add the space of the null character for the combinational string
	total_size=a+b+1;
	//allocate enough bytes for z which can be used to combine str1 and str2
	z=(char*)malloc((total_size)*(sizeof(char)));
	//create a for loop to copy str1 in it first
	for(i=0;i<a;i++)
	{
		z[i]=str1[i];
	}
    //then create another for loop to copy str2 behind str1
	for(j=i;j<total_size;j++)
	{
		z[j]=str2[k];
		k++;
	}
	//add the null character in the last of the new string
	z[total_size]='\0';


	/* finally, return the string*/
	return z;
}

void break_above(char *str3)
{
	free(str3);

}
