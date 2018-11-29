package JavaAlgorithm;

import java.util.Arrays;

/**
 * 575. Distribute Candies: Given an integer array with even length, where
 * different numbers in this array represent different kinds of candies. Each
 * number means one candy of the corresponding kind. You need to distribute
 * these candies equally in number to brother and sister. 
 * 
 * Return the maximum number of kinds of candies the sister could gain.
 * 
 * Example 1: Input: candies = [1,1,2,2,3,3] Output: 3 Explanation: There are
 * three different kinds of candies (1, 2 and 3), and two candies for each kind.
 * Optimal distribution: The sister has candies [1,2,3] and the brother has
 * candies [1,2,3], too. The sister has three different kinds of candies.
 * 
 * Example 2: Input: candies = [1,1,2,3] Output: 2 Explanation: For example, the
 * sister has candies [2,3] and the brother has candies [1,1]. The sister has
 * two different kinds of candies, the brother has only one kind of candies.
 * 
 * Note:
 * 
 * The length of the given array is in range [2, 10,000], and will be even. The
 * number in given array is in range [-100,000, 100,000].
 **/


/*
My init solution:
seems too complex
*/

public class Array_DistributeCandies {
    public int distributeCandies(int[] candies) {
        boolean picked[] = new boolean[candies.length];
        Arrays.sort(candies);

        int i=1;
        int sPickedNum = 1;  // sister picked number
        int cur = candies[0];  //current candie
        Set<Integer> sPicked = new HashSet<Integer>();  // sister picked candy kinds
        sPicked.add(candies[0]);


        while(sPickedNum<candies.length/2){
            if(i % candies.length == 0){  //return to the very begining
                cur = Integer.MIN_VALUE;
                i = 0;
            }

            if(picked[i]){  //already picked, then skip
                i++;
            }else{  //not picked
                if(candies[i] == cur){  //same as current, skip
                    i++;
                }else{
                    sPickedNum++;
                    cur = candies[i];
                    picked[i] = true;
                    if(!sPicked.contains(candies[i])){
                        sPicked.add(candies[i]);
                    }
                }
               
            }
        }

        return sPicked.size();
    }
}
