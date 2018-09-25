/*
1314. Power of Two
Given an integer, write a function to determine if it is a power of two.
*/

    /**
     * @param n: an integer
     * @return: if n is a power of two
     */
    public boolean isPowerOfTwo(int n) {
        // Write your code here
        if(n<=0)
            return false;
        if(n==1)
            return true;
            
        while(n>1){
            if(n % 2 == 1)
                return false;
            
            n>>=1;
        }
        
        return true;
    }
