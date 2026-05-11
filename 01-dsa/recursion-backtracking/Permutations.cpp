Link:   https://leetcode.com/problems/permutations/description/?envType=study-plan-v2&envId=top-interview-150


Note:
=> permutation er khetre current index er sathe sob index swap kore samne jabo, tarpor swap back korbo



Solution:

class Solution {
public:
    void perm(int idx, int n, vector<vector<int>>&ans, vector<int>&nums){
        if(idx>=n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            perm(idx+1,n,ans,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        perm(0,n,ans,nums);
        return ans;
    }
};