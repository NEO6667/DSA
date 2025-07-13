// Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

#include <bits/stdc++.h>
using namespace std;

bool canFormPalindrome(const string &s) {
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }
    
    int oddCount = 0;
    for (const auto &pair : charCount) {
        if (pair.second % 2 != 0) {
            oddCount++;
        }
    }
    
    return oddCount <= 1; // A palindrome can have at most one character with an odd count
}
int main() {
    string s;
    cin >> s;

    if (canFormPalindrome(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}