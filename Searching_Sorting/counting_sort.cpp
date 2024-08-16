#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
    vector<int> countingsort(vector<int> & inputArray){
        int max1=0;
        int n= inputArray.size();
        int i;
        for(i=0;i<n;i++){
            max1=max(max1,inputArray[i]);           
        }
        cout<<"maximum number is:"<<max1<<endl;
        vector<int> countArray(max1+1,0);

        for(i=0;i<=max1;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(inputArray[j]==i){
                    count++;
                }
            }
            countArray[i]=count;
        }
        //return countArray;
        vector<int> countArray1(max1+1,0);
        countArray1[0]=countArray[0];
        for(i=1;i<=max1;i++){
            countArray1[i]=countArray[i]+countArray1[i-1];
        }
        vector<int> outputArray(n,0);
        for(i=n-1;i>=0;i--){
            int x=inputArray[i];
            int index=countArray1[x];
            outputArray[index-1]=x;
            countArray1[x]--;              
        }
    return outputArray;
    }
};

int main(){
    vector<int> inputArray={2,5,3,0,2,3,0,3};
    solution s;
    vector <int> results=s.countingsort(inputArray);
    for (auto val:results){
        cout<<val<<" ";
    }
}