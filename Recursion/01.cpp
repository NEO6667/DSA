#include<iostream>
#include<string.h>
using namespace std;

void rec(string s, int n){
    if(n<0) return;
    cout<<s<<endl;
    rec(s,n-1);
    cout<<n<<endl;
}

void print1ToN(int i, int n){
    if(i==n+1) return;
    cout<<i<<endl;
    print1ToN(i+1,n);
}

void printNto1(int n){
    if(n<0) return;
    cout<<n<<endl;
    printNto1(n-1);
}

void back1toN(int n){
    if(n<0) return;
    back1toN(n-1);
    cout<<n<<endl;
}

void backNto1(int n, int i){
    if(i>n) return;
    backNto1(n,i+1);
    cout<<i<<endl;
}

int main(){
    // string s;
    // getline(cin, s);
    // rec(s, 5);
    int n;
    cin>>n;
    cout<<endl;

    // print1ToN(0,n);
    // printNto1(n);

    // back1toN(n);

    backNto1(n,0);



    return 0;
}