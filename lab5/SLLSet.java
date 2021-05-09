
public class SLLSet {
    private int size;
    private SLLNode head;

    public SLLSet() {
    	//To set an empty list, the size must be zero and the content must be null
        size=0;
        head=null;
    }

    public SLLSet(int[] sortedArray) {
    	//To transfer the values from the parameter array to the set, the size of the list must equal to the length of the array
    	int n = sortedArray.length;
    	//Consider that the array is not empty first
        if(n>0) {
        	//the size of the list equal to the length of the input array
        	size = n;
        	//Start from the last element, the link must be null because this is the last element in the list
    	    head = new SLLNode(sortedArray[n-1],null);
    	    //make the head point to the node firstly
    	    SLLNode temp = head;
    	    //use for loop to take the value front one by one
    	    for(int j = n-2; j>=0;j--)
    	    {
    	    	//create the new node whose value is the element in front of the current node and take the head as its link
    	    	temp = new SLLNode(sortedArray[j],head);
    	    	//update the head to point to the node created before
    		    head = temp;
    		    }
    	    }
        //When the array is empty
        else {
        	//The list should be empty too
        	size = 0;
        	head = null;
        }
        
    }

    public int getSize() {
		
    	//get the size
        return size;
    }

    public SLLSet copy() {
    	//create a list named copy
    	SLLSet copy;
    	//take the node named source to get the content from the object
    	SLLNode source = head;
    	//create an array to collect the content in the object
    	int temp[] = new int[size];
    	//use for loop to get the value one by one
        for(int i=0;i<size;i++) {
        	temp[i]=source.value;
        	//get the node next
        	source = source.next;
        }
        //use the method SLLSet(array[]) to convert the array to list
        copy = new SLLSet(temp);

        return copy;
    }

    public boolean isIn(int v) {
    	//use for loop to compare all nodes' values with the input integer
        for(SLLNode here = this.head; here!=null; here=here.next) {
        	//if finding any node equals input, return true
        	if(here.value==v) {
        		return true;
        	}
        }

        //else return false 
        return false;
    }

    public void add(int v) {
    	//check if v is not same with any value of the list, if so, execute the program below, otherwise, do nothing
    	if(isIn(v)==false){
    		//if the object is empty
    		if(this.size==0) {
    			//the only node will have the value of v and the link of null
    			SLLNode temp = new SLLNode(v,null);
    			head = temp;
    			//the size will be 1
    			this.size+=1;
    			return;
    		}
    		else {
    			//the size will plus 1
    			this.size+=1;
    			//create a node which is the first node of the list
    		    SLLNode first = head;
    		    //if the v is smaller thank all nodes in the list
    		    if(first.value>v) {
    		    	//create the node which has the value of v and the link pointing to the origin first node
    		    	SLLNode temp = new SLLNode(v,head);
    		    	//update the head pointing to the new node 
    			    head = temp;
    			    return;
    			    }
    		    //if the value of any one node in the list is larger than v
    		    else {
    		    	for(SLLNode here = this.head; here!=null; here=here.next) {
    		    		//if v is neither the maximum or the minimum in the list, find the position which v should be 
    		    		if(here.next!=null&&here.value<v&&here.next.value>v) {
    		    			//create a node with the value of v and unknown link
    		    			SLLNode temp = new SLLNode(v,null);
    		    			//the link of the new node should be the same with the front node
    			            temp.next=here.next;
    			            //update the link of here pointing to the temp
    			            here.next=temp;
    			            return;
    			            }
    		    		//if v is the maximum in the values of the list
    		    		if(here.next==null&&here.value<v) {
    		    			//the created node will be the last in the list, the link must be null
    		    			SLLNode temp = new SLLNode(v,null);
    		    			//here is the origin last node in the list, correct its link to the created node
    				        here.next = temp;
    				        return;
    				        }
    		    		}
    		    	}
    		    }
    		}
    	}

    public void remove(int v) {
    	//check if v is the same with any value of the list, if so, execute the program below, otherwise, do nothing
    	if(isIn(v)==true) {
    		//first is the first node in the list
    		SLLNode first = head;
    		//if v equals to the value of the fist node
	        if(first.value==v) {
	        	//update the head to the second node directly 
	        	head = first.next;
	        	//the size minus 1
	        	this.size-=1;
	        	return;
	        	}
	        //if size is 2 and v doen't equal the value of the first node
	        else if(this.size==2) {
	        	//delete the last node so the link of the first node should be null
	        	head.next=null;
	        	//the size minus 1
	        	this.size-=1;
	        	return;
	        }
	        else{
	        	//size is larger than 3 and the value of the first node isn't v
	        	for(SLLNode here = this.head; here!=null; here=here.next) {
	        		//select the node whose value equals v
	        		if(here.next.value==v) {
	        			//update the link equals to the link of the next one, skip the middle one
	        			here.next=here.next.next;
	        			//the size should minus 1
	        			this.size-=1;
	        			return;
	        			}
	        		}
	        }
    	}
    }

    public SLLSet union(SLLSet s) {
    	//if the size of the object is larger than 0, we can use for loop
        if(this.size>0) {
        	 for(SLLNode here = this.head; here!=null; here=here.next) {
        		 //use add() method which can ignore the same node and add the different node
        		 s.add(here.value);
        	}
        }
      //if the size of the object is 0, return s directly  
        return s;
    }

    public SLLSet intersection(SLLSet s) {
    	//the intersection will be null either the size of s is 0 or the size of the object is 0
        if(s.size==0||this.size==0) {
        	s = new SLLSet();
        	return s;
        }
        else {
        	//create a list named output
        	SLLSet output=new SLLSet();
            for(SLLNode here = this.head; here!=null; here=here.next) {
            	//check which nodes in s have the same value with that in the object
            	if(s.isIn(here.value)) {
            		//use add() method to add the nodes satisfy the if condition to output
            		output.add(here.value);
            		}
            	}
            return output;
        }

        //return s;
    }

    public SLLSet difference(SLLSet s) {
    	//create an object named output to collect the difference
        SLLSet output = new SLLSet();
        //use for loop to check if all values of nodes in the object are unique in s
        for(SLLNode here = this.head; here!=null; here=here.next) {
        	//use isIn() to check if every value of the object is unique in s
            if(!s.isIn(here.value)) {
            	//if so, use add() to add the node into the list output
            	output.add(here.value);;
           		}
        }
        

        return output;
    }

    public static SLLSet union(SLLSet[] sArray) {
    	//create the an object named ss
        SLLSet ss = new SLLSet();
        //get the size of the array
        int len = sArray.length;
        //use for loop to operate every list in the array
        for(int i = 0; i<len-1;i++) {
        	//use union() method to get all unions of all elements in the array
        	ss=sArray[i].union(sArray[i+1]);
        }

        

        return ss;
    }

    @Override
    public String toString() {
    	//Create the new empty string named output
		String output = new String();
		//create the node named temp
		SLLNode temp;
		//make the node temp equals to the first node of object
		temp = head;
		//check if the size is 0, if not, we can use the for loop. The output will be an empty otherwise
		if(size!=0) {
			for(int i = 0; i<size-1;i++) {
				//take the values with comma and space
				output = output+temp.value+", ";
				//get over to the next node
				temp = temp.next;
			}
			//the last value of temp doesn't need the space and comma
			output = output + temp.value;
    }
        return output;
    }
}
