/*
Daily practice problem
Link: https://leetcode.com/problems/equal-sum-grid-partition-ii/submissions/1959998937/?envType=daily-question&envId=2026-03-26
*/

/*
Edge cases should be habdled:
1. Single row or single column grid
2. Cut in first or last row/column
3. Cut in middle which make the section disconnected
4. 3x1 or 1x3 matrix
5. Cut the last element of first section in 1xn or mx1 matrix or cut the first element of second section in 1xn or mx1 matrix
*/

#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<ll>row(m+1,0),col(n+1,0);
        map<ll,vector<pair<int,int>>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]].push_back({i,j});
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
            ll f = row[i],s=row[m]-row[i];
            if(f==s)return true;
            if((f-grid[0][0])==s || (f-grid[0][n-1])==s)return true;
            if(f==(s-grid[m-1][0]) || f==(s-grid[m-1][n-1]))return true;
            if(f==(s-grid[i][0]) || f==(s-grid[m-1][0]))return true;
            if(m!=1 && n!=1){
                bool possible = false;
                if(f>s && i>1){
                    ll need = f-s;
                    for(auto ind:mp[need]){
                        if(ind.first<i){
                            possible = true;
                            break;
                        }
                    }
                }
                else if(s>f && i<m-1){
                    ll need = s-f;
                    for(auto ind:mp[need]){
                        if(ind.first>=i){
                            possible = true;
                            break;
                        }
                    }
                }
                if (possible==true) return true;
            }

        }
        for(int i=1;i<n;i++){
            ll f = col[i],s=col[n]-col[i];
            if(f==s)return true;
            if((f-grid[0][0])==s || (f-grid[m-1][0])==s)return true;
            if(f==(s-grid[0][n-1]) || f==(s-grid[m-1][n-1]))return true;
            if(f==(s-grid[0][i]) || f==(s-grid[0][n-1]))return true;
            if(m!=1 && n!=1){
                bool possible = false;
                if(f>s && i>1){
                    int need = f-s;
                    for(auto ind:mp[need]){
                        if(ind.second<i){
                            possible = true;
                            break;
                        }
                    }
                }
                else if(s>f && i<n-1){
                    int need = s-f;
                    for(auto ind:mp[need]){
                        if(ind.second>=i){
                            possible = true;
                            break;
                        }
                    }
                }
                
                if (possible==true) return true;
            }

        }

        return false;
    }
};