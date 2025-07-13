#include<bits/stdc++.h>
using namespace std;

int pivot(vector<int>&arr){
	int s=0,e=arr.size()-1;
	while(s<e){
		int mid=s+(e-s)/2;
		if(arr[mid]<arr[mid+1]){
			s=mid+1;
		}
		else{
			e=mid;
		}
	}
	return arr[s];
}

int main(){
	vector<int> arr={1,2,3,4,5,6,7,8,9,5,3,2,1};

	cout<<pivot(arr);
	return 0;
}