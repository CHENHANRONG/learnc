/*
521. Longest Uncommon Subsequence I

Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc"
Output: 3
Explanation: The longest uncommon subsequence is "aba" (or "cdc"), 
because "aba" is a subsequence of "aba", 
but not a subsequence of any other strings in the group of two strings. 
Note:

1. Both strings' lengths will not exceed 100.
2. Only letters from a ~ z will appear in input strings.

*/

/*
My init solution:
start from longer string's longest substring, and check against shorter one, 
if shorter one has substring same as longer one's substring

*/
  public int findLUSlength(String a, String b) {
        int res = -1;
        String longerStr = "";
        String shorterStr = "";
        if(a.length()>=b.length()){
            longerStr = a;
            shorterStr = b;
        }else{
            longerStr = b;
            shorterStr = a;
        }



        int i=0;
        int j=longerStr.length();
        while(i<j){
            String rs = longerStr.substring(i, j);  //from left to right-1
            
            if(shorterStr.indexOf(rs) == -1)
                res = Math.max(res, j-i);
            
            i++;  //left++
            String ls = longerStr.substring(i, j);  //from left+1 to right
            if(shorterStr.indexOf(ls)==-1)
                res = Math.max(res, j-i);
            
            j--;  //right--
        }

        return res;
    }
