/*
Link: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/?envType=daily-question&envId=2026-03-18
*/

/*
strategy:
1. create a prefix sum 2d array from the beginning of the grid
prefix sum of current index from beginning, prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
where prefix array is 1 indexed and grid is 0 indexed
the idea is to add the sum of the current row and current column and subtract the sum of the previous row and previous column to avoid double counting
*/

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(),cnt=0;
        vector<vector<int>>prefix(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j] = grid[i-1][j-1];
                prefix[i][j]+=prefix[i-1][j];
                prefix[i][j]+=prefix[i][j-1];
                prefix[i][j]-=prefix[i-1][j-1];
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(prefix[i][j]<=k)cnt++;
            }
        }
        return cnt;

    }
};