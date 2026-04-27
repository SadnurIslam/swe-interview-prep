Link:   https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/?envType=daily-question&envId=2026-04-27





Strategy: DFS on some conditions
-> proti node theke j dui node a jete parbe, sei node gulao receive korte parbe kina check korte hbe





Solution:

class Solution {
public:
    int m, n;
    vector<vector<bool>>vis;
    pair<int,int> getIn(int val){
        if(val==1)return {-1,1};
        if(val==2)return {-2,2};
        if(val==3)return {-1,2};
        if(val==4)return {1,2};
        if(val==5)return {-1,-2};
        return {1,-2};
    }
  
    void dfs(int i, int j, vector<vector<int>>& grid, int src){
        if(i<0 || j<0 || i>=m || j>=n)return;
        if(vis[i][j])return;
        pair<int,int>pr = getIn(grid[i][j]);
        if(pr.first!=src && pr.second!=src)return;
        vis[i][j] = true;
        if(grid[i][j]==1){
            dfs(i,j+1,grid,-1);
            dfs(i,j-1,grid,1);
        }
        else if(grid[i][j]==2){
            dfs(i+1,j,grid,-2);
            dfs(i-1,j,grid,2);
        }
        else if(grid[i][j]==3){
            dfs(i+1,j,grid,-2);
            dfs(i,j-1,grid,1);
        }
        else if(grid[i][j]==4){
            dfs(i+1,j,grid,-2);
            dfs(i,j+1,grid,-1);
        }
        else if(grid[i][j]==5){
            dfs(i,j-1,grid,1);
            dfs(i-1,j,grid,2);
        }
        else{
            dfs(i,j+1,grid,-1);
            dfs(i-1,j,grid,2);
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n,false));
        pair<int,int>pr = getIn(grid[0][0]);
        dfs(0,0,grid,pr.first);
        return vis[m-1][n-1];
    }
};