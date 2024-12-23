#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class kadaneAlgo{
    public:
     int max_so_far_func(vector<int>& nums){
        int n=nums.size();
        int max_so_far=INT_MIN;
        int max_ending_here=0;
        for(int i=0;i<n;i++){
            if((max_ending_here+nums[i])>nums[i]){
                max_ending_here=max_ending_here+nums[i];
            }
            else{
                max_ending_here=nums[i];
            }
        max_so_far=max_ending_here>max_so_far?max_ending_here:max_so_far;
        }
        
        return max_so_far;
     }
};

int main(){
    kadaneAlgo a;
    vector<int> nums={ -2, -3, 4, -1, -2, 1, 5, -3 };
    int max_sum=a.max_so_far_func(nums);
    cout<<"Maximum sum is: "<<max_sum;
}
