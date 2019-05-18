//queue-with-max-api
//https://ide.geeksforgeeks.org/kHJhZWMtme


#include<bits/stdc++.h>
using namespace std; 

queue<int> Q;
deque<int> D;

void Enqueue(int x){
    //
    Q.push(x);
    while(!D.empty()){
        if(D.back() >= x) break;
        D.pop_back(); //keep removing elements until last ele in D is >= x
    }
    D.push_back(x);
}


int Dequeue(){
    
    int front;
    if(!Q.empty()){
        front = Q.front();
        if(front == D.front()){
            D.pop_front();
        }
        Q.pop();
        return front;
    }
    else{
        return INT_MAX;
    }
}

int max(){
    if(!D.empty()) return D.front();
    else return INT_MAX;
}



int main(){
    
    for(int i=10; i<50; i+=10)
        Enqueue(i);
        
    cout<<Dequeue()<<" ";
    Enqueue(50);
    cout<<Dequeue()<<" ";
    cout<<max()<<"\n";
    cout<<Dequeue()<<" ";
    cout<<max()<<"\n";
    Enqueue(20);
    cout<<Dequeue()<<" ";
}
