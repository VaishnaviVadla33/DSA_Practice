//There is an integer array nums sorted in ascending order (with distinct values).
//Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
//Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
//You must write an algorithm with O(log n) runtime complexity.
//Example 1:
//Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4

//my approach: rotated the array then searched the target , here i considered the pivot idex as target index then permormed the rotation 
//and again used target variable to search in sorted array and return its index

#include <iostream>
#include <vector>
#include <tuple> 
using namespace std;

tuple<vector<int>, int> sortedSearch(vector<int> & a, int target){
    vector<int> b(target);  // Create a vector with size 'target' to hold elements
    int i = 0;
    int n = a.size();

    // Copy elements from start to target index to vector b
    for(i = 0; i < target; i++){
        b[i] = a[i];
    }
    
    // Shift the rest of the elements in the original vector
    for(i = target; i < n; i++){
        a[i - target] = a[i];
    }  
    
    // Resize the original vector to hold the merged result
    a.resize(n);

    // Copy elements from vector b back to the original vector
    for(i = 0; i < target; i++){
        a[n - target + i] = b[i];
    }

    // Find the index of the target in the modified array
    int index = -1;
    for (i = 0; i < n; i++) {
        if (a[i] == target) {
            index = i;
            break;
        }
    }

    // Return the sorted array and the index of the target
    return make_tuple(a, index);
}

int main() {
    vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    int target = 2;  // You may want to use a different target to see the rotation

    // Call sortedSearch to get the sorted array and index
    tuple<vector<int>, int> result = sortedSearch(a, target);

    // Extract the sorted array and index from the tuple
    vector<int> sortedArray = get<0>(result);
    int index = get<1>(result);

    // Print the sorted array
    cout << "Sorted array is: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;

    // Print the index of the target
    cout << "Index of target " << target << " is: " << index << endl;

    return 0;
}
