/*
Daily practice problem
Link: https://leetcode.com/problems/binary-number-with-alternating-bits/description
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while(n>0){
            int rem = n%2;
            if(rem==prev)return false;
            n/=2;
            prev = rem;
        }
        return true;
    }
};