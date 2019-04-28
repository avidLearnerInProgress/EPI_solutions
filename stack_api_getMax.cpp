//getMax() in O(1)
//https://ide.geeksforgeeks.org/c6ibye3hOF

#include <bits/stdc++.h>
using namespace std;

struct Combined{
  int maxEle;
  int Ele;
};
stack<Combined> myst;

bool Empty(){
    if(myst.empty())return true;
    else return false;
}

void Top(){
    if(!Empty()){
        int top = myst.top().Ele;
     //   myst.pop();
        cout<<"Top of ST is:- "<<top<<"\n";
    }
    else{
        cout<<"ST is empty.."<<"\n";
        return;
    }
}

int Max(){
    if(!Empty()) return myst.top().maxEle;
}

void Push(int p){
    if(Empty()){
        myst.emplace(Combined{p, p});
    }   
    else{
        myst.emplace(Combined{p, max(p, Max())});
    }
}

int Pop(){
    if(!Empty()){
        int top = myst.top().Ele;
        myst.pop();
        cout<<"Popped from ST is:- "<<top<<"\n";
    }
    else{
        cout<<"ST is empty.."<<"\n";
        return 0;
    }
}

int main(){

    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);
    Pop();
    Top();
    Push(80);
    cout<<Max()<<"\n";
    Pop();
    cout<<Max()<<"\n";
    
}
