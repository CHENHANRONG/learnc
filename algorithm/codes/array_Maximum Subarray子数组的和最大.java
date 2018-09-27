/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/


/*
My very begining solution:
思路：初始化max和tSum两个变量，max记录最大的子数组tSum值， tSum用来记录阶段的子数组和。
当访问到某个位置i时，
1. 如果tSum +nums[i] >=0， 并且之前的tSum >=0, 则继续，并把tSum += nums[i];
2. 如果tSum +nums[i] >=0， 但是原来tSum<0, 则舍弃原来部分的子数组，并把 tSum 重新初始化为 nums[i];

3. 如果tSum +nums[i] < 0 && tSum < 0, 则tSum = Math.max(tSum,nums[i]);
4. 如果tSum +nums[i] < 0 && tSum > 0, 则舍弃原来部分的子数组，并把 tSum 重新初始化为 nums[i]；
*/

  public int maxSubArray(int[] nums) {
        int preMax = nums[0];  //初始化max为第一个数
        int tSum = nums[0];
        for(int i=1;i<nums.length;i++){

            if(tSum +nums[i] >=0){
                if(tSum <0){
                    tSum = nums[i];
                }else{
                    tSum += nums[i];
                }
            }else{
                if(tSum>=0){
                    tSum = 0;
                }else{
                    tSum = Math.max(tSum,nums[i]);
                }
            }

            preMax = Math.max(preMax, tSum);
        }
        
        return preMax;
    }
