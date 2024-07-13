#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
using namespace std; 

class Solutions{
public:
vector<int> spiral(vector<vector<int>> &matrix){ // m-> number of rows, n-> number of columns
    int m=matrix.size();
    int n=matrix[0].size();
    int top=0;int buttom=m-1;
    int left=0;int right=n-1; 
    vector<int> results;
    while(top<=buttom && left<=right){
        for(int i=left;i<=right;i++){
            results.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=buttom;i++){
            results.push_back(matrix[i][right]);
        }
        right--;

        if(top<=buttom){
            for(int i=right;i>=left;i--){
                results.push_back(matrix[buttom][i]);
            }
            buttom--;
        }
        if(left<=right){
            for(int i=buttom;i>=top;i--){
                results.push_back(matrix[i][left]);
            }
            left++;
        }

    }
    return results;
}
};

int main(){
    Solutions sol;
    vector<vector<int> > matrix = { { 1, 2, 3, 4 },
                                    { 5, 6, 7, 8 },
                                    { 9, 10, 11, 12 },
                                    { 13, 14, 15, 16 } };
    vector<int> results = sol.spiral(matrix);
    for(int value:results){
        cout<<value<<" ";
    }
    return 0;
}