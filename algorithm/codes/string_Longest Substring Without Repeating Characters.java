/*
3. Longest Substring Without Repeating Characters


Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
             
             
*/



/*
my init solution:
思路：
遍历Sting， 对于第i个char，
查询在map里有没有出现过，
1. 出现过，并且i不是最后一位char，则重置i到上次出现位置，从后一位开始继续。
2. 没有出现过，max++， 加入map

*/
public int lengthOfLongestSubstring(String s) {
        if(s==null || s.isEmpty())
            return 0;

        //current max
        int max = 0;
        int tempMax = 0;

        //
        Map<Character,Integer> mp = new HashMap<Character, Integer>();

        for(int i=0;i<s.length();i++){
            char ichar = s.charAt(i);
            if(mp.keySet().contains(ichar)){  //already exists
                //update last appear index
                if(i < s.length()-1) {  // if not last char
                    i = mp.get(ichar); //re search from last appear char+1
                    mp.clear();
                    tempMax = 0;  //already appear in previous string, reset tempMax to 0
                }
            }else{
                mp.put(ichar, i);
                max = Math.max(max, ++tempMax);
            }
        }

        return max;

    }
