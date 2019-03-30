//run length encoding;
//https://ide.geeksforgeeks.org/ZcuCmesGmt

#include <bits/stdc++.h> 
using namespace std; 

void decoding(string s){
    string res = "";
    int count = 0;
    for(int i=0; i<s.length(); i++){
        if(isdigit(s[i])){
            //count = count * 10 + (s[i] - '0');
            count = s[i] - '0';
        }
        else{
            res.append(count, s[i]);
          //  count = 0;
        }
    }
    cout<<res<<"\n";
}

void encoding(string s){
    string res = "";
    int count = 1;
    
    for(int i=0; i<=s.length()-1; i++){
        if(i+1 == s.length() || s[i] != s[i+1]){ //new character
            res += to_string(count) + s[i];
            count = 1;
        }
        else{ //same character
            count++;
        }
    }
    cout<<res<<"\n";
}

int main() 
{ 
	string str1, str2; //1 for decode , 2 for encode
	cin>>str1>>str2;
	decoding(str1);
	encoding(str2);
	return 0; 
} 

