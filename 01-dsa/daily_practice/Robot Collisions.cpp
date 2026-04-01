/*
Daily practice problem
Link: https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2026-04-01
*/

// first attempt (accepted)
// Time complexity: A little bit higher (900ms+)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,pair<int,char>>, null_type,less<pair<int,pair<int,char>>>, rb_tree_tag,tree_order_statistics_node_update> //s.order_of_key  , *s.find_by_order

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ordered_set st;
        vector<int>ans;
        int n = positions.size();
        for(int i=0;i<n;i++){
            st.insert({positions[i],{healths[i],directions[i]}});
        }
        for(int i=0;i<n-1;){
            auto p = *st.find_by_order(i);
            auto q = *st.find_by_order(i+1);

            if(p.second.second=='R' && q.second.second=='L'){
                st.erase(p);
                st.erase(q);
                if(p.second.first==q.second.first){
                    if(i>0)i--;
                }
                else if(p.second.first>q.second.first){
                    st.insert({p.first,{p.second.first-1,p.second.second}});
                }
                else{
                    st.insert({q.first,{q.second.first-1,q.second.second}});
                    if(i>0)i--;
                }
            }
            else{
                i++;
            }
            n = st.size();
        }
        set<int>s;
        map<int,int>mp;
        for(auto p:st){
            s.insert(p.first);
            mp[p.first] = p.second.first;
        }
        for(int i=0;i<positions.size();i++){
            if(s.find(positions[i])!=s.end()){
                ans.push_back(mp[positions[i]]);
            }
        }
        return ans;
    }
};


// second attempt (accepted)
// Time complexity: (100ms)

/*
N.B. If second one to be added we should go back to current iteration again
*/



class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>ans;
        stack<tuple<int,int,char>>st;
        vector<tuple<int,int,char>>v;
        int n = positions.size();
        for(int i=0;i<n;i++){
            v.push_back({positions[i],healths[i],directions[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(v[i]);
                continue;
            }
            auto [pos,health,dir] = st.top();
            auto &[pos1,health1,dir1] = v[i];

            if(dir=='R' && dir1=='L'){
                if(health==health1){
                    st.pop();
                }
                else if(health>health1){
                    st.pop();
                    st.push({pos,health-1,dir});
                }
                else{
                    st.pop();
                    health1--;
                    i--;
                }
            }
            else{
                st.push(v[i]);
            }
        }
        map<int,int>mp;
        while(!st.empty()){
            auto [pos,health,dir]= st.top();
            mp[pos] = health;
            st.pop();
        }
        for(int i=0;i<n;i++){
            if(mp.find(positions[i])!=mp.end())ans.push_back(mp[positions[i]]);
        }
        return ans;
    }
};