/*

35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0

*/


/*
my init solution:
*/

  private int helper(int []nums, int start, int end,int target){

        if(target<=nums[start])
            return start;
        else if(target>nums[end])
            return end+1;


        while(start<end){
            int mid = start+(end-start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>target)
                return helper(nums, start, mid-1, target);
            else
                return helper(nums, mid+1, end, target);
        }

        return start+1;

    }


    public int searchInsert(int[] nums, int target) {
        //思路：二分查找

        int s = 0;
        int e = nums.length;

        return helper(nums, 0, nums.length-1,target);

    }
