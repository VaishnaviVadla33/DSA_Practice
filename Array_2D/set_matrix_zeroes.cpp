#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
using namespace std; 

class Solutions{
public:
void setZeroes(vector<vector<int>>& matrix){ // m-> number of rows, n-> number of columns
    int m=matrix.size();
    int n=matrix[0].size();
    int top=0;int buttom=m-1;
    int left=0;int right=n-1; 
    int x;
    int y;

    while(top<=buttom && left<=right){
        for(int i=top;i<=buttom;i++){
            for(int j=left;i<=right;j++){
                if(matrix[i][j]==0){
                    int x=i;
                    int y=j;
                }
            }
        }
        cout<<x<<y;
}
};

int main(){
    Solutions sol;
    return 0;
}