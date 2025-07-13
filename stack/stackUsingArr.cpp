#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;
    
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    
    public:
    void push(int n){
        if(size-top>1){
            top++;
            arr[top]=n;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
        
    }
    
    void pop(){
        if(top>=0){
            cout<<arr[top--]<<endl;
        }
        
    }
    
    int peek(){
        return arr[top];
    }
    
    bool empty(){
        if(top>=0){
            return 1;
        }
        else{
            return 0;
        }
        
    }
    
};

int main(){
     Stack s(5);

    s.push(10);
    s.push(20);
    cout << "Top: " << s.peek() << endl;

    s.pop();
    cout << "Is Empty: " << s.empty() << endl;

    s.pop();
    s.pop(); // Underflow test
    
    return 0;
}

// ---------------------------------------------
// implementation of stack using linked list //
// ---------------------------------------------


/*#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    
};

class Stack{
    public:
    Node* head;
    
    Stack(){
        head=NULL;
    }
    
    void push(int val){
        Node* newHead= new Node(val);
        newHead->next=head;
        head=newHead;
    }
    
    void pop(){
        if(head!=NULL){
            Node* temp = head;
            head=head->next;
            delete temp;
        }
    }
    
    int peek(){
        if(head!=NULL){
            return head->data;
        }
    }
    
    bool empty(){
        return head==NULL;
        
    }
};

int main(){
    
    return 0;
}*/