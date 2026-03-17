/*
Daily practice problem
Link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/?envType=daily-question&envId=2026-03-17
*/

/*
strategy:
1. first we will convert the matrix into a histogram like structure where each cell will contain the number of consecutive 1's above it (including itself).
2. then for each row, we will sort the values in non-decreasing order and calculate the area of the largest rectangle that can be formed with the heights of the current histogram.

*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                if(matrix[i][j]==0)continue;
                matrix[i][j]+=matrix[i-1][j];
            }
        }

        int ans = 0;

        for(int i=0;i<m;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
                if(matrix[i][j]!=0)
                v.push_back(matrix[i][j]);
            }
            sort(v.begin(),v.end());
            int k = v.size();
            for(int j=0;j<v.size();j++){
                ans = max(ans,v[j]*(k-j));
            }
        }

        return ans;
    }
};