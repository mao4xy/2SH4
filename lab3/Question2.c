#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;


	/*write your implementation here*/
	int n;
	int i;
	//open and read the file first
	FILE*input_file=fopen(filename,"r");
	//get the content of the integer in the first line which represents the number of students
	fscanf(input_file,"%d",&n);
	//make the pointer points to the number of students
	*sizePtr=n;
	//allocate enough space for the class_list to store data
	class_list=(student**)calloc(n,sizeof(student*));
	for(i=0;i<n;i++)
	{
		//the use of calloc() can initialize all storage to 0 first
		class_list[i]=(student*)calloc(6,sizeof(student));
		//store the data of student id, first name, and last name
		fscanf(input_file,"%d" "%s" "%s",&class_list[i]->student_id,class_list[i]->first_name,class_list[i]->last_name);

	}
	//close the file
	fclose(input_file);


	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	
	/*write your implementation here and update the return accordingly*/
	int i;
	for(i=0;i<size;i++)
	{
		//get the index of student's id equals to idNo
		if(list[i]->student_id==idNo)
			return i;
	}

	//if no one's id equals to idNo, return -1
	return -1;
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/
	//x is the id of each student, y is the project1 grade, z is the project2 grade
	int i,x,y,z;
	int position;
	//open the file and read
	FILE*input_file=fopen(filename,"r");
	for(i=0;i<size;i++)
	{
		//assign x, y, and z values from the file, which is id, project1 grade, and project2 grade respectively
		fscanf(input_file,"%d %d %d",&x,&y,&z);
		//use find() to find the index of student id in list
		position = find(x,list,size);
		if(position!=-1)
		{
			//use the index get from above to sort the grades
			list[position]->project1_grade=y;
			list[position]->project2_grade=z;
		}

	}
	//close the file
	fclose(input_file);

}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/
	int i;
	for(i=0;i<size;i++)
	{
		//final grade is the average of the project1 grade and project2 grade, and is a double. So it is obtained by use the sum of 2 grades over 2.0
		list[i]->final_grade=(list[i]->project1_grade + list[i]->project2_grade)/2.0;
	}

}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/
	int i;
	//open the file and get ready to write something
	FILE*output_file=fopen(filename,"w");
	//first pass the number of student to the file
	fprintf(output_file,"%d\n",size);
	//use for loop to operate every line
	for(i=0;i<size;i++)
	{
		//then write the student id and final grade into the file
		fprintf(output_file,"%d ",list[i]->student_id );
		//final grade is a double
		fprintf(output_file,"%lf\n",list[i]->final_grade );
	}
	fclose(output_file);

}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int j;
	//call find() function to get the number and index of students whose id is idNo
	int num_idNo=find(idNo, list, *sizePtr);
	if(num_idNo==-1)
	{
		//when the find() function returns to -1 which means there is no student's id equals to idNo
		printf("No Student's ID equals to %d \n", idNo);
	}
	else
	{
		for(j=num_idNo;j<*sizePtr-1;j++)
	    {
			// because the list includes different types of data, so we need to transfer all kind of data one by one
			list[j]->student_id=list[j+1]->student_id;
			strcpy(list[j]->first_name,list[j+1]->first_name);
			strcpy(list[j]->last_name,list[j+1]->last_name);
			list[j]->project1_grade=list[j+1]->project1_grade;
			list[j]->project2_grade=list[j+1]->project2_grade;
			list[j]->final_grade=list[j+1]->final_grade;
	    }

		//deallocate the storage which at the last
		free(list[*sizePtr-1]);

		//when a pointer is deallocated, the size should minus 1
		(*sizePtr)-=1;
	   }

}
void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	int i;
	//use for loop to deallocate all subsets of the list
	for(i=0;i<*sizePtr;i++)
	{
		free(list[i]);
	}
	//finally deallocate the whole list
	free(list);
	*sizePtr=0;

}
