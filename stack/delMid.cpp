// delete middle element of a stack 

#include<bits/stdc++.h>
using namespace std;

void deleteMid(stack<int> &st, int size, int curr) {
    if (st.empty() || curr == size) {
        return;
    }
    
    int x = st.top();
    st.pop();
    
    if (curr == size / 2) {
        // If we are at the middle element, do not push it back
        return;
    }
    
    // Recursive call
    deleteMid(st, size, curr + 1);
    
    // Push the element back to stack
    st.push(x);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    int size = st.size();
    
    deleteMid(st, size, 0);
    
    // Print the stack after deleting the middle element
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}


/*#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>&inputStack, int size, int count){
   //base case
   if(count==size/2){
      inputStack.pop();
      return;
   }
   int num=inputStack.top();
   inputStack.pop();
   solve(inputStack,size,count+1);
   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
   // Write your code here  
   int count=0;
   solve(inputStack,N,count);
}

int main(){
    deleteMiddle;
    
    return 0;
}*/