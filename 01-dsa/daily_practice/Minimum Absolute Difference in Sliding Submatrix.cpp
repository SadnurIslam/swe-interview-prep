/*
Daily practice problem
Link: https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/?envType=daily-question&envId=2026-03-20
*/


class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(),i,j,x,y;
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1));
        vector<int>v;
        set<int>st;
        for(i=0;i<m-k+1;i++){
            for(j=0;j<n-k+1;j++){
                for(x=i;x<i+k;x++){
                    for(y=j;y<j+k;y++){
                        v.push_back(grid[x][y]);
                    }
                }
                sort(v.begin(),v.end());
                int sz = v.size();
                int cur = v[sz-1]-v[0];
                for(x=1;x<sz;x++){
                    if(v[x]==v[x-1])continue;
                    cur=min(cur,v[x]-v[x-1]);
                }
                ans[i][j] = cur;
                v.clear();
            }
        }

        return ans;
    }
};