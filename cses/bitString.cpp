// Your task is to calculate the number of bit strings of length n.
// For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.
#define mod 1000000007
#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    // The number of bit strings of length n is 2^n
    // We can calculate this using the power function
    long long result = 1;
    for(int i = 0; i < n; i++){
        result = (result * 2) % mod; // Using modulo to prevent overflow
    }
    cout << result << endl;
    // The above code calculates the number of bit strings of length n by raising 2 to
    // the power of n. It uses a loop to multiply 2, n times, and applies modulo 1000000007
    // to ensure the result does not overflow. The final result is printed to the console.
    return 0;
}