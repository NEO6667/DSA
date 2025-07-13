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
    cout<<s<<endl;
	return s;
}

// int search(vector<int>&arr,int key){
// 	int piv=pivot(arr);
// 	if(arr[piv]<key && arr[arr.size()-1]){
// 		int s=piv,e=arr.size()-1;
// 		while(s<=e){
// 			int mid=s+(e-s)/2;
// 			if(arr[mid]==key){
// 				return mid;
// 			}
// 			else if(arr[mid]<key){
// 				s=mid+1;
// 			}
// 			else{
// 				e=mid-1;
// 			}
// 		}
// 	}
// 	else{
// 		int s=0,e=piv-1;
// 		while(s<=e){
// 			int mid=s+(e-s)/2;
// 			if(arr[mid]==key){
// 				return mid;
// 			}
// 			else if(arr[mid]<key){
// 				e=mid-1;  //here error
//				s=mid+1;
// 			}
// 			else{
// 				s=mid+1; //same here
//				e=mid-1;
// 			}
// 		}

// 	}
// 	return -1;
// }
int binarySearch(vector<int>&arr,int s,int e, int k){
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==k){
			return mid;
		}
		else if(arr[mid]<k){
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
    return -1;
}
int main(){
	vector<int>arr={7,9,1,2,3};
	int key=2;

	int piv=pivot(arr),n=arr.size()-1;

	if(arr[piv]<=key && key<=arr[n]){
		cout<<binarySearch(arr,piv,n,key);
	}
	else{
		cout<<binarySearch(arr,0,piv,key);
	}

	return 0;
}