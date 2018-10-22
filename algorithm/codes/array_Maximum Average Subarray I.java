/*
643. Maximum Average Subarray I


Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].

*/


/**
My init solution
*/

public double findMaxAverage(int[] nums, int k) {
    if(nums == null)
        return 0.0;
    if(nums.length<=k){
        int sum = 0;
        for(int i=0; i<nums.length; i++){
            sum += nums[i];
        }
        return 1.0* sum / k;
    }

    double max = 1.0*Integer.MIN_VALUE;
    for(int i=0; i<=nums.length-k; i++){
        int temp = k-1;
        int sum = 0;
        while(temp>=0){
            sum += nums[i+temp--];
        }
        max = Math.max(max, 1.0* sum / k);
    }

    return max;
}


/**
better solution
Approach #1 Cumulative Sum [Accepted]
Time complexity : O(n). We iterate over the numsnums array of length nn once to fill the sumsum array. Then, we iterate over n-kn−k elements of sumsum to determine the required result.
Space complexity : O(n). We make use of a sumsum array of length nn to store the cumulative sum.
*/
public double findMaxAverage(int[] nums, int k) {
		int[] sum = new int[nums.length];
		sum[0] = nums[0];
		for (int i = 1; i < nums.length; i++)
		sum[i] = sum[i - 1] + nums[i];
		double res = sum[k - 1] * 1.0 / k;
		for (int i = k; i < nums.length; i++) {
			res = Math.max(res, (sum[i] - sum[i - k]) * 1.0 / k);  // sum[i]−sum[i−k] to get i's k sum
		}
		return res;
	}
  
/*
Approach #2 Sliding Window [Accepted]
Time complexity : O(n). We iterate over the given numsnums array of length nn once only.
Space complexity : O(1). Constant extra space is used.
*/

public double findMaxAverage(int[] nums, int k) {
    double sum=0;
    for(int i=0;i<k;i++)
        sum+=nums[i];
    double res=sum;
    for(int i=k;i<nums.length;i++){
        sum+=nums[i]-nums[i-k];
            res=Math.max(res,sum);
    }
    return res/k;
}
