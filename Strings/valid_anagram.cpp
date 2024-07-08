#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

baat, tab

Input: s = "rat", t = "car"
Output: false*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};

int main(){
    Solution sol;
    string s = "anagram", t = "nagaram";
    cout<<sol.isAnagram(s,t);
}