/*
Daily practice problem
Link: https://leetcode.com/problems/robot-return-to-origin/description/?envType=daily-question&envId=2026-04-05
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j =0;
        for(auto move:moves){
            if(move=='U')i--;
            else if(move=='D')i++;
            else if(move=='L')j--;
            else j++;
        }
        return i==0 && j==0;
    }
};