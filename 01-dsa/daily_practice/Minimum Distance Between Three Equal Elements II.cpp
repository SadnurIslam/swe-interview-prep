/*
Daily practice problem
Link: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/?envType=daily-question&envId=2026-04-11
*/


class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(),ans = INT_MAX;
        vector<vector<int>>vq(n+1);
        for(int i=0;i<n;i++){
            if(vq[nums[i]].size()==2){
                ans = min(ans,2*(i-vq[nums[i]][0]));
                vq[nums[i]].erase(vq[nums[i]].begin());
                
            }
            vq[nums[i]].push_back(i);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};