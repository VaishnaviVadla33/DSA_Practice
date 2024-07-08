#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int k, i, j;
        string longest = "";

        for (k = 0; k < s.size(); k++) {
            for (i = 0; i < s.size(); i++) {
                string pat = s.substr(k, i + 1); // Create the substring from k to i
                //cout << "Pattern is: " << pat << endl;
                if (isPalindrome(pat)) {
                    //cout << "Palindrome found: " << pat << endl;
                    if (pat.size() > longest.size()) {
                        longest = pat;
                    }
                }
            }
        }
        
        return longest;
    }

private:
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    string s = "cbbd";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;

    s = "babad";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;

    return 0;
}
