/*
Daily practice problem
Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=daily-question&envId=2026-03-29
*/




class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1[0]>s1[2])swap(s1[0],s1[2]);
        if(s1[1]>s1[3])swap(s1[1],s1[3]);
        if(s2[0]>s2[2])swap(s2[0],s2[2]);
        if(s2[1]>s2[3])swap(s2[1],s2[3]);
        return s1==s2;
    }
};