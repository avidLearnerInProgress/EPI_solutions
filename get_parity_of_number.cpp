//get parity of number
//https://ide.geeksforgeeks.org/Ap0nT8mZKf

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef unsigned long long ll;

bool getParity(int n) { 
    bool parity = 0;
    while(n){
	    n = n & (n-1);
	    parity = !parity;
    }
    return parity;
}

bool getParityV1(int n){
    int result = 0;
    while(n){
        result ^= (n & 1);
        n = n >> 1;
    }
    return result;
}

/*
If we break a number S into two parts S1 and S2 such S = S1S2. If we know parity of S1 and S2, we can compute parity of S using below facts :
    If S1 and S2 have the same parity, i.e. they both have an even number of bits or an odd number of bits, their union S will have an even number of bits.
    Therefore parity of S is XOR of parities of S1 and S2
*/

//Lookup table generator
#define P2(n) n, n^1, n^1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
#define LOOKUP P6(0), P6(1), P6(1), P6(0)

bool getParityV2(int n){

    bool parity_table[256] = {LOOKUP};
    int total_sz = 16;

    while(total_sz >= 8){
        n = n ^ (n >> total_sz);
        total_sz /= 2;
    }
    return parity_table[n & 0xff]; //0xff --> 11111111 
}

int getParityV3(ll n){
	n = n ^ (n >> 32);	
	n = n ^ (n >> 16);
	n = n ^ (n >> 8);
	n = n ^ (n >> 4);
	n = n ^ (n >> 2);
	n = n ^ (n >> 1);
	return n & 1;
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
            cout<<getParityV1(n)<<"\n";

            int num = 184346774; 
            cout<<getParityV2(num)<<"\n";
            cout<<getParityV3(num)<<"\n";
        }
	return 0;
}
