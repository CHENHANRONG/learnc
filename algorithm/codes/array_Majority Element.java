/*
169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/


/*
My init solution:
use hashmap to count elements' appear count.
*/
public int majorityElement(int[] nums) {
    int res = nums[0];
    HashMap<Integer,Integer> mp = new HashMap<Integer, Integer>();
    for(int i=0;i<nums.length;i++){
        if(mp.containsKey(nums[i])){
            int temp = mp.get(nums[i])+1;
            mp.put(nums[i], temp);
            if( nums.length %2 == 0 && temp >= nums.length/2){
                res = nums[i];
                break;
            }else if (nums.length %2 != 0 && temp >= nums.length/2+1){
                res = nums[i];
                break;
            }


        }else{
            mp.put(nums[i], 1);
        }
    }

    return res;


}
