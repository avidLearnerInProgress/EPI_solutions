#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


bool getParity(int n) 
{ 
    bool parity = 0;
    while(n){
	    n = n & (n-1);
	    parity = !parity;
    }
    return parity;
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
	        if(getParity(n))
	            cout<<"odd\n";
	        else
	            cout<<"even\n";
        }
	return 0;
}
