#include<bits/stdc++.h>
using namespace std;

int main(){
    // Declare a vector of integers
    vector<int> nums = {1,3,2,7,11,8};
    // Print the original vector
    cout << "Original vector: ";
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    // Swap alternate elements in the vector
    for(int i=0; i<nums.size()-1; i+=2){
        if(i+1<nums.size()){
            swap(nums[i], nums[i+1]);
        }
    }
    // Print the modified vector
    cout << "Vector after swapping alternate elements: ";
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;


    return 0;
}