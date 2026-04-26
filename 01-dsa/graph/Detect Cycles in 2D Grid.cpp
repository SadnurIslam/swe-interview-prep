Link:   https://leetcode.com/problems/detect-cycles-in-2d-grid/description/?envType=daily-question&envId=2026-04-26



Strategy: DFS
-> DFS call hobe char dike
-> call korar age check korbo jekhane jassi seta current node er parent kina mane sekhan thekei current node a aschilam kina
-> parent node a abar dfs chalabo na
-> tarpor parent node chara jokhoni kono already visited node pabo tokhoni bujhte parbo cycle ache


Solution: 

class Solution {
public:
    int n, m;
    vector<vector<bool>>vis;
    bool dfs(int i, int j, int p1, int p2, char p, vector<vector<char>>&grid){
        if(i<0 || j<0 || i>=n || j>=m)return false;
        if(grid[i][j]!=p)return false;
        if(vis[i][j])return true;
        vis[i][j] = true;
        bool b = false;
        if(i+1!=p1 || j!=p2)b|=dfs(i+1,j,i,j,p,grid);
        if(i-1!=p1 || j!=p2)b|=dfs(i-1,j,i,j,p,grid);
        if(i!=p1 || j+1!=p2)b|=dfs(i,j+1,i,j,p,grid);
        if(i!=p1 || j-1!=p2)b|=dfs(i,j-1,i,j,p,grid);
        return b;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid[i][j],grid)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};