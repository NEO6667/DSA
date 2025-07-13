// You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<bool> present(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        present[x] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!present[i]) {
            cout << i << endl;
            break;
        }
    }


    return 0;
}