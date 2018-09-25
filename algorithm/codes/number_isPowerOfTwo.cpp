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

/*
解题思路:
如果一个数 n 是 2 的整数幂，那么以二进制表示的话只有一位是 1 ，其余每一位都是 0 ，而 n - 1 则全是 1 ，且比 n 少一位最高位，两者相与为零
*/
    /*
     * @param n: An integer
     * @return: True or false
     */
    public boolean checkPowerOf2(int n) {
        if (n <= 0) {
            return false;
        }

        return (n & (n - 1)) == 0;
    }
