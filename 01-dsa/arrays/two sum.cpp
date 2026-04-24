class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp[target-nums[i]]>0){
                ans.push_back(mp[target-nums[i]]-1);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] =i+1;
        }
        return ans;
    }
};