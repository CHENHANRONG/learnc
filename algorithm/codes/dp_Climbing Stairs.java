/*
70. Climbing Stairs


You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

/**
my init solution:
DP:
dp[i] = dp[i-1] + dp[i-2];
*/
public int climbStairs(int n) {
    if(n<2)
        return 1;

    int dp[] = new int[n];
    dp[0] = 1;
    dp[1] = 2;
    for(int i=2;i<n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n-1];

}


other solutions: https://leetcode.com/articles/climbing-stairs/
