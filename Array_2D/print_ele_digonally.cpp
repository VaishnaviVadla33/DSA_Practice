#include <iostream>
#include <bits/stdc++.h> 
#define r 5 
#define c 4 
using namespace std; 

bool valid(int i, int j){
    if (i<0||i>=r||j<0||j>=c){
        return false;
    }
    return true;
}

void diagonal(int arr[][c]){
    for (int k=0;k<r;k++){
        cout<<arr[k][0]<<" ";
        int i=k-1;
        int j=1;

        while(valid(i,j)){
            cout<<arr[i][j]<<" ";
            i--;
            j++;
        }
        cout<<endl;
    }

    for(int k=1;k<c;k++){
        cout<<arr[r-1][k]<<" ";
        int i=r-2;
        int j=k+1;
        while(valid(i,j)){
            cout<<arr[i][j]<<" ";
            i--;
            j++;
        }
        cout<<endl;
    }
}

int main(){
    int arr[][c]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20} };
    diagonal(arr);
}