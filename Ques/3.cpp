// 2586. Count the Number of Vowel Strings in Range

class Solution {
private:
    bool check(string s){
        int a = 0, b = s.length()-1;
        if((s[a] == 'a' || s[a] == 'e' || s[a] == 'i' || s[a] == 'o' || s[a] == 'u') && ((s[b] == 'a' || s[b] == 'e' || s[b] == 'i' || s[b] == 'o' || s[b] == 'u')) ){
            return true;
        }
        else{
            return false;
        }

    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for(int i=left; i <= right; i++){
            if(check(words[i])){
                cnt++;
            }
        }
        return cnt;
        
    }
};



class Solution {
private:
    bool isVowel(char ch) {
        ch = tolower(ch); // Optional, if case-insensitive
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    bool isVowelString(const string& s) {
        return isVowel(s.front()) && isVowel(s.back());
    }

public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            if (isVowelString(words[i])) {
                ++count;
            }
        }
        return count;
    }
};
