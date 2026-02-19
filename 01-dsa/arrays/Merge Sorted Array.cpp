/*
leetcode 150

Link: https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
*/

/*
Note: Using two queues is simple and straightforward for this problem for O(m+n) complexity
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        queue<int>q1,q2;
        for(auto num:nums2)q2.push(num);
        for(int i=0;i<m;i++){
            q1.push(nums1[i]);
        }
        for(int i=0;i<m+n;i++){
            if(!q1.empty() && !q2.empty()){
                if(q1.front()<q2.front()){
                    nums1[i] = q1.front();
                    q1.pop();
                }
                else{
                    nums1[i] = q2.front();
                    q2.pop();
                }
            }
            else if(!q1.empty()){
                nums1[i] = q1.front();
                q1.pop();
            }
            else{
                nums1[i] = q2.front();
                q2.pop();
            }
        }
    }
};