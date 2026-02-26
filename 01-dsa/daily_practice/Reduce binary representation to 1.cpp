/*
Daily practice problem
link:  https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/

*/



class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s.size()>1){
            ans++;
            int n = s.size();
            if(s[n-1]=='0'){
                s.pop_back();
            }
            else{
                int pos = -1;
                for(int i=n-1;i>=0;i--){
                    if(s[i]=='0'){
                        pos = i;
                        break;
                    }
                    else{
                        s[i] = '0';
                    }
                }
                if(pos!=-1){
                    s[pos] = '1';
                }
                else{
                    s.insert(s.begin(),'1');
                }
            }
        }
        return ans;
    }
};