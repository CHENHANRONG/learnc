
/*
58. Length of Last Word


Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

  public int lengthOfLastWord(String s) {
        s = s.trim();
        String []sub = s.split(" ");
        String last = sub[sub.length-1].trim();
        
        if(last.isEmpty())
            return 0;
        else
            return last.length();
        
    }
