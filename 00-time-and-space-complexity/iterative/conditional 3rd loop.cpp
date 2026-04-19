for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

        if (i == j) {

            for (int k = 0; k < n; k++) {
                sum++;
            }

        }
    }
}


Time Complexity: O(n^2)
Space Complexity: O(1) (only a constant amount of extra space is used)