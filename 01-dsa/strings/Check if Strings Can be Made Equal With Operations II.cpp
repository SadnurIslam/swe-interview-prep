/*
Daily practice problem
Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description
*/

// first attempt (accepted)
// Time complexity: A little bit higher (60ms+)

/*
Strategy:
1. We can swap characters at odd indices and even indices separately.
2. So, we can separate the characters at odd and even indices for both strings.
3. Then, we can sort the characters at odd and even indices separately for both strings.
4. Finally, we can compare the sorted characters at odd and even indices for both strings.

*/

#define pb push_back
#define ssort(a) sort(a.begin(),a.end())
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string so1="",se1="",so2="",se2="";
        int n = s1.size();
        for(int i=0;i<n;i++){
            if(i&1){
                so1.pb(s1[i]);
                so2.pb(s2[i]);
            }
            else{
                se1.pb(s1[i]);
                se2.pb(s2[i]);
            }
        }
        ssort(so1);
        ssort(so2);
        ssort(se1);
        ssort(se2);

        return (so1==so2 && se1==se2);
    }
};



// second attempt (accepted)
// Time complexity: O(n) (0ms)

/*
Strategy:
1. We can swap characters at odd indices and even indices separately.
2. So, we can separate the characters at odd and even indices for both strings.
3. We can count the frequency of characters at odd and even indices separately for both strings.
4. Finally, we can compare the frequency of characters at odd and even indices for both strings.

*/


class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int>odd(26,0),even(26,0);
        int n = s1.size();
        for(int i=0;i<n;i++){
            if(i&1){
                odd[s1[i]-97]++;
                odd[s2[i]-97]--;
            }
            else{
                even[s1[i]-97]++;
                even[s2[i]-97]--;
            }
        }
        for(int i=0;i<26;i++){
            if(even[i]!=0 || odd[i]!=0)return false;
        }

        return true;
    }
};