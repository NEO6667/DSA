#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>& arr,int key){
    int s=0, e=arr.size()-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int lastOcc(vector<int>& arr,int key){
    int s=0, e=arr.size()-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 5, 5, 6,6,6,6,7,7,7,7,7,7,7,2,88,8};
    int target = 6;

    cout<<firstOcc(arr, target)<<endl;
    cout<<lastOcc(arr, target)<<endl;



    return 0;
}