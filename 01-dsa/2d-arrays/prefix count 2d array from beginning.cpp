/*
Link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/?envType=daily-question&envId=2026-03-19
*/

/*
strategy:
1. create a prefix sum 3d array from the beginning of the grid
prefix sum of current index from beginning, prefix[i][j][0] = grid[i-1][j-1][0] + prefix[i-1][j][0] + prefix[i][j-1][0] - prefix[i-1][j-1][0]
and prefix[i][j][1] = grid[i-1][j-1][1] + prefix[i-1][j][1] + prefix[i][j-1][1] - prefix[i-1][j-1][1]
where prefix array is 1 indexed and grid is 0 indexed and grid[i][j][0] is 1 if grid[i][j] is 'X' and 0 otherwise and grid[i][j][1] is 1 if grid[i][j] is 'Y' and 0 otherwise
the idea is to add the sum of the current row and current column and subtract the sum of the previous row and previous column to avoid double counting
*/

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(),ans=0;
        vector<vector<vector<int>>>prefix(m+1, vector<vector<int>>(n+1,vector<int>(2,0)));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(grid[i-1][j-1]=='X')prefix[i][j][0]=1;
                else if(grid[i-1][j-1]=='Y')prefix[i][j][1]=1;
                prefix[i][j][0]+=prefix[i-1][j][0]+prefix[i][j-1][0]-prefix[i-1][j-1][0];
                prefix[i][j][1]+=prefix[i-1][j][1]+prefix[i][j-1][1]-prefix[i-1][j-1][1];
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(prefix[i][j][0]>0 && prefix[i][j][0]==prefix[i][j][1])ans++;
            }
        }

        return ans;
    }
};