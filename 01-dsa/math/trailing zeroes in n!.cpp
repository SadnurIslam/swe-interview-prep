/*

link : https://leetcode.com/problems/factorial-trailing-zeroes/description/

theory:
Given an integer n, return the number of trailing zeroes in n!.
Trailing zeros can be made with pairs of 2 and 5. But there are always more factors of 2 than 5 in n!, so we only need to count the number of times 5 is a factor in the numbers from 1 to n.

Formula to calculate trailing zeroes in n! is:
trailing zeroes in n! = ⌊n/5⌋ + ⌊n/25⌋ + ⌊n/125⌋ + .....
Where ⌊x⌋ is the floor function.


Time Complexity: O(log5(N)) -> O(logN)

*/


int trailingZeroes(int n) {
    int ans = 0;

    for(int i=5;i<=n;i=i*5){
        ans+=n/i;
    }

    return ans;
}