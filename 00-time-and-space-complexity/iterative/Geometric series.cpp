1.   for (i = 0; i < n; i++)           // runs n times
    {
        for (j = n; j > 0; j /= 2)    // j = n, n/2, n/4, ... , 1  => log n times
        {
            for (k = 0; k < j; k++)   // runs j times
            {
                sum++;
            }
        }
    }


    Inner two loops (j and k)
    For each j, the k loop runs j times.
    So total work for the j loop:
                            =n+(n/2)+(n/4)+...+1
                            This is a geometric series:
                            =2n-1
                             O(n)

    So the middle+inner loops together cost O(n).

    Outer loop runs n times.

    So total complexity: O(n) * O(n) = O(n^2)

    ->Final Time Complexity: O(n^2)





2.  for (int i = n; i >= 1; i /= 2) {
        for (int j = 1; j <= i; j++) {
            sum++;
        }
    }


    Outer loop: i = n, n/2, n/4, ... , 1  => log n times
    Inner loop: runs i times for each iteration of the outer loop.
    So total work:
                    =n+(n/2)+(n/4)+...+1
                    This is a geometric series:
                    =2n-1
                     O(n)
    
    Final Time Complexity: O(n)



