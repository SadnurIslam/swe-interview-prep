Link:   https://leetcode.com/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-interview-150




Solution: Optimized Backtracking Solution

class Solution {
public:

    void rec(int idx, int open, int closed, int n, string &tmp, vector<string>&ans){
        if(idx>=2*n){
            ans.push_back(tmp);
            return;
        }

        if(open<n){
            tmp.push_back('(');
            rec(idx+1,open+1,closed,n,tmp,ans);
            tmp.pop_back();
        }

        if(closed<open){
            tmp.push_back(')');
            rec(idx+1,open,closed+1,n,tmp,ans);
            tmp.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string tmp = "";
        rec(0,0,0,n,tmp,ans);
        return ans;
    }
};





Solution: Brute Force Solution

class Solution {
public:

    bool valid(string s, int n){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')cnt++;
            else{
                if(cnt==0)return false;
                else cnt--;
            }
        }
        return cnt==0;
    }
    void rec(int idx, int n, string tmp, vector<string>&ans){
        if(idx>=n){
            cout<<tmp<<endl;
            if(valid(tmp,n)){
                ans.push_back(tmp);
            }
            return;
        }

        tmp.push_back('(');
        rec(idx+1,n,tmp,ans);

        tmp.pop_back();

        tmp.push_back(')');
        rec(idx+1,n,tmp,ans);

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string tmp = "";
        rec(0,2*n,tmp,ans);
        return ans;
    }
};