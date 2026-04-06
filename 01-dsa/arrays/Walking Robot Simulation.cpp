/*
Daily practice problem
Link: https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2026-04-06
*/



class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<char,char>right,left;
        right['n'] = 'e';
        right['e'] = 's';
        right['s'] = 'w';
        right['w'] = 'n';

        left['n'] = 'w';
        left['w'] = 's';
        left['s'] = 'e';
        left['e'] = 'n';

        set<pair<int,int>>st;
        for(auto p:obstacles){
            st.insert({p[0],p[1]});
        }
        int ans = 0;
        char face = 'n';
        int x=0,y=0;
        int sz = commands.size();

        for(auto com:commands){
            if(com==-1){
                face = right[face];
            }
            else if(com==-2){
                face = left[face];
            }
            else{
                if(face=='n'){
                    while(com--){
                        y++;
                        if(st.find({x,y})!=st.end()){
                            y--;
                            break;
                        }
                    }
                }
                else if(face=='e'){
                    while(com--){
                        x++;
                        if(st.find({x,y})!=st.end()){
                            x--;
                            break;
                        }
                    }
                }
                else if(face=='s'){
                    while(com--){
                        y--;
                        if(st.find({x,y})!=st.end()){
                            y++;
                            break;
                        }
                    }
                }
                else{
                    while(com--){
                        x--;
                        if(st.find({x,y})!=st.end()){
                            x++;
                            break;
                        }
                    }
                }
                ans = max(ans,x*x+y*y);
            }
        }

        return ans;
    }
};