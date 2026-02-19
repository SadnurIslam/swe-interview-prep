/*
Daily practice problem
Link: https://leetcode.com/problems/binary-watch/?envType=daily-question&envId=2026-02-17
*/

/*
Note: recursion on subset
*/


class Solution {
public:
    void func(int ind, vector<pair<int,int>>&vp,vector<pair<int,int>>&tmp, vector<pair<int,int>>&times,int turnedOn, int n){
        if(ind==n || tmp.size()>=turnedOn){
            
            if(tmp.size()!=turnedOn)return;
            int time=0;
            int hr = 0, mnt = 0;
            for(int i=0;i<turnedOn;i++){
                if(tmp[i].second==1){
                    hr+=tmp[i].first;
                }
                else{
                    mnt+=tmp[i].first;
                }
            }
            
            times.push_back({hr,mnt});
            return;
        }
        tmp.push_back(vp[ind]);
        func(ind+1,vp,tmp,times,turnedOn,n);
        tmp.pop_back();
        func(ind+1,vp,tmp,times,turnedOn,n);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<pair<int,int>>vp,tmp;
        for(int i=1;i<=32;i=i*2){
            if(i<=8){
                vp.push_back({i,1});
                vp.push_back({i,-1});
            }
            else{
                vp.push_back({i,-1});
            }
        }
        vector<pair<int,int>>times;
        func(0,vp,tmp,times,turnedOn,vp.size());
        vector<string>ans;
        for(auto time:times){
            int hour = time.first;
            int minute = time.second;
            if(hour>11 || minute>59)continue;
            string hr = to_string(hour);
            string mnt = to_string(minute);
            if(minute<10){
                mnt= "0"+mnt;
            }
            ans.push_back(hr+":"+mnt);
        }
        return ans;
    }
};