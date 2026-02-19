/*
leetcode 150

Link: https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150
*/

// my solution
class Solution {
public:
    map<int,string>mp;
    vector<int>v = {1,5,10,50,100,500,1000};

    string func(int &num){
        string s = to_string(num), curs="";
        bool fn= false;
        if(s[0]=='4' || s[0]=='9'){
            fn = true;
        }
        int sz = s.size();
        int cur = 1;
        for(int i=1;i<sz;i++){
            cur = cur*10;
        }
        int n = (s[0]-48);
        if(fn)n=(n+1)*cur;
        else n = n*cur;
        int lb = lower_bound(v.begin(),v.end(),n)-v.begin();
        if(lb>6){
            lb--;
        }
        if(v[lb]>n)lb--;
        if(fn==true){
            int lb1 =lower_bound(v.begin(),v.end(),cur)-v.begin();
            curs = mp[v[lb1]]+mp[v[lb]];
            num = num%cur;
        }
        else{
            curs+=mp[v[lb]];
            num-=v[lb];
        }
        
        return curs;
    }
    string intToRoman(int num) {
        mp[1] = "I";
        mp[5] = "V";
        mp[10] = "X";
        mp[50] = "L";
        mp[100] = "C";
        mp[500] = "D";
        mp[1000] = "M";
        string ans = "";
        while(num>0){
            string c= func(num);
            cout<<c<<endl;
            ans+=c;
        }
        return ans;
    }
};