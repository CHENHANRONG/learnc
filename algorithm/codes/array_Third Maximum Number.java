/**
414. Third Maximum Number


Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

*/

/*
My init solution:
*/
public int thirdMax(int[] nums) {
    //
    Set<Integer> s = new HashSet<Integer>();
    for(int x : nums){
        s.add(x);
    }
    int ns[] = new int[s.size()];

    int i = 0;
    for(int xs : s){
        ns[i++] = xs;
    }

    if(ns.length == 1){
        return ns[0];
    }

    if(ns.length == 2){
        return Math.max(ns[0], ns[1]);
    }

    //length>=3
    Arrays.sort(ns);
    return ns[ns.length-3];
}

/*
other solution
*/
public int thirdMax(int[] nums) {
    Integer max1 = null;
    Integer max2 = null;
    Integer max3 = null;
    for (Integer n : nums) {
        if (n.equals(max1) || n.equals(max2) || n.equals(max3)) continue;
        if (max1 == null || n > max1) {
            max3 = max2;
            max2 = max1;
            max1 = n;
        } else if (max2 == null || n > max2) {
            max3 = max2;
            max2 = n;
        } else if (max3 == null || n > max3) {
            max3 = n;
        }
    }
    return max3 == null ? max1 : max3;
}
