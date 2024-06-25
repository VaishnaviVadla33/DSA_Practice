#include<iostream>
using namespace std;

int minimum(int a[],int n){
    int mini=a[0];
    int i;
    for(i=0;i<=n-1;i++){
        if(mini>a[i]){
            mini=a[i];
        }
    }
    return mini;
}

int maximum(int a[],int n){
    int max=a[0];
    int i;
    for(i=0;i<=n-1;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    return max;
}


int main(){
    int b[]={10,83,51,62,28,5,78,34,78};
    int n = sizeof(b) / sizeof(b[0]);
    int minimum1;
    minimum1=minimum(b, n);
    cout<<"minimum numer is:"<<minimum1<<endl;

    int maximum1;
    maximum1=maximum(b, n);
    cout<<"maximum numer is:"<<maximum1;
    
    return 0;
}