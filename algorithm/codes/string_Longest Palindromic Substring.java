/*
5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/



/*
my init solution:
Approach 2: Brute Force
The obvious brute force solution is to pick all possible starting and ending positions for a substring, and verify if it is a palindrome.

Complexity Analysis

Time complexity : O(n^3)
*/

private boolean isPalindromic(String sub){
        for(int m=0, n=sub.length()-1;m<n;m++,n--){
            if(sub.charAt(m)!=sub.charAt(n)){
                return false;
            }
        }
        return true;
    }
    public String longestPalindrome(String s) {
        if(s.length()==1)
            return s;
        
        int max = 0;
        String maxStr="";
        // int mid = s.length()/2;
        for(int i=0;i<s.length()-1;i++){
            for(int j=i+1;j<=s.length();j++){
                String temp = s.substring(i,j);
                if(isPalindromic(temp) && j-i>=max){
                    maxStr = temp;
                    max = Math.max(j-i, max);
                }
            }
        }
        
        return maxStr;
    }
