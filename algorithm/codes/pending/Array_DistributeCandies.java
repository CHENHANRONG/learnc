package JavaAlgorithm;

import java.util.Arrays;

/**
 * 575. Distribute Candies: Given an integer array with even length, where
 * different numbers in this array represent different kinds of candies. Each
 * number means one candy of the corresponding kind. You need to distribute
 * these candies equally in number to brother and sister. Return the maximum
 * number of kinds of candies the sister could gain.
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


public class Array_DistributeCandies {
    public int distributeCandies(int[] candies) {
        boolean picked[] = new boolean[candies.length];
        Arrays.sort(candies);

        int num = 0;
        int i=1;
        int pickNum=1;
        int remainNum = candies.length;
        while(pickNum<candies.length/2){
            if(i == remainNum){
                // remainNum = cntRemain(picked);
                i = 0;
            }

            if(!picked[i] && candies[i] != candies[i-1]){ // not picked && 
                picked[i] = true;  // set pick to true
                pickNum++;  // pick num++
            }else if(!picked[i] || candies[i] == candies[i-1]){
                i++;
            }

        }
        
    }

    public int cntRemain(boolean arr[]){
        int cnt = 0;
        for(Boolean x : arr){
            if(!x) cnt++; 
        }

        return cnt;
    }
}
