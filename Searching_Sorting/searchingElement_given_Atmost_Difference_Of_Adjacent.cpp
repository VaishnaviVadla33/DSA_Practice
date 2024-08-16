#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
    int searching(vector<int> & inputArray, int k, int x){
        if(inputArray[0]==x){
            cout<<"Target found at index:"<<0;
            return 0;
        }
        int i=0;
        while(inputArray[i]!=x){
            int diff=abs(inputArray[i]-x);
            i=i+max(1,diff/k);
            if(inputArray[i]==x){
                cout<<"Target found at index:"<<i;
                return i;
            }
        }
    }
};

int main(){
    solution s;
/*vector<int> inputArray={20,40,50,70,70,60};
int k=20;
int x=60;
int result=s.searching(inputArray,k,x);*/

vector<int> inputArray={4, 5, 6, 7, 6};
int k=1;
int x=6;
int result=s.searching(inputArray,k,x);
}