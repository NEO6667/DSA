// You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
// On each move, you may increase the value of any element by one. What is the minimum number of moves required?

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long moves = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i - 1]){
            moves += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1]; // Increase current element to match the previous one
        }
    }

    cout << moves << endl;
    // The above code calculates the minimum number of moves required to make an array non-decreasing.
    // It iterates through the array, checking if the current element is less than the previous


    return 0;
}