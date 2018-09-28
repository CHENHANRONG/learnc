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
如果它与栈顶端第括号匹配，则把栈顶端第括号弹出。
如果不匹配，如果是左边半个，则把这个char压栈。
如果是右边半个， 则返回false；


如果栈不为空:
对于第i个char，是右边的部分， 如果不与栈顶元素匹配，则表明不可能配对，返回false
如果可以匹配，则把栈顶端第括号弹出。

如果栈为空：
对于第i个char，是右边的部分，则返回false；
如果是左边半个，则把这个char压栈。
*/


    public boolean isValid(String s) {
        if(s==null || s.isEmpty())
            return true;

        Map<Character,Character> mp= new HashMap<Character,Character>();
        mp.put('(',')');
        mp.put('[',']');
        mp.put('{','}');

        Stack<Character> st = new Stack<Character>();
        for(int i=0;i<s.length();i++){
            char iChar = s.charAt(i);
            boolean isLeftHalf = mp.keySet().contains(iChar);
            if(!st.empty()){
                char peekChar = st.peek();

                if(mp.get(peekChar) == iChar){
                    st.pop();
                }else if(isLeftHalf){
                    st.push(iChar);  //only left half pair could be pushed
                }else{  //if right half pair, return false;
                    return false;
                }
            }
            else
            {
                if(isLeftHalf){
                    st.push(iChar);
                }else{
                    return false;
                }

            }



        }

        if(st.empty())
            return true;
        else
            return false;
    }
