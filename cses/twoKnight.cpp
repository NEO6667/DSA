// Your task is to count for k=1,2,\ldots,n the number of ways two knights can be placed on a k \times k chessboard so that they do not attack each other.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++)
    {
        long long total = (k * k) * (k * k - 1) / 2;
        long long attack = 4 * (k - 1) * (k - 2);
        cout << total - attack << endl;
    }

    return 0;
}