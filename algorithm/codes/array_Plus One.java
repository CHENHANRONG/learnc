/*

66. Plus One


Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/


/**
better
*/


public int[] plusOne(int[] digits) {
        
  int n = digits.length;
  for(int i=n-1; i>=0; i--) {
      if(digits[i] < 9) {
          digits[i]++;
          return digits;
      }

      digits[i] = 0;
  }

  int[] newNumber = new int [n+1];
  newNumber[0] = 1;

  return newNumber;
}


/*
My init solution:
res[i] = digit[i]+ 进位
*/

public int[] plusOne(int[] digits) {
    if(digits == null)
        return null;

    int res[] = new int[digits.length+1];
    int addStep = 0;
    for(int i=digits.length-1; i>=0; i--){
        if(i==digits.length-1){
            res[i+1] = (digits[i]+addStep+1)%10;
            addStep = (digits[i]+addStep+1)/10;
        }else{
            res[i+1] = (digits[i]+addStep)%10;
            addStep = (digits[i]+addStep)/10;
        }

    }
    res[0] = addStep;


    if(res[0] == 0){
        int finRes[] = new int[digits.length];
        for(int i=1;i<res.length;i++){
            finRes[i-1] = res[i];
        }

        return finRes;
    }else{
        return res;
    }

}
