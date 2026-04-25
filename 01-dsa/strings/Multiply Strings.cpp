Link:   https://leetcode.com/problems/multiply-strings/description/









Solution:


class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<vector<int>>v(n,vector<int>(n+m,0));
        int k = 0, l = 0;
        for(int i=n-1;i>=0;i--){
            int carry = 0;
            int x = n+m-1-l;
            for(int j=m-1;j>=0;j--){
                int d1 = num1[j]-48;
                int d2 = num2[i]-48;
                int mul = d1*d2+carry;
                int rem = mul%10;
                carry = mul/10;
                v[k][x] = rem;
                x--;
            }
            if(carry>0){
                v[k][x]=carry;
            }
            l++;
            k++;
        }
        string ans = "";
        int carry = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m+n;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=m+n-1;i>=0;i--){
            int sum = 0;
            for(int j=n-1;j>=0;j--){
                sum+=v[j][i];
            }
            sum+=carry;
            ans.push_back(char(sum%10+48));
            carry = sum/10;
        }
        while(carry>0){
            ans.push_back(char(carry%10+48));
            carry/=10;
        }
        while(true){
            int sz = ans.size();
            char last = ans[sz-1];
            if(sz==1)break;
            if(last=='0')ans.pop_back();
            else break;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};