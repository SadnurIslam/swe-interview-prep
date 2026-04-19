// Time Complexity: O(2^n)
// Space Complexity: O(n) (due to the recursive call stack, which can go up to n levels deep in the worst case)

#include <bits/stdc++.h>
using namespace std;

int fibo(int n){
    if(n==0)return 0;
    if(n==1) return 1;
    return fibo(n-1)+fibo(n-2);
}

int main() {
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
}





//  Time Complexity: O(n) (each Fibonacci number is computed once and stored in the dp array)
// Space Complexity: O(n) (the dp array of size n+1 is used to store the computed Fibonacci numbers)

#include <bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int>&dp){
    if(n==0)return 0;
    if(n==1) return 1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}

int main() {
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    fibo(n,dp);
    cout<<dp[n]<<endl;
}
