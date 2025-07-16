// You are given an integer array a of length n and an integer x.

// In one operation, you can remove the leftmost or rightmost element from the array. The value of the removed element is then subtracted from 
// .

// Your goal is to perform a minimum number of such operations so that 
//  becomes exactly 
// . If it's not possible, print 
// .

// Note: The removed elements no longer appear in the array for future operations.
// Input Format:
// The first line contains two integers 
//  and 
//  (
// , 
// ) --- the size of the array and the target value.

// The second line contains 
//  integers 
//  (
// ) --- the elements of the array.
// Output Format:
// Print a single integer --- the minimum number of operations to make 
//  exactly zero, or 
//  if it is not possible.

#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int>& arr, int n, int x){
    int total = 0;
    for(int val:arr) total += arr[val];
    int tar = total - x;
    if(tar < 0) return -1;

    int maxLen = -1, sum = 0, left = 0;
    for(int right=0; right<n; ++right){
        sum += arr[right];
        while(sum > tar && left <= right){
            sum -= arr[left++];
        }
        if(sum == tar){
            maxLen = max(maxLen, right - left + 1);
        }
    }
    return (maxLen == -1) ? -1 : n - maxLen;
}

int main(){

    int n,x;
    cin>>n>>x;
    vector<int> arr;
    for(int &val:arr) cin>>arr[val];

    cout<<solve(arr,n,x)<<endl;

    return 0;

}