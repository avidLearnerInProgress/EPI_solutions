//swap bits of number
//https://ide.geeksforgeeks.org/J32n9NwK0Z

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef unsigned long long ll;

int swapbits(int x, int i, int j){
    if((x>>i & 1 ) != (x>>j & 1)){
        ll mask = (1L << i) | (1L << j);
        x = x ^ mask;
    }
    return x;
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
            cout<<swapbits(n, 2, 3)<<" ";
        }
	return 0;
}
