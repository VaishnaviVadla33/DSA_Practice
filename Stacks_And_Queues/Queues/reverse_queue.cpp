#include <iostream>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

//to print queues
void print(queue<int> Queue){   //void reverse(queue<int>& Queue) in this method passing address completely deletes queuue address while poping so next/second time wec cannot print elements again, so instead pass by value
    while(!Queue.empty()){
        cout<<Queue.front()<<" ";
        Queue.pop();
    }
}

//to reverse queue
void reverse(queue<int>& Queue){  
    stack<int> stackk;
    while(!Queue.empty()){
        stackk.push(Queue.front());
        Queue.pop();
    }
    while(!stackk.empty()){
        Queue.push(stackk.top());
        stackk.pop();
    }
}

int main(){
    queue<int> que1;
    que1.push(1);
    que1.push(2);
    que1.push(3);
    que1.push(4);
    que1.push(5);

    cout<<"Before reversing:"<<endl;
    print(que1);
    cout<<endl;
    
    cout<<"After reversing:"<<endl;
    reverse(que1);
    print(que1);
    cout<<endl;

    return 0;
}