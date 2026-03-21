/*
Daily practice problem
Link: https://leetcode.com/problems/flip-square-submatrix-vertically/?envType=daily-question&envId=2026-03-21
*/




class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>>ans = grid;
        int pos = x;
        for(int i=x+k-1;i>=x;i--){
            for(int j=y;j<y+k;j++){
                ans[pos][j] = grid[i][j];
            }
            pos++;
        }
        return ans;
    }
};