#include <iostream>
#include <climits>
using namespace std;

int MaxSubarraySum(int a[],int n){
    int max_sum_sofar=INT_MIN;
    int max_ending_sum=0;
    int i;
    for(i=0;i<n;i++){
        max_ending_sum=max_ending_sum+a[i];
        if (max_sum_sofar<max_ending_sum){
            max_sum_sofar=max_ending_sum;
        }
        if(max_ending_sum<0){
            max_ending_sum=0;
        }
        
        }
        return max_sum_sofar;
    }

int main()
{
    int a[]={-2,1,-3,4,-1,2,1,-5};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"Max sub array sum is:"<<MaxSubarraySum(a,n);
}
