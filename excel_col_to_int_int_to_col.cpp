//Excel column to number and vice a versa
//A - 0, B - 1, ...
//https://ide.geeksforgeeks.org/xgInOXFqRp
#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int colToNumber(string x){
        int res = 0;
        for(int i=0; i<x.size(); i++){
            res *= 26;//if A starts from --> '0' then mod 25 else if A starts from '1'
            res += x[i] - 'A' + 1;
        }
        
    return res;
}

string numberToCol(int y){
    
    string n = "";
    int c = 0;
    while(y > 0){
        
        int rem = y%26;cout<<rem<<" ";
        if(rem == 0){
            n += 'Z';
            y = y/26 - 1;
        }
        else{
            n += (rem - 1) + 'A';
            y = y/26;
        }
    c++;
    }
    
    n += '\0';
    
    reverse(n.begin(), n.end());
    
    return n;
}

int main()
 {
	//code
    FAST_INP;
    int T;
    cin>>T;
    while(T--)
    {

        string s; cin>>s;
        int x; cin>>x;
        int n = s.size();
        cout<<colToNumber(s)<<"\n";
        cout<<numberToCol(x)<<"\n";
    }
     
 }
