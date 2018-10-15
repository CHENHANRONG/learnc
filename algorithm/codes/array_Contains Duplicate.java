/*
217. Contains Duplicate

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

*/

/*
My init solution:
give a Set, if a[i] already in set, return true;
if not meet already in set, return false;
*/

public boolean containsDuplicate(int[] nums) {
    if(nums==null || nums.length<2)
        return false;

   boolean res = false;
    Set<Integer> ns = new HashSet<Integer>();
    for(int i=0;i<nums.length;i++){
        if(ns.contains(nums[i])){
            res = true;
            break;
        }else{
            ns.add(nums[i]);
        }
    }

    return res;
}
