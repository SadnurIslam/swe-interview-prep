/*
Daily practice problem
Link: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/?envType=daily-question&envId=2026-04-02
*/


/*
Strategy:
1. Create a 3D dp array where dp[i][j][0] will store the maximum amount of money the robot can earn when it reaches cell (i,j) without using any power-up, dp[i][j][1] will store the maximum amount of money the robot can earn when it reaches cell (i,j) after using one power-up, and dp[i][j][2] will store the maximum amount of money the robot can earn when it reaches cell (i,j) after using two power-ups.
2. Initialize the dp array with a very small value (like -1000000000) to indicate that those states are not reachable.
3. Iterate through the grid and fill the dp array based on the values in the coins grid and the transitions from the previous two states.
4. Finally, return the maximum value among dp[m][n][0], dp[m][n][1], and dp[m][n][2] as the answer.
*/



class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        int dp[m+1][n+1][3];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k] = -1000000000;
                }
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1){
                    dp[i][j][0] = coins[i-1][j-1];
                    dp[i][j][1] = (coins[i-1][j-1]>=0)?coins[i-1][j-1]:0;
                    dp[i][j][2] = (coins[i-1][j-1]>=0)?coins[i-1][j-1]:0;
                    continue;
                }
                if(coins[i-1][j-1]>=0){
                    dp[i][j][0]=max(dp[i][j-1][0],dp[i-1][j][0])+coins[i-1][j-1];
                    dp[i][j][1]=max(dp[i][j-1][1],dp[i-1][j][1])+coins[i-1][j-1];
                    dp[i][j][2]=max(dp[i][j-1][2],dp[i-1][j][2])+coins[i-1][j-1];
                    continue;
                }
                
                int mx = max(dp[i-1][j][0],dp[i][j-1][0]);
                dp[i][j][0]=mx+coins[i-1][j-1];
                int mx1 = max(dp[i-1][j][1],dp[i][j-1][1]);
                if(mx>mx1+coins[i-1][j-1]){
                    dp[i][j][1]=mx;
                }
                else{
                    dp[i][j][1]=mx1+coins[i-1][j-1];
                }
                mx = max(dp[i-1][j][2],dp[i][j-1][2]);
                if(mx+coins[i-1][j-1]>mx1){
                    dp[i][j][2] = mx+coins[i-1][j-1];
                }
                else{
                    dp[i][j][2] = mx1;
                }
            }
        }
       
        
        return max(dp[m][n][0],max(dp[m][n][1],dp[m][n][2]));
    }
};