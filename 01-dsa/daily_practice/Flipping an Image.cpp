/*
Daily practice problem
Link: https://leetcode.com/problems/flipping-an-image/description/
*/




class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        vector<vector<int>>ans(n,vector<int>(n));
        for(int i=0;i<n;i++){
            int pos = 0;
            for(int j=n-1;j>=0;j--){
                ans[i][pos] = 1-image[i][j];
                pos++;
            }
        }
        return ans;
    }
};