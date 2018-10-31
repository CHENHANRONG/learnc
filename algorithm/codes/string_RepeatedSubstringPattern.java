/**
 * 459. Repeated Substring Pattern
 * 
 * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

 */


 /*
 My init solution:
 start from len=1, max len is str.len/2
 for each len, check substring of the s for len interval to see if they are duplicate
 */

public boolean repeatedSubstringPattern(String s) {
    boolean res = false;
    int len= 1;
    while(len<=s.length()/2){
        String cur = s.substring(0, len);
        for(int i=len; i<=s.length()-len; i=i+len){
            if(!s.substring(i, i+len).equals(cur)){
                break;
            }
            
            if(i==s.length()-len){
                res = true;
                len = s.length(); // break outer loop
                break;  //break inner loop
            }
                
        }
        len++;
    }
    
    return res;
}


/*
Amazing solution:
*/
public boolean repeatedSubstringPattern(String str) {
    String s = str + str;
    return s.substring(1, s.length() - 1).contains(str);
}