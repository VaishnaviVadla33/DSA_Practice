#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
        return !isalnum(static_cast<unsigned char>(c));
    }), s.end());
    
    string s1 = s;
    reverse(s1.begin(), s1.end());
    if(s==s1){
        return true;
    }
    return false;
    }
};

int main(){
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panamae") << endl;
}