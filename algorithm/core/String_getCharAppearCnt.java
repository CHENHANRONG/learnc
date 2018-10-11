/*
统计一个String里所有字母出现的次数。

以都是小写字母为例：

实际问题例子：
https://leetcode.com/problems/group-anagrams/solution/

*/
final int NUM = 26;
int[] count = new int[NUM];
Arrays.fill(count, 0);
for (char c : s.toCharArray()) 
  count[c - 'a']++;
