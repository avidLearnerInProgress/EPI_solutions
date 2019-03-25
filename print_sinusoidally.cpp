//Compute all valid IP addresses 
//https://ide.geeksforgeeks.org/qb3an4qBPm

#include<bits/stdc++.h>
using namespace std;

string printss(const string& s){
    string res = "";
    
    for(int i=1; i<s.size(); i+=4) res += s[i];
    for(int i=0; i<s.size(); i+=2) res += s[i];
    for(int i=3; i<s.size(); i+=4) res += s[i];
    
    return res;
}

int main(){
    string s;
    cin>>s;
    string v=printss(s);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<"";
}