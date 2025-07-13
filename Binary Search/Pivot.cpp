#include<bits/stdc++.h>
using namespace std;

int pivot(vector<int>&arr){
	int s=0,e=arr.size()-1;
	while(s<e){
		int mid=s+(e-s)/2;
		if(arr[mid]>=arr[0]){
			s=mid+1;
		}
		else{
			e=mid;
		}
	}
	return arr[s];
}

int main(){
	vector<int> arr={7,9,1,2,3};

	cout<<pivot(arr)<<endl;

	return 0;
}