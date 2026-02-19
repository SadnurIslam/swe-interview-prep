/*
Daily practice problem
Link: https://leetcode.com/problems/count-binary-substrings/description
*/


// first attempt (accepted)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size(), c0 = 0, c1 = 0,ans=0;
        if(s[0]=='0')c0=1;
        else c1 = 1;
        s.push_back((s[n-1]=='0')?'1':'0');
        for(int i=1;i<=n;i++){
            if(s[i]!=s[i-1]){
                ans +=min(c0,c1);
                if(s[i]=='0')c0=0;
                else c1 = 0;
            }
            if(s[i]=='0')c0++;
            else c1++;
        }
        return ans;
    }
};



// second attempt (accepted)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size(),ans=0;
        vector<int>cnt;
        int c = 1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])c++;
            else{
                cnt.push_back(c);
                c=1;
            }
        }
        cnt.push_back(c);
        for(int i=1;i<cnt.size();i++){
            ans+=min(cnt[i],cnt[i-1]);
        }
        return ans;
    }
};