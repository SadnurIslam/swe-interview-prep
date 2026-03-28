/*
Daily practice problem
Link: https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description



class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>tmp = mat;
        int m = mat.size(),n=mat[0].size();
        while(k--){
            for(int i=0;i<m;i++){
                if(i%2==0){
                    int f =tmp[i][0];
                    for(int j=0;j<n-1;j++){
                        tmp[i][j] = tmp[i][j+1];
                    }
                    tmp[i][n-1] = f;
                }
                else{
                    int l =tmp[i][n-1];
                    for(int j=n-1;j>=1;j--){
                        tmp[i][j] = tmp[i][j-1];
                    }
                    tmp[i][0] = l;
                }
                
            }
        }
        return mat==tmp;
    }
};