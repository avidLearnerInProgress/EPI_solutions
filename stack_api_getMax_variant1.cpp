//getMax in O(1) time
//https://ide.geeksforgeeks.org/iUUxktagqh

#include<bits/stdc++.h>
using namespace std;

struct MaxStack{
    
    stack<int> myst;
    int maxEle;
    
    void Top(){
        if(!myst.empty()){
            int t = myst.top();
            cout<<"Top ele is:- ";
            (t>maxEle)?cout<<maxEle:cout<<t;
        }
    }
    void Push(int x){
        if(myst.empty()){ myst.push(x); maxEle = x;}
        else{
            if(x>=maxEle){
                myst.push(2*x - maxEle);
                maxEle = x;
            }
        }    
    }

    void Pop(){
        if(myst.empty()){
            cout<<"Empty stack"<<"\n";
            return;
        }
        int top = myst.top();
        myst.pop();
        if(top >= maxEle){
            cout<<maxEle<<"\n";
            maxEle = 2*maxEle - top;
        }
        else
            cout<<top<<"\n";
    }
};

int main(){
    
    MaxStack x;
    x.Push(10);
    x.Push(20);
    x.Push(30);
    x.Push(40);
    x.Pop();
    x.Push(42);
    x.Top();
    
}
