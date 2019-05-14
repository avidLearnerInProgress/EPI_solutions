//queue using stack
//https://ide.geeksforgeeks.org/Ac4ADjdOO6

#include<bits/stdc++.h>
using namespace std;

stack<int> s1, s2;

void enq(int x){
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	s1.push(x);
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
}


int deq(){
	
	if(s1.empty())cout<<"Empty";
	int a = s1.top(); s1.pop();
	return a;
}


int main(){
	
	enq(1);	
	enq(2);
	enq(3);
	enq(4);
	cout<<deq()<<"\n";
	cout<<deq();
}
