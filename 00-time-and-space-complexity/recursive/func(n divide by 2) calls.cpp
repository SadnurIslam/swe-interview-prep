=> Space complexity will O(logn) for all cases here 
    because the maximum depth of the call stack is log n (since we are dividing n by 2 in each recursive call).



void func(int n) {
    if (n <= 1) return;
    func(n / 2);
}

Time Complexity: O(log n)
Space Complexity: O(log n) (due to the call stack in recursion)


...............................................

void func(int n) {
    if (n <= 1) return;
    func(n / 2);
    func(n / 2);
}

Time Complexity = O(2^(log n)) = O(n)
Space Complexity: O(log n) (due to the call stack in recursion)



...............................................

void func(int n) {
    for (int i = 1; i <= n; i++) {
        func(n / 2);
    }
}


Time Complexity: O(n^(log n))
Space Complexity: O(log n) (due to the call stack in recursion)


...........................................


void func(int n) {
    if (n <= 1) return;
    func(n / 2);
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
}

T(n) = T(n/2) + O(n)

Time Complexity:  O(n)
Space Complexity: O(log n) (due to the call stack in recursion)


............................................


void func(int n) {
    if (n <= 1) return;
    func(n / 2);
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    func(n / 2);
}



Time Complexity: O(n log n)
Space Complexity: O(log n) (due to the call stack in recursion)



..................................................


void f(int n) {
    if (n <= 1)
        return;

    f(n / 2);
    f(n / 2);
    f(n / 2);
    f(n / 2);
}

T(n) = 4T(n/2) + O(1)
    = O(4^(log n)) = O(n^2)

Time Complexity: O(4^(log n)) = O(n^2)
Space Complexity: O(log n) (due to the call stack in recursion)


................................................

void f(int n) {
    if (n <= 1) return;

    f(n / 2);
    f(n / 2);
    f(n / 2);
    f(n / 2);

    for (int i = 0; i < n * n; i++) {
        print(i);
    }
}

T(n) = 4T(n/2) + O(n^2)
    = O(n^2 log n)

Time Complexity: O(n^2 log n)
Space Complexity: O(log n) (due to the call stack in recursion)


...............................................


void solve(int n) {
    if (n <= 1) return;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            print(i + j);
        }
    }

    solve(n / 2);
    solve(n / 2);
}


T(n) = 2T(n/2) + O(n^2)
    = O(n) + O(n^2)
    = O(n^2)

Time Complexity: O(n^2 )
Space Complexity: O(log n) (due to the call stack in recursion)