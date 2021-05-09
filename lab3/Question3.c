#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){

	
    char **word_list;

    /*write your implementation here*/
    int i,n;
    //define a string first
    char word[100];
    //open the file and read
    FILE*input_file=fopen(input_filename,"r");
    //get the number of words
    fscanf(input_file,"%d",&n);
    //make the pointer points to the number
    *nPtr=n;
    //allocate the enough space for every word
    word_list=(char**)malloc(n*sizeof(char*));
    for(i=0;i<*nPtr;i++)
    {
    	//get the word from file
    	fscanf(input_file,"%s",word);
    	//use strlen()+1 to get the total length of every word including '\n' and allocate the enough space for each character in a word
    	word_list[i]=(char*)malloc((strlen(word)+1)*sizeof(char));
    	//copy the content of word in to the wordlist
    	strcpy(word_list[i],word);
    }
    //close the file
    fclose(input_file);


    return word_list;

}

int compare_str(const char *str1,const char *str2){

	/*this is a helper function that you can implement and use to facilitate your development*/
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/

	/*write your implementation here and update the return accordingly*/
	int len1,len2;
	int i,j;
	//get the length of the 2 strings without the null character
	len1=strlen(str1);
	len2=strlen(str2);
	//get the minimum length of the 2 strings as the ending index
	if(len1<len2)
	{
		//compare the characters with the same index in the 2 strings
		for(i=0;i<len1;i++)
		{
			//if str1 is smaller, return 0
			if(str1[i]<str2[i])
				return 0;
			//if str2 is smaller, return 1
			if(str1[i]>str2[i])
				return 1;

		}
	}
	else
	{
		for(j=0;j<len2;j++)
		{
			if(str1[j]<str2[j])
				return 0;
			if(str1[j]>str2[j])
				return 1;
		}
	}
	//if they are completely, return -1
	return -1;


    
}

void sort_words(char **words, int size){
   
	/*write your implementation here*/
	//use insertion algorithm here
	char *temp;
	char *temp2;
	int i,j,min_index;
	for(i=0;i<size;i++)
	{
		//find the smallest value from the first one
		//assume the words[i] is smallest
		temp=words[i];
		min_index=i;
		for(j=i+1;j<size;j++)
		{
			//if the temp meet the element which is smaller than it, the new element will be the temp, and the min_index will be its index
			if(compare_str(temp,words[j])==1)
			{
				temp=words[j];
				min_index=j;
			}

		}
		//if the temp is changed, it will swap with the element which changes it
		if(min_index!=i)
		{
			temp2=words[i];
			words[i]=words[min_index];
			words[min_index]=temp2;
		}
	}


}

void swap(char **str1, char **str2){
 
	//define a temporary pointer variable to store the value of *str1
	char *temp;
	temp=*str1;
	//make the *str1 point to *str2 then str1=str2
	*str1=*str2;
	//make the *str2 point to temp which is *str1 then str1=str2
	*str2=temp;

}

void sort2_words(char **words, int size){

   
	/*write your implementation here*/
	int i,j;
	//From the first element, compare every 2 adjacent element
	for(i=0;i<size;i++)
	{
		for(j=1;j<size;j++)
		{
			//use compare the 2 adjacent elements in the words
			if(compare_str(words[j-1],words[j])==1)
			{
				//call swap() function to swap the elements which the first one is larger than the second one
				swap(&words[j-1],&words[j]);
			}
		}
	}


}

void break_q3(char **word_list, int *nPtr)
{
	int i;
	//use for loop to deallocate all subsets of the list
	for(i=0;i<*nPtr;i++)
	{
		free(word_list[i]);
	}
	//finally deallocate the whole list
	free(word_list);
	*nPtr=0;
}
