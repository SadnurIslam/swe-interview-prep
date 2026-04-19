for (int i = 1; i <= n; i++) {

    int j = i;

    while (j % 2 == 0) {
        j /= 2;
        sum++;
    }

}


Time Complexity: O(n)
Space Complexity: O(1) (only a constant amount of extra space is used)