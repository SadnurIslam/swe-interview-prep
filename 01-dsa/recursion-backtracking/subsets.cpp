Link:   https://leetcode.com/problems/subsets/description/



Solution: using recursion and backtracking

class Solution {
public:
    void rec(int idx, vector<int>&nums,vector<vector<int>>&ans,vector<int>&tmp){
        if(idx>=nums.size()){
            ans.push_back(tmp);
            return;
        }

        // pick the current element
        tmp.push_back(nums[idx]);
        rec(idx+1,nums,ans,tmp);

        // not pick the current element
        tmp.pop_back();
        rec(idx+1,nums,ans,tmp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        rec(0,nums,ans,tmp);
        return ans;
    }
};




Alternative: using bit manipulation

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<(1<<n);i++){
            bitset<10>bs(i);
            vector<int>tmp;
            for(int j=0;j<n;j++){
                if(bs[j]==1)tmp.push_back(nums[j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};