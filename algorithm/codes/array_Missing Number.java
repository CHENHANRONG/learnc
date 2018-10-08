/*
268. Missing Number


Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

*/



/*
my init solution:
*/

  public int missingNumber(int[] nums) {
        int res=-1;
        int maxVal = nums.length;

        for(int i=0;i<=maxVal;i++){
            for(int j=0;j<nums.length;j++){
                
                if(nums[j] == i){
                    break;
                }
                else if(j==nums.length-1){
                    res = i;
                    i = nums.length;
                    j = maxVal+1;
                }
                    
            }
        }
        
        return res;
       
    }
