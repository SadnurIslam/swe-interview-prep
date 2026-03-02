/*
Daily practice problem
link:  https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/?envType=daily-question&envId=2026-03-02

*/



class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), step = 0;
        vector<int>zero(n,0);
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0)cnt++;
                else break;
            }
            zero[i] = cnt;
        }

        for(int i=0;i<n;i++){
            int need = n-i-1;
            int pos = -1;
            for(int j=i;j<n;j++){
                if(zero[j]>=need){
                    pos = j;
                    break;
                }
            }
            if(pos==-1)return -1;
            step += pos-i;
            for(int j=pos;j>i;j--){
                zero[j] = zero[j-1];
            }
        }

        return step;
    }
};