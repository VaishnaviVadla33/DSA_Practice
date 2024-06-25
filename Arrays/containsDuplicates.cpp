#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 6, 2, 4, 5};
    bool hasDuplicate = solution.containsDuplicate(nums);
    cout << "Contains duplicate: " << (hasDuplicate ? "True" : "False") << endl;

    return 0;
}
