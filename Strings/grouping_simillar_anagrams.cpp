#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // for sort
using namespace std;

// Function to create a list of lists from a list of strings
vector<vector<char>> createListOfLists(const vector<char>& input) {
    // Create an unordered map to count occurrences of each string
    unordered_map<char, vector<char>> occurrenceMap;

    // Populate the occurrence map
    for (char c : input) {
        occurrenceMap[c].push_back(c);
    }

    // Create a vector to hold the lists of occurrences
    vector<vector<char>> listOfLists;

    // Transfer values from map to vector
    for (auto& pair : occurrenceMap) {
        listOfLists.push_back(pair.second);
    }

    // Sort inner lists based on first element
    auto sortByFirstElement = [](const vector<char>& a, const vector<char>& b) {
        return a[0] < b[0];
    };
    sort(listOfLists.begin(), listOfLists.end(), sortByFirstElement);

    return listOfLists;
}

int main() {
    vector<char> input = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c', 'd', 'd'};
    
    // Create list of lists
    vector<vector<char>> listOfLists = createListOfLists(input);

    // Output the result
    cout << "List of lists:\n";
    cout<<"[";
    for (const auto& list : listOfLists) {
        cout << "[ ";
        for (char c : list) {
            cout << c << " ";
        }
        cout << "],\n";
    }
    cout<<"]";

    return 0;
}
