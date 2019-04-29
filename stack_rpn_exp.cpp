//RPN Expression
//https://ide.geeksforgeeks.org/3TVJxK0rkr

#include <bits/stdc++.h>
using namespace std;

int RPNExpression(string &s){
    
    stack<int> x;

	for(int i=0; i<s.length(); i++){
        if(s[i] == "*" || s[i] == "/" || s[i] == "+" || s[i] == "-"){
            int m = x.top();
            x.pop();
            int n = x.top();
            x.pop();
            
            if(s[i] == '+')
                x.push(m + n);
            else if(s[i] == '-')
                x.push(m - n);
            else if(s[i] == '*')
                x.push(m * n);
            else if(s[i] == '/')
                x.push(m / n);
            }
        else{
            x.push(stoi(s[i]));
        }
	}
    cout<<x.top()<<"\n";
}


int main() {
    string y = "34+2x1+";
    RPNExpression(y);
	return 0;
}
