/*
Daily practice problem
link:  https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/?envType=daily-question&envId=2026-03-01

*/



class Solution {
public:
    int minPartitions(string n) {
        int mx = 1;
        for(auto c:n)mx=max(mx,c-48);
        return mx;
    }
};