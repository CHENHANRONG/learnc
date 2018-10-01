
/*

125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

*/



/*
My init solution:
思路： 比对开头和结尾的char， 遇到不是数字和字符，则跳过继续。
*/
public boolean isPalindrome(String s) {
        if(s == null)
            return false;
        else if(s.trim().length()<=1)
            return true;

        int i=0;
        int j=s.length()-1;


        while(i<j){
            char ichar = s.charAt(i);
            char jchar = s.charAt(j);

            while(!Character.isLetterOrDigit(ichar) && i<j){  //不是数字和字符，找i的下个字符
                ichar = s.charAt(++i);
            }

            while(!Character.isLetterOrDigit(jchar) && j>i){  //不是数字和字符，找j的前个字符
                  jchar = s.charAt(--j);
            }

            if(Character.toLowerCase(ichar) != Character.toLowerCase(jchar))
                return false;

            i++;
            j--;
        }

        return true;
    }
