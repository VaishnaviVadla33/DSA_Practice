#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramList;
        for(string s: strs){
            string sorteds=s;
            sort(sorteds.begin(),sorteds.end());

            anagramList[sorteds].push_back(s);
        }

        vector<vector<string>> results;
        for(auto& pair: anagramList){
            results.push_back(pair.second);
        }

        return results;
        
    }
};

int main(){
    Solution sol;
    vector<string> strs= {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> results=sol.groupAnagrams(strs);
    cout<<"sorted anagram groups are"<<endl;
    // Print the results
    auto printResult = [](const vector<vector<string>>& result) {
        for (const auto& group : result) {
            cout << "[";
            for (const auto& word : group) {
                cout << "\"" << word << "\",";
            }
            cout << "],";
        }
        cout << endl;
    };
    printResult(results);
}