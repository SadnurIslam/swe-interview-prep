int fib(int n) {
    if (n <= 1) 
        return n;

    return fib(n - 1) + fib(n - 2);
}



Time Complexity: O(2^n)

Space Complexity: O(n) (due to the call stack in recursion)
                maximum depth of the call stack is n.