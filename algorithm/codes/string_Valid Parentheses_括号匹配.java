/*
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true


*/


/*
My init solution.
思路：利用栈。

对于第i个char，
如过是左边的，则直接押入栈
如果是右边的，1. 如果栈为空，则返回false；2. 如果栈不为空，则判断是否和栈顶原色匹配

*/


    public boolean isValid(String s) {
        if(s==null || s.isEmpty())
            return true;

        Map<Character,Character> mp= new HashMap<Character,Character>();
        mp.put('(',')');
        mp.put('[',']');
        mp.put('{','}');

        Stack<Character> st = new Stack<Character>();
        for(int i=0;i<s.length();i++) {
            char iChar = s.charAt(i);
            boolean isLeftHalf = mp.keySet().contains(iChar);

            if (isLeftHalf) {  //如过是左边的，则直接押入栈
                st.push(iChar);
            } else {  //如果是右边的
                if (st.empty()) {  // 如果栈为空，则返回false；
                    return false;
                } else {  // 如果栈不为空，则判断是否和栈顶原色匹配
                    char peekChar = st.peek();  
                    if (mp.get(peekChar) == iChar) {  //匹配，弹出栈顶元素
                        st.pop();  
                    }else{
                        return false;  //不匹配，返回false；
                    }
                }
            }
        }

        if(st.empty())  //最后如果栈不为空，表明有不匹配顶元素
            return true;
        else
            return false;
    }
