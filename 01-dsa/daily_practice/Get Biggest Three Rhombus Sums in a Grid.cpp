/*
Daily practice problem
Link: https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/?envType=daily-question&envId=2026-03-16
*/

/*
strategy:
1. we will iterate over each cell of the grid and for each cell
2. we will calculate the sum of the rhombus with the current cell as the center and k as the size of the rhombus.
3. we will keep track of the top 3 maximum sums in a set and return them at the end.

*/


class Solution {
public:

    int func(int i, int j, int k, int m, int n, vector<vector<int>>&grid){
        int ui=i-k,uj=j,ri=i,rj=j+k,di=i+k,dj=j,lj=j-k,li=i;
        if(ui<0 || rj>=n || di>=m || lj<0)return -1;
        int sum = 0;
        int x=ui,y=uj;
        for(int l=0;l<=50;l++){
            if(x==ri || y==rj)break;
            else{
                sum+=grid[x][y];
                x++;y++;
            }
        }

        x=ri,y=rj;
        for(int l=0;l<=50;l++){
            if(x==ui || y==uj)break;
            else{
                sum+=grid[x][y];
                x++;y--;
            }
        }

        x=di,y=dj;
        for(int l=0;l<=50;l++){
            if(x==li || y==lj)break;
            else{
                sum+=grid[x][y];
                x--;y--;
            }
        }

        x=li,y=lj;
        for(int l=0;l<=50;l++){
            if(x==ui || y==uj)break;
            else{
                sum+=grid[x][y];
                x--;y++;
            }
        }

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int>ans;
        vector<int>fans;
        int m = grid.size(), n = grid[0].size();
        int mn = min(n/2,m/2);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans.insert(-1*grid[i][j]);
                for(int k=1;k<=mn;k++){
                    int cur = func(i,j,k,m,n,grid);
                    if(cur!=-1)ans.insert(-1*cur);
                }
            }
        }
        int sz = 0;
        while(true){
            if(sz>=3 || ans.size()==0)break;
            fans.push_back(-1*(*ans.begin()));
            sz++;
            ans.erase(ans.begin());
        }

        return fans;
    }
};