#include <bits/stdc++.h> 
void solve(stack<int>& myStack, int x, int count, int size){
    //base case
    if(count==size){
        myStack.push(x);
        return;
    }

    int num=myStack.top();
    myStack.pop();
    solve(myStack,x,count+1,size);
    myStack.push(num);

}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    int count=0;
    int size=myStack.size();
    solve(myStack, x, count, size);
    return myStack;
}

-------------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
void solve(stack<int>& myStack, int x){
    //base case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int num = myStack.top();
    myStack.pop();
    solve(myStack, x);
    myStack.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack, x);
    return myStack;
}
