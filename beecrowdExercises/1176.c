// Author -> fatzzx
// Exercise -> 1176

#include <stdio.h>

// int fibonacci(int n)
// {
//     if (n <= 0)
//     {
//         return 0;
//     }
//     else if (n == 1 || n == 2)
//     {
//         return 1;
//     }
//     else
//     {
//         return fibonacci(n - 1) + fibonacci(n - 2);
//     }
// }

// int main()
// {
//     int n;
//     scanf(" %d", &n);
//     int f[n];

//     for (int i = 0; i < n; i++)
//     {
//         scanf(" %d", &f[i]);
//     }

//     for (int j = 0; j < n; j++)
//     {
//         printf("Fib(%d) = %d\n", f[j], fibonacci(f[j]));
//     }

//     return 0;
// }

int main()
{
    int n, f;
    long long fib[61];
    scanf("%d", &n);
    fib[0] = 0;
    fib[1] = 1;
    for (int j = 2; j <= 60; j++)
    {
        fib[j] = fib[j - 2] + fib[j - 1];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f);
        printf("Fib(%d) = %lld", f, fib[f]);
    }

    return 0;
}
