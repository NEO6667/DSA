#include<bits/stdc++.h>
using namespace std;


// pair<int,int> pairSum(vector<int> arr, int k){
//     unordered_map<int,int> m;
//     pair<int,int> p;
//     for(int i=0; i<arr.size(); i++){
//         int x=k-arr[i];
//         if(m.find(x)!=m.end()){
//             p.first=x;
//             p.second=arr[i];
//             return p;
//         }
//         m[arr[i]]=i;
//     }
//     return {-1,-1};
// }

int main(){

    vector<int> arr= {1,2,3,4,5};
    int k=5;
    vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==k){
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                ans.push_back(temp);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }

    return 0;
}