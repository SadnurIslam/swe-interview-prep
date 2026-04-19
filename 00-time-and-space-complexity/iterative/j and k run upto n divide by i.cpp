for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= n / i; j++) {

        for (int k = 1; k <= n / i; k++) {

            sum++;

        }
    }
}


// j r k er upper limit duita mile gunfol (n/i x n/i) =  n er kasakasi hbe


Time Complexity: O(n^2)
Space Complexity: O(1) (only a constant amount of extra space is used)