//Compute all valid IP addresses 
//https://ide.geeksforgeeks.org/0QToW8q4m7

#include<bits/stdc++.h>
using namespace std;
bool isvalid(string s){
    if(s.size()>3) return false;
    if(s.front() == '0' && s.size()>1) return false;
    int curr = stoi(s);
    return curr<=255 && curr>=0;
}
vector<string> restoreIpAddresses(string s) {
    vector<string> v;
    string x;
    for(int i=1; i<4 && i<s.size(); i++){
        string A = s.substr(0, i);
        if(isvalid(A)){
            for(int j=1; j<4 && i+j<s.size(); j++){
                string B = s.substr(i, j);
                if(isvalid(B)){
                    for(int k=1; k<4 && i+j+k<s.size(); k++){
                        string C = s.substr(i+j, k);
                        string D = s.substr(i+j+k);
                        if(isvalid(C) && isvalid(D)){
                            v.push_back(A + "." + B + "." + C + "." + D);
                        }
                    }
                }
            }
        }
    }
    return v;
}
int main(){
    string s;
    cin>>s;
    vector<string> v=restoreIpAddresses(s);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
}
