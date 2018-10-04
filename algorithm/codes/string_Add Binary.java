/*

67. Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

*/


  public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();

        int i=a.length()-1;
        int j=b.length()-1;

        int carry = 0;
        while(i>=0 || j>=0){
            int xa = i>=0?a.charAt(i--)-'0':0;
            int xb = j>=0?b.charAt(j--)-'0':0;
            int isum = xa+xb+carry;
            int ix = isum%2;
            sb.insert(0,String.valueOf(ix));
            carry = isum/2;
        }
        if(carry >0){
            sb.insert(0,String.valueOf(carry));
        }

        return sb.toString();
    }
