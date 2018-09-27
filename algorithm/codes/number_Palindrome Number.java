/*
9. Palindrome Number
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/
public boolean isPalindrome(int x) {
        int flag = x<0?-1:1;
        int input = x;
        int res = 0;
         while(x!=0){
             int xpos = x %10;
             x = x/10;
             
             res = res*10+xpos;
         }
        
        if(res*flag == input)
            return true;
        else 
            return false;
    }

/*
方法2: 反转前半部，跟后半部比较是否一样


Following the thoughts based on the second idea, to avoid the overflow issue of the reverted number, what if we only revert half of the \text{int}int number? After all, the reverse of the last half of the palindrome should be the same as the first half of the number, if the number is a palindrome.

For example, if the input is 1221, if we can revert the last part of the number "1221" from "21" to "12", and compare it with the first half of the number "12", since 12 is the same as 12, we know that the number is a palindrome.
*/


//TODO
