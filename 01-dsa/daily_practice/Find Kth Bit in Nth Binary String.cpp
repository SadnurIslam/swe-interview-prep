/*
Daily practice problem
Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/?envType=daily-question&envId=2026-03-03
*/

class Solution {
public:

    string func(int n){
        if(n==1)return "0";
        string prev = "0",cur;
        for(int i=2;i<=n;i++){
            cur = prev+"1";
            for(int j = prev.size()-1;j>=0;j--){
                if(prev[j]=='0')cur.push_back('1');
                else cur.push_back('0');
            }
            prev = cur;
        }
        return cur;
    }

    char findKthBit(int n, int k) {
        string s = func(n);
        cout<<s<<endl;
        return s[k-1];
    }
};