//https://ide.geeksforgeeks.org/6SVGgeDg7X
//Enumerate primes upto n using sieve of Eratosthenes

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()
 {
    FAST_INP;

        int n; cin>>n;
        vector<bool> prime(n+1, true);
        
        for(int i=2; i*i<=n; i++){
            if(prime[i] == true){
                for(int j=i*i; j<=n; j+=i)
                    prime[j] = false;
            }
        }
        for(int i=2; i<=n; i++){
            if(prime[i]) cout<<i<<" ";
        }
    return 0;
 }
