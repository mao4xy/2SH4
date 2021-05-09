/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author jianfeng
 */
public class Matrix {
	
	//comment
    
	private int[][]  matrixData;
	private int    rowsNum;	
	private int    colsNum;	
	
	public Matrix( int row, int col ) 
	{   
		/*
		* constructs a row-by-col matrix with
		* all elements equal to 0; if row <= 0, the number of rows of the matrix is set to
		* 3; likewise, if col <= 0 the number of columns of the matrix is set to 3.		
		*/
		//When the number of row is smaller than 1,set it to 3
		if(row<=0) {
			this.rowsNum=3;
		}
		//set the the number of row equal to the input row
		else {
			this.rowsNum=row;
		}
		//When the number of column is smaller than 1,set it to 3
		if(col<=0) {
			this.colsNum=3;
		}
		//set the the number of column equal to the input column
		else {
			this.colsNum=col;
		}
		//use the new int() function to initialize the matrix and set all elements to 0 automatically
		this.matrixData=new int[this.rowsNum][this.colsNum];
		
		
	}

	public Matrix( int[][] table) 
	{	

		/*
		* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
		* element in each position as array table.
		*/ 
		int i,j;
		//use the .length function to get the values of the row number and column number
		this.rowsNum = table.length;
		this.colsNum = table[0].length;
		//use the new int() function to initialize the matrix and set all elements to 0 automatically
		this.matrixData = new int[this.rowsNum][this.colsNum];
		//use for loop to copy each element from the table to matrixData
		for(i=0;i<this.rowsNum;i++) 
			for(j=0;j<this.colsNum;j++) 
				this.matrixData[i][j]=table[i][j];
		
	}
	
	public int getElement(int i, int j) throws IndexOutOfBoundsException
	{ 	
		/*
		* returns the element on row i and column j of this matrix; 
		* it throws an exception (IndexOutOfBoundsException) if any of indexes i and j is not in the required range 
		* (rows and columns indexing starts with 0)
		*  the detail message of the exception should read: "Invalid indexes".
		*/
		//use if to set the correct conditions where i and j are in the required range
		if(i<this.rowsNum&&j<this.colsNum&&i>=0&&j>=0) {
			return this.matrixData[i][j];
		}
		//if the inputs don't satisfy the requirements, the detail message of the exception should read:  "Invalid indexes"
		else
		{
			throw new IndexOutOfBoundsException("Invalid indexes.");
		}
		
	}
        
    public boolean setElement(int x, int i, int j){ 
        
    	//use if to set the correct conditions where i and j are in the required range
    	if(i<this.rowsNum && j<this.colsNum && i>=0 && j>=0)
    	{
    		//reset the element as the input x
    		this.matrixData[i][j] = x;
    		//and return the boolean true
    		return true;
    	}
    	//if the inputs don't satisfy the requirements, return the boolean true
    	else
    		return false;
    } 

    public Matrix copy(){ 
        
    	/* fix the code and write your implementation below */
		/*Matrix copy = new Matrix (0,0);*/
    	//create a new matrix where all element are 0 at first
    	Matrix copy =  new Matrix(this.rowsNum,this.colsNum);
    	int i,j;
    	//use nested for loop to copy the value from the matrixdata to the matrix copy
    	for(i=0;i<this.rowsNum;i++)
    		for(j=0;j<this.colsNum;j++)
    			copy.matrixData[i][j]=this.matrixData[i][j];
		
        return  copy;
    }    
                
	public void addTo( Matrix m ) throws ArithmeticException
	{
		
		/* the detail message of the exception should read: "Invalid operation". */
		//only the matrixes with the same size can be added up together
		if(m.rowsNum==this.rowsNum && m.colsNum==this.colsNum) {
			for(int i=0;i<this.rowsNum;i++)
			{
				for(int j=0;j<this.colsNum;j++)
				{
					//add the two elements with the same position in two matrixes
					this.matrixData[i][j]+=m.matrixData[i][j];
				}
			}
		}
		//if the two matrixes have different sizes, the detail message of the exception should read:  "Invalid operation"
		else
			throw new ArithmeticException("Invalid operation");
		
	
	}
	
    public Matrix subMatrix(int i, int j) throws ArithmeticException{ 
        
		/* The exception detail message should read: "Submatrix not defined"*/
    	
    	/* fix the code and write your implementation below */
    	//use if to set the correct conditions where i and j are in the required range
		if(i>0 && j>0 && i<this.rowsNum && j<this.colsNum)
		{
			//the i and j represent the index of the elements we want, size equal to the index plus one
			Matrix subM = new Matrix (i+1,j+1);
			int x,y;
			//use nested foe loop to copy the value with the same position(up to i and j) from the matrixdata to subM
			for(x=0;x<i+1;x++)
			{
				for(y=0;y<j+1;y++)
				{
					subM.matrixData[x][y]=this.matrixData[x][y];
				}
			}
			return  subM; 
		}
		else
			//if the two matrixes have different sizes, the detail message of the exception should read:  "Submatrix not defined"
			throw new ArithmeticException("Submatrix not defined");
        
    }
        
    public int getsizeofrows(){ 
           
		/* update below return */
    	//get the number of rows
		return this.rowsNum;
    }
        
    public int getsizeofcols(){
		
		/* update below return */
    	//get the number of columns
        return this.colsNum; 
    }
        
    public boolean isUpperTr(){
            
		/* write your implementation here and update return accordingly */
    	for(int i=0;i<this.rowsNum;i++) {
    		for(int j=0;j<this.colsNum;j++) {
    			//when the index of row is smaller than the index of column, the element of the upper triangular matrix must be 0
    			if(i>j) {
    				//if any one of the elements below the diagonal isn't 0, the matrix is not a upper triangular matrix
    				if(this.matrixData[i][j]!=0)
    					return false;
    				
    			}
    		}
    	}
    	//otherwise it's a upper triangular matrix
		return true;
	}
        
    public static Matrix sum(Matrix[] matArray) throws ArithmeticException{
    	
        //create the variable a, b, and c to store the value of the sizes of the three-dimension-matrix    
        int a = matArray.length;
        int b = matArray[0].rowsNum;
        int c = matArray[0].colsNum;
        //set the variable check to check id the sizes of the elements in the matrixes are equal to each other 
        int check=0;
        for(int x=0;x<a-1;x++) {
        	if(matArray[x].rowsNum!=matArray[x+1].rowsNum && matArray[x].colsNum!=matArray[x+1].colsNum)
        		//when the sizes don't satisfy the requirements, check won't be 0
        		check+=1;
        }
       if(check==0) {
    	   //initialize the superMatrix as a b-by-c matrix where all elements are 0
    	   Matrix superMatrix = new Matrix (b,c);
    	   //a is the number of matrix which we should calculate
           for(int i = 0;i<a;i++) {
        	   //use addTo() function to get the sum of two matrix
        	   superMatrix.addTo(matArray[i]);
           }   
           return superMatrix; 
       }
       else
    	 //if the two matrixes have different sizes, the detail message of the exception should read:  "Invalid operation"
    	   throw new ArithmeticException("Invalid operation");
    	   
    }
        
	public String toString(  )
	{
		String output = new String();
		for(int i=0;i<this.rowsNum;i++)
		{
			for(int j=0;j<this.colsNum;j++)
			{
				//take every element in the same row and insert space between every two
				output=output+this.matrixData[i][j]+" ";
			}
			//swtich to another line when to the next row
			output = output+"\n";
		}
        	
		return output;
	}
    
}