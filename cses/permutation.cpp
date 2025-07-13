// A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
// Given n, construct a beautiful permutation if such a permutation exists.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1" << endl; // The only permutation for n=1
    } else if (n == 2) {
        cout << "2 1" << endl; // The only beautiful permutation for n=2
    } else {
        // For n >= 3, we can construct a beautiful permutation
        for (int i = 2; i <= n; i++) {
            cout << i << " "; // Print even numbers first
        }
        for (int i = 1; i <= n; i += 2) {
            cout << i << " "; // Then print odd numbers
        }
        cout << endl;
    }

    return 0;
}