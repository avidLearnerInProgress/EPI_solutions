//test palindromicity
//https://ide.geeksforgeeks.org/4ub5d3xsVm

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()
{
    string s; cin>>s;
    int i=0, j=s.size() - 1;
    bool flag = true;
    while(i < j){
        while(!isalnum(s[i]) && i < j) ++i;
        
        while(!isalnum(s[j]) && i < j) --j;
        
        if(islower(s[i++]) != islower(s[j--])){
            flag = false;
        }
    }
    if(flag) cout<<"palindrome"<<"\n";
    else cout<<"non-palindrome"<<"\n";
    
    
}
