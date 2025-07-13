// reverse a string using stack

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="neo";
    stack<char> st;
    for(char ch:s){
        st.push(ch);
    }
    string ans="";
    
    while(!st.empty()){
        char ch=st.top();
        ans.push_back(ch);
        st.pop();
    }
    cout<<ans;
    
    
    return 0;
} b 