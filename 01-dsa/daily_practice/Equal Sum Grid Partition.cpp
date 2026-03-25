/*
Daily practice problem
Link: https://leetcode.com/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25
*/

#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<ll>row(m+1,0),col(n+1,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i+1]+=grid[i][j];
                col[j+1]+=grid[i][j];
            }
        }
        for(int i=1;i<=m;i++){
            row[i]+=row[i-1];
        }
        for(int i=1;i<=n;i++){
            col[i]+=col[i-1];
        }
        for(int i=1;i<m;i++){
            if(row[i]==row[m]-row[i])return true;
        }
        for(int i=1;i<n;i++){
            if(col[i]==col[n]-col[i])return true;
        }
        return false;
    }
};