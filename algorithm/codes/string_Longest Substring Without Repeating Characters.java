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
better solutions:
https://leetcode.com/articles/longest-substring-without-repeating-characters/







The naive approach is very straightforward. But it is too slow. So how can we optimize it?

In the naive approaches, we repeatedly check a substring to see if it has duplicate character. But it is unnecessary. If a substring s_{ij}s 
ij
​	
  from index ii to j - 1j−1 is already checked to have no duplicate characters. We only need to check if s[j]s[j] is already in the substring s_{ij}s 
ij
​	
 .

To check if a character is already in the substring, we can scan the substring, which leads to an O(n^2)O(n 
2
 ) algorithm. But we can do better.

By using HashSet as a sliding window, checking if a character in the current can be done in O(1)O(1).

A sliding window is an abstract concept commonly used in array/string problems. A window is a range of elements in the array/string which usually defined by the start and end indices, i.e. [i, j)[i,j) (left-closed, right-open). A sliding window is a window "slides" its two boundaries to the certain direction. For example, if we slide [i, j)[i,j) to the right by 11 element, then it becomes [i+1, j+1)[i+1,j+1) (left-closed, right-open).

Back to our problem. We use HashSet to store the characters in current window [i, j)[i,j) (j = ij=i initially). Then we slide the index jj to the right. If it is not in the HashSet, we slide jj further. Doing so until s[j] is already in the HashSet. At this point, we found the maximum size of substrings without duplicate characters start with index ii. If we do this for all ii, we get our answer.

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
