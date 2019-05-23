//reverse actual bits of number
//https://ide.geeksforgeeks.org/AplYMAcwAN

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef unsigned long long ll;

void getReverse(int n){
    
    unsigned int rev = 0;
    while(n > 0){
        rev = rev << 1;
        if(n & 1 == 1)
            rev = rev ^ 1;
        n = n >> 1;
    } 
    cout<<rev<<"\n";
}

int main()
 {
	//code
        FAST_INP;
        int T;
        cin>>T;
        while(T--)
        { 
            int n; cin>>n;
            getReverse(n);
        }
	return 0;
}