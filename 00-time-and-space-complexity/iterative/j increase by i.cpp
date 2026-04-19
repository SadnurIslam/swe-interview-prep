for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j = j + i) {
        count++;
    }
}

Time Complexity : O(n log n)
Space Complexity: O(1) (only a constant amount of extra space is used)



............................................




for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j = j + i) {
        for (int k = 1; k <= n; k = k + j) {
            count++;
        }
    }
}


Time Complexity Analysis: O(n log^2 n)
Space Complexity: O(1) (only a constant amount of extra space is used)


..............................................

for (int i = 1; i <= n; i++) {

    int j = n;

    while (j >= 1) {
        j = j - i;   // j decreases by i in each iteration
    }

}


Time Complexity: O(n log n)
Space Complexity: O(1) (only a constant amount of extra space is used)