// Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
// $$ 3 \rightarrow 10 \rightarrow 5 \rightarrow 16 \rightarrow 8 \rightarrow 4 \rightarrow 2 \rightarrow 1$$
// Your task is to simulate the execution of the algorithm for a given value of n

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != 1)
    {
        if (n & 1)
        {
            n = n * 3 + 1;
            cout << n << " -> ";
        }
        else
        {
            n /= 2;
            cout << n << " -> ";
        }
    }

    return 0;
}