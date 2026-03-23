/*
Link: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/?envType=daily-question&envId=2026-03-23
*/

/*
strategy:
1. create a dp 3d array where dp[i][j][0] is the maximum non-negative product path from (0,0) to (i,j) 
and 
dp[i][j][1] is the minimum negative product path (which can be maximum later) from (0,0) to (i,j)
2. for each cell (i,j) we can come from (i-1,j)
or (i,j-1) so we will take the maximum of the two paths and the minimum of the two paths and multiply it with the current cell value to get the maximum non-negative product path and minimum negative product path for the current cell
3. at the end we will check the maximum non-negative product path and minimum negative product path
4. if the maximum non-negative product path is negative and minimum negative product path is negative then we will return -1 else we will return the maximum of the two paths
*/

#define ll long long
#define pb push_back
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(),z=0;
        vector<vector<vector<ll>>>dp(m,vector<vector<ll>>(n));
        dp[0][0].pb(grid[0][0]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)z++;
                if(i+j==0)continue;
                vector<ll>tmp;
                if(i>0){
                    for(auto p:dp[i-1][j]){
                        tmp.pb(1LL*grid[i][j]*p);
                    }
                }
                if(j>0){
                    for(auto p:dp[i][j-1]){
                        tmp.pb(1LL*grid[i][j]*p);
                    }
                }
                sort(tmp.begin(),tmp.end(),greater<>());
                ll pos = tmp[0];
                ll neg = tmp[tmp.size()-1];
                if(pos>=0)dp[i][j].pb(pos);
                if(neg<0)dp[i][j].pb(neg);
            }
        }
        ll mx = dp[m-1][n-1][0];
        if(z>0)mx=max(mx,0LL);
        if(dp[m-1][n-1].size()>1)mx=max(mx,dp[m-1][n-1][1]);
        if(mx<0)return -1;
        mx = mx%1000000007;
        return (int)mx;
    }
};