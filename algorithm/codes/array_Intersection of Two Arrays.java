/*

349. Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.


*/


/*
a little imporve
*/

  public int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> res = new ArrayList<Integer>();

        Set<Integer> mySet = new HashSet<Integer>();
        for(int i=0;i<nums1.length;i++){
            mySet.add(nums1[i]);
        }

        for(int i=0;i<nums2.length;i++){
            if(mySet.contains(nums2[i])){
                res.add(nums2[i]);
                mySet.remove(nums2[i]);  //remove found element in the set
            }
                
            
        }

        int[] resArray = new int[res.size()];
        for(int j=0;j<resArray.length;j++){
            resArray[j] = res.get(j);
        }
        return resArray;

    }

/*
my init solution:
Set has unique value, use it.
*/

  public int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> res = new ArrayList<Integer>();

        Set<Integer> mySet = new HashSet<Integer>();
        for(int i=0;i<nums1.length;i++){
            mySet.add(nums1[i]);
        }

        for(int i=0;i<nums2.length;i++){
            if(mySet.contains(nums2[i]) && !res.contains(nums2[i]))
                res.add(nums2[i]);
        }

        int[] resArray = new int[res.size()];
        for(int j=0;j<resArray.length;j++){
            resArray[j] = res.get(j);
        }
        return resArray;

    }
