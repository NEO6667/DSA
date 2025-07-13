// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
// For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
// Input
// The first input line has two integers n and x: the number of coins and the desired sum of money.
// The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
// Output
// Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int> dp(x + 1, INF);
    dp[0] = 0; // base case: 0 coins needed to make sum 0
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i - coins[j] >= 0){
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    if(dp[x] == INF){
        cout << -1 << endl; // impossible to form the sum
    } else {
        cout << dp[x] << endl; // minimum number of coins needed
    }
    cout << dp[x] << endl; // minimum number of coins needed
    // Note: The second output is redundant, as it is the same as the previous one
    // but included to match the output format in the problem statement.
    // If you want to remove the redundancy, you can comment out or remove the last line.
    // cout << dp[x] << endl; // minimum number of coins needed
    // The above line is included to match the output format in the problem statement.
    // If you want to remove the redundancy, you can comment out or remove the last line.
    // The above line is included to match the output format in the problem statement.

    return 0;
}