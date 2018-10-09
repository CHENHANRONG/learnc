
## Important resources
- EXACT STRING MATCHING ALGORITHMS: http://www-igm.univ-mlv.fr/~lecroq/string/


### 所有可能的子串：
- 子集的概念： A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.  
- 一个集合的子集共有the possible 2的n次方种subsequences（一个位置上的值出现和不出现有2种情况，n个位置，共有2的n次方种可能).  
- 基于上一点，可以用编码来表示， 如11100011这样来表示一个子集。





### Sliding window 

- A sliding window is an abstract concept commonly used in array/string problems.   
A window is a range of elements in the array/string which usually defined by the start and end indices, 
i.e. [i, j)[i,j) (left-closed, right-open). 
A sliding window is a window "slides" its two boundaries to the certain direction.  

- 通常用来处理子串问题(Substring related).
