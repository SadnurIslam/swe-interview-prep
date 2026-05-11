Link:   https://leetcode.com/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150



Note:
=> N songkhok jinis theke k songkhok jinis neyar combination er khetre
current ta niye jabo ekbar , na niye jabo ekbar, tarpor k songkhk puron hole ans a rakhbo



Solution:

class Solution {
public:
    void rec(int cur, int n, int k, vector<int>&tmp, vector<vector<int>>&ans){
        if(cur>n){
            if(tmp.size()==k){
                ans.push_back(tmp);
            }
            return;
        }

        tmp.push_back(cur);
        rec(cur+1,n,k,tmp,ans);

        tmp.pop_back();
        rec(cur+1,n,k,tmp,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>tmp;
        rec(1,n,k,tmp,ans);
        return ans;
    }
};