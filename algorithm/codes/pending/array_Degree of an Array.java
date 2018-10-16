/*
697. Degree of an Array

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/



/*
My init solution:
it is wrong
*/


public int findShortestSubArray(int[] nums) {
    if(nums.length < 2)
        return 1;

    Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
    for(int i=0;i<nums.length-1;i++){
        if(mp.keySet().contains(nums[i])){
            mp.put(nums[i], mp.get(nums[i])+1);
        }else{
            mp.put(nums[i], 1);
        }
    }

    int maxKey = 0;
    for(Integer key : mp.keySet()){
        if(mp.get(key) > maxKey){
            maxKey = key;
        }
    }

    int pre=-1; 
    for(int i=0; i<nums.length-1; i++){
        if(nums[i] == maxKey){
            pre = i;
            break;
        }
    }

    int lat = -1;
    for(int j=nums.length-1; j>=0; j--){
        if(nums[j] == maxKey){
            lat = j;
            break;
        }
    }

    return lat - pre +1;

}

