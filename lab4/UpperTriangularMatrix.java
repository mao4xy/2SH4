/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author jianfeng
 */
public class UpperTriangularMatrix {
    private int n;
    private int[] array;
    
    public UpperTriangularMatrix(int n){
    	//if n>0, the this.n will be n
    	if(n>0) {
    		this.n = n;
    		//the size equals to n*(n+1)/2
    		this.array = new int [(this.n)*(this.n+1)/2];
    	}
    	else {
    		//if n=0, the size will be 1
    		this.n = 1;
    		//initialize the array to a n-by-n matrix where all elements are 0
    		this.array = new int [this.n];
    	}
    	  
    }
    
    public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException{
    	int index=0;
    	//check if the upTriM satisfy the requirements
    	if(upTriM.isUpperTr() && upTriM.getsizeofrows()==upTriM.getsizeofcols()) {
    		//set n equals to the upper triangular matrix's number of rows or columns
    		this.n = upTriM.getsizeofrows();
    		//initialize the array
    		this.array = new int [(this.n)*(this.n+1)/2];
    		//use nested for loop to set the element to the special position
    		for(int i=0;i<upTriM.getsizeofrows();i++)
    		{
    			for(int j=i;j<upTriM.getsizeofcols();j++)
    			{
    				this.array[index]=upTriM.getElement(i, j);
    				//index should plus one every time it record a new element 
    		        index+=1;
    				
    			}
    		}
    	}
    	else
    		//if the matrix is not a upper triangular matrix, print something
    		throw new IllegalArgumentException("Not an upper triangular Matrix");
        
        
    }    
        
    public int getDim(){
        
		
		/* write your implementation here and update return accordingly */
    	//the number of rows should be the n because it's a square matrix
        return this.n; 
    }
    
    public int getElement(int i, int j) throws IndexOutOfBoundsException{
		
		
 		/* write your implementation here and update return accordingly */
    	//check if the upTriM satisfy the requirements
    	if(i>=0 && j>=0 && i<this.n && j<this.n) {
    		int zero_num=0;
    		int index;
    		if(i>j)
    			return 0;
    		else
    			//calculate the number of 0s in the matrix
    			for(int x=0;x<=i;x++)
    			{
    				//the number of 0s in a row equals the rownumber
    				zero_num+=x;
    			}
    		//because there is no 0 in the array, the index in array should be the order in the matrix minus the number of 0s
    		index = i*this.n+j-zero_num;
    		return this.array[index];
    	}
    	
    	else
    		//if the matrix is not a upper triangular matrix, print something
    		throw new IndexOutOfBoundsException("Invalid indexes");
    }
    
    public void setElement(int x, int i, int j) throws IndexOutOfBoundsException,IllegalArgumentException{
    	//check if the upTriM satisfy the requirements
    	if(i>=0 && j>=0 && i<this.n && j<this.n) {
    		int zero_num=0;
    		int index;
    		//when i is bigger than j, all elements should be 0, print something
    		if(i>j)
    			throw new IndexOutOfBoundsException("supposed to be a valid input");
    		else
    			//calculate the number of 0s in the matrix
    			for(int y=0;y<=i;y++)
    			{
    				//the number of 0s in a row equals the rownumber
    				zero_num+=y;
    			}
    		//because there is no 0 in the array, the index in array should be the order in the matrix minus the number of 0s
    		index = i*this.n+j-zero_num;
    		array[index]=x;
    	}
    	
    	else
    		//if the matrix is not a upper triangular matrix, print something
    		throw new IndexOutOfBoundsException("Invalid index");
    }
    
    public Matrix fullMatrix(){

    	//initialize the matrix full to a n-by-n matrix
        Matrix full= new Matrix(n,n); 
        int index = 0;
        for(int i = 0; i < this.n; i++) {
        	for(int j = 0;j<this.n;j++) {
        		if(i<=j) {
        			//when i<=j, copy the values from the array one by one in order 
        			full.setElement(array[index], i, j);
        			//the index should grow
        			index++;
        		}
        		if(i>j)
        			//when i<j, all elements should be 0
        			full.setElement(0, i, j);
        	}
        }
		
        return full; 
    }
    
   
      
    public String toString(){
    	String output = new String();
    	int index = 0;
    	//use nested loop to get the elements to string
    	for(int i=0;i<this.n;i++)
		{
			for(int j=0;j<this.n;j++)
			{
				if(i<=j) {
					//take the nonzero elements one by one and insert space in every two 
					output=output+this.array[index]+" ";
					//the index should grow
				    index++;
				}
				if(i>j)
					//when i<j, all elements should be 0
					output=output+0+" ";
	
			}
			output = output+"\n";
		}
    	return output;
    }
    
    public int getDet(){
		int index,ans=1;
		for(int i=0; i<this.n; i++) {
			for(int j=0; j<this.n; j++) {
				int zero_num=0;
				//when i=j, the element is a diagonal
				if(i==j) {
					for(int x=0;x<=i;x++)
					{
						//the number of 0s in a row equals the rownumber
						zero_num+=x;
					}
					//get the index of the diagonal in the array
					index = i*this.n+j-zero_num;
					//the product of all the diagonals 
					ans*=this.array[index];
				}
			}
		}
        
        
       return ans; 
    }

    
    public double[] effSolve(double[] b) throws IllegalArgumentException{

        /* fix the following and write your implementation */
    	//initialize the sol matrix with n-by-1 elements
    	double[] sol = new double[this.n];
    	double ele,sum;
    	//the index is overflow now but we will minus it below
		int index=this.n*(this.n+1)/2;
		//there is one or more diagonal equal to 0
    	if(getDet()==0)
    	{
    		throw new IllegalArgumentException("The determinant of the matrix is 0");
    	}
    	//the two matrix can be calculated together because of the zie problem
    	else if(b.length!=this.n) {
    		throw new IllegalArgumentException("The dimension of the matrix is not defined for operation");
    	}
    	else
    		//the nested for loop should start with the last element
    		for(int i=this.n-1;i>=0;i--)
    		{
    			sum=0;
    			for(int j=this.n-1;j>=0;j--) {
    				if(j>=i) {
    					//the index should start from the last, and it also be the index of the diagonal in the last of j loop
    					index-=1;
    					//the sum should equal to the product of the elements in the x[j] and matrix[i][j] except when j is the index of diagonal (but j is the umber after the index of diagonal in this row)
    					sum+=sol[j]*this.array[index];
    				}
    			}
    			//b[i]-sum can get the product of the diagonal with the x[i], make this over the diagonal can get the x[i]
    			ele=(b[i]-sum)/this.array[index];
    			//x[i] should equal to ele
    			sol[i]=ele;
    			
    		}
 
        return sol;  
    }   
}