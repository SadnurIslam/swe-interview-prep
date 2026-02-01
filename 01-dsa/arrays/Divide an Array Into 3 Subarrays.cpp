/*
link:  https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description

*/

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin()+1,nums.end());  //sort from index 1 to end because we should keep the first element as it is
        return nums[0]+nums[1]+nums[2];
    }
};


/*
My first attempt: wrong answer
cause: I sorted the whole array instead of sorting from index 1 to end but index 0 should be always in the first subarray as first element

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[0]+nums[1]+nums[2];
    }
};

*/