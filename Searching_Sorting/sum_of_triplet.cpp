#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
    int countingsort(vector<int> & inputArray, int sum){
        int n = inputArray.size();
        int count=0;
        for(int i=0;i<n-2;i++){                             //for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){                          //for(int j=;j<n;j++){
                for(int k=j+1;k<n;k++){                      //for(int k=0;k<n;k++){        keeping this logic make repeated calculation leading wrong count , so instead use current one
                    if((inputArray[i]+inputArray[j]+inputArray[k])<sum){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main(){
    solution s;
    vector<int> inputArray={-2, 0, 1, 3};
    int sum=2;
    int result=s.countingsort(inputArray,sum);
    cout<<"Count triplets with sum smaller than a given value is:"<<endl;
    cout<<result;
}
