#include <iostream>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Check if lengths are the same
    if (s.length() != t.length()) {
        return false;
    }

    // Create a map to count character frequencies
    unordered_map<char, int> charCount1;
    unordered_map<char, int> charCount2;

    // Count characters for the first string
    for (char c : s) {
        charCount1[c]++;
    }

    // Count characters for the second string
    for (char c : t) {
        charCount2[c]++;
    }

    // Compare the two maps
    return charCount1 == charCount2;
    }
};

int main(){
    Solution sol;
    string s = "anagram", t = "nageram";
    cout<<sol.isAnagram(s,t);
}

