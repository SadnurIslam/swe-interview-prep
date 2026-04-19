=> recursion er space complexity O(depth of the tree), ekhane depth n

=> Space complexity is O(n) here for all cases
    because the maximum depth of the call stack is n 
    (since we are reducing n by 1 in each recursive call).
    n = depth of the call stack



void func(int n) {
    if (n <= 1)
        return;

    func(n - 1);
}

Time Complexity: O(n)
Space Complexity:  O(n) (due to the call stack in recursion)
                maximum depth of the call stack is n.


.................................



void func(int n) {
    if (n <= 1)
        return;

    func(n - 1);
    func(n - 1);
}

Time Complexity: O(2^n)
Space Complexity: O(n) 


.........................................



void func(int n) {
    if (n <= 1)
        return;

    func(n - 1);

    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }

}

Time Complexity: O(n^2)
Space Complexity: O(n) 



...............................


void func(int n) {
    if (n <= 1)
        return;

    for (int i = 1; i <= n; i++) {
        func(n - 1);
    }

}


Time Complexity: O(n!)
Space Complexity: O(n) 


..............................


void func(int n) {
    if (n <= 1)
        return;

    func(n - 1);

    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }

    func(n - 1);
}


Time Complexity: O(n * 2^n)
Space Complexity: O(n)