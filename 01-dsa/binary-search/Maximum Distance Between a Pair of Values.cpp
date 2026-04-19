Link:   https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/?envType=daily-question&envId=2026-04-19






Solution 1:  O(nlogm)

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int l = 0, h = m-1, cur = -1;
            while(l<=h){
                int mid = (l+h)/2;
                if(nums2[mid]>=nums1[i]){
                    l = mid+1;
                    cur = mid;
                }
                else{
                    h = mid-1;
                }
            }
            if(cur!=-1){
                ans = max(ans,cur-i);
            }
        }
        return ans;
    }
};