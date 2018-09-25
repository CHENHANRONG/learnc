/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

/* 
Java implement
*/
public int reverse(int x) {
        
        long res = 0;
        while(x !=0){
           int modx = x % 10; 
            x /= 10;
            
            res = res*10+modx;
        }
        if(res > Integer.MAX_VALUE || res < Integer.MIN_VALUE)
            return 0;
        else 
            return (int)res;
    }
    
  /**
     * @param n: the integer to be reversed
     * @return: the reversed integer
     */
    public int reverseInteger(int n) {
        // write your code here
        int result = 0;
        while(n != 0){
            int temp = result * 10 + n%10;
            n /= 10;
            //若*10之后的数再/10得不到原来的数，则说明已经溢出（-2^32~2^32）
            if(temp / 10 != result){
                result = 0;
                break;
            }else{
                result = temp;
            }
        }
        
        return result;
    }   

/* 
C++ implement
*/
