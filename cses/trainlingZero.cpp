// Your task is to calculate the number of trailing zeros in the factorial n!.
// For example, 20!=2432902008176640000 and it has 4 trailing zeros.

#include <bits/stdc++.h>
using namespace std;

long long fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    
    return n*fact(n-1);
}

// int main(){
//     int n;
//     cin>>n;
//     long long ans=fact(n);
//     int cnt=0;
    
//     while(1){
//         if(ans%10==0){
//             cnt++;
//             ans/=10;
//         }
//         else{
//             break;
//         }
        
//     }
//     cout<<cnt;
    
//     return 0;
// }

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    while (n > 0) {
        cnt += n / 5;
        n /= 5;
        cout << "Current n: " << n << ", Count of trailing zeros: " << cnt << endl;
    }

    cout << cnt << endl;

    return 0;
}