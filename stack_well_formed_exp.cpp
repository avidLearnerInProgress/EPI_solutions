//well formed expression
//https://ide.geeksforgeeks.org/gZs4zkpwNk
#include <bits/stdc++.h>
using namespace std;

bool well_formed(string s){
    
    stack<char> wf;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
            wf.push(s[i]);
        }
        else{
            if(s.empty()) return false;
            if((s[i] == ')' && wf.top() != '(') || (s[i] == '}' && wf.top() != '{') || (s[i] == ']' && wf.top() != '[')){
                return false; //mismatch
            }
            wf.pop(); //ensures that condition is matched!!
        }
    }
    return wf.empty();
}


int main() {
    string y = "{[()]}";
    string z = "{{]]())";
    cout<<well_formed(y)<<"\n";
    cout<<well_formed(z);
	return 0;
}
