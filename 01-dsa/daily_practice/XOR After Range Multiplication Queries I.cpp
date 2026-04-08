/*
Daily practice problem
Link: https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/?envType=daily-question&envId=2026-04-08
*/




class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        for(int i=0;i<q;i++){
            int idx = queries[i][0];
            while(idx<=queries[i][1]){
                nums[idx] = (1LL*nums[idx]*queries[i][3])%1000000007;
                idx+=queries[i][2];
            }
        }
        int ans = 0;
        for(auto num:nums)ans^=num;
        return ans;
    }
};