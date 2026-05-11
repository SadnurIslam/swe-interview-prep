Link:   https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-interview-150



note:
=> ei dhoroner combination proti set theke ekta kore niyei jete hbe, tai loop chalabo protita kore ekbar kore niye gele ki output ashe seta nite



Solution: using recursion and backtracking

class Solution {
public:
    void rec(int idx, int n, string &tmp, vector<string>&ans, vector<string>&vs){
        if(idx==n){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<vs[idx].size();i++){
            tmp.push_back(vs[idx][i]);
            rec(idx+1,n,tmp,ans,vs);
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string>vs;
        for(auto d:digits)vs.push_back(mp[d]);
        vector<string>ans;
        string tmp = "";
        int n = digits.size();
        rec(0,n,tmp,ans,vs);
        return ans;
    }
};