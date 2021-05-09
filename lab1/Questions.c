
#include "Questions.h"



int Q1_for(){
	int sum;
	// calculate your sum below..this has to use for loop
	int i;
	sum = 0;
	for(i=30; i<=1000; i++)
	{
		if(i%4==0)
		{
			sum+=i;
		}
	}
	// here, we return the calcualted sum:
	return sum;
}
int Q1_while(){
	int sum;
	// calculate your sum below..this has to use while loop
	int i=30;
	sum=0;
	while(i<=1000)
	{
		if(i%4==0)
		{
			sum+=i;
		}
		i++;
	}
	// here, we return the calcualted sum:
	return sum;
}
int Q1_do(){
	int sum;
	// calculate your sum below..this has to use do-while loop
	int i=30;
	sum=0;
	do
	{
		if (i%4==0)
		{
			sum+=i;
		}
		i++;
	}
	while(i<=1000);
	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not


	// Do your coding below to check
	int IsFiveDigit;
	if(Q2_input>=0)
	{
		if(Q2_input>=10000)
		{
			if(Q2_input<=99999)
				IsFiveDigit=1;
			else
				IsFiveDigit=0;
		}
		else
			IsFiveDigit=0;
	}
	else
	{
		if(Q2_input<=-10000)
		{
			if(Q2_input>=-99999)
				IsFiveDigit=1;
			else
				IsFiveDigit=0;
		}
		else
			IsFiveDigit=0;
	}

	



	            
	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and prints:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program should print a message to signal an invalid input.
*/	
	// this is the varaible that holds the out value to return
	float GPA;
	
	
	// Do your coding below to calculate the GPA variable value
	if(Q3_input<0)
		GPA=-1;
	else if (Q3_input>100)
		GPA=-1;
	else
		if(Q3_input>=90)
			GPA=4;
		else
			if(Q3_input>=80)
				GPA=3;
			else
				if(Q3_input>=70)
					GPA=2;
				else
					if(Q3_input>=60)
						GPA=1;
					else
						GPA=0;
	 
	
	
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the varaible that holds the pi value to return
	double pi=0;
	
	
	// Do your coding below to calculate the pi value
	int i;
	double x=4.0;
	for(i=1; i<=Q4_input; i++)
	{
		if(i%2!=0){
			pi+=x/(2*i-1);
		}
		else{
			pi-=x/(2*i-1);
		}
	}

	   
	
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		print each triple on a separate line, 
		and update the total number of triples if needed
	*/
	int side1,side2,side3;
	double hyposide;
	for(side1=1; side1<=400; side1++)
	{
		for(side2=side1; side2<=400; side2++)
		{
			hyposide = sqrt((side1*side1)+(side2*side2));
			side3 = hyposide;
			if(hyposide==side3)
			{
				if(hyposide<=400)
				{
					totNumTribles+=1;
			        //this is the format that you MUST print the found tribles..uncomment this line and fill in the missings to get it working correctly
				    //printf("A trible found: side1=%d, side2=%d, side3=%d\n", side1, side2, side3);
				}
			}
		}
	
	}
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	
	
		//counts is teh variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;
	    int i,j,sumoffactor,index;
	    index=0;
	    for(i=1; i<=Q6_input; i++)
	    {
	        sumoffactor=0;
	    	for(j=1; j<i; j++)
	    	{
	    		if(i%j!=0)
	    		{
	    			continue;
	    		}
	    		else
	    		{
	    			sumoffactor+=j;
	    		}
	    	}
	    	if(sumoffactor==i)
	    	{
                counts+=1;
                perfect[index]=i;
	    	    index+=1;
	    	}

	    }


		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/

	   return counts;

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	int i,j,k,digits,number;
	number=Q7_input;
	j=0;
	for(i=1; i<=7; i++)
	{
		if(number%10==0)
		{
			number/=10;
			j+=1;
			continue;
		}
		else
		{
			j=0;
		}

		digits=number%10;
		number=number/10;
		for(k=1; k<=7-i-j; k++)
		{
			digits*=10;
		}
		reversedInt+=digits;

	}
	return reversedInt;
	
}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	int i,j,k,s,y,digits,number;
	number=Q7b_input;
	s=0;
	for(i=0; i<Q7b_input; i++)
	{
		if(Q7b_input<pow(10,i))
			break;
		j=i+1;
	}
	for(k=1; k<=j; k++)
	{
		if(number%10==0)
		{
			number/=10;
			s+=1;
		    continue;
		}
		else
		{
			s=0;
		}
		digits=number%10;
		number=number/10;
		for(y=1; y<=j-k-s; y++)
		{
			digits*=10;
		}
		reversedInt+=digits;
	}
	return reversedInt;
	
	
}
