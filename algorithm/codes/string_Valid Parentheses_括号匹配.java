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


    public boolean isValid(String s) {
        if(s==null || s.isEmpty())
            return true;

        Map<Character,Character> mp= new HashMap<Character,Character>();
        mp.put('(',')');
        mp.put('[',']');
        mp.put('{','}');

        Stack<Character> st = new Stack<Character>();
        for(int i=0;i<s.length();i++){

            if(!st.empty()){
                char peekChar = st.peek();
                
                if(mp.values().contains(peekChar))  // right brack in stack, means not in pair
                    return false;
                
                if(mp.get(peekChar) == s.charAt(i)){
                    st.pop();
                }else{
                    st.push(s.charAt(i));
                }
            }
            else
            {
                st.push(s.charAt(i));
            }



        }

        if(st.empty())
            return true;
        else
            return false;
    }
