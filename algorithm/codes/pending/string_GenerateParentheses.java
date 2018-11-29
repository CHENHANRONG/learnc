/**
 * 22. Generate Parentheses
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/


/**
My first solution:
从左边第n个（开始， 与）中除最右边一个的）交换，产生的所有排列中合法的部分（hashset）。
*/
