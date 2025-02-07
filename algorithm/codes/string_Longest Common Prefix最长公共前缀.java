/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

/*
better solution: divide and conqur.
https://leetcode.com/problems/longest-common-prefix/solution/

*/
//TODO



/*
my first solution
*/

    public String longestCommonPrefix(String[] strs) {
        if(strs==null || strs.length==0)
            return "";
        
        for(int i=0;i<strs[0].length();i++){
            String sub_base = strs[0].substring(0,i+1);
            for(int j=1;j<strs.length;j++){
                if(strs[j].length()<sub_base.length() || !strs[j].substring(0,i+1).equals(sub_base)){
                    return sub_base.substring(0, sub_base.length()-1);
                }
            }
        }
        
        return strs[0];
    }
