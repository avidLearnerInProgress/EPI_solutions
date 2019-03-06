//https://ide.geeksforgeeks.org/EHhY3xb3IS
//rearrange elements in array variant 1
#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()
 {
	//code
	    
    FAST_INP;
    int T;
    cin>>T;
    while(T--)
    { 
        int n; cin>>n;
        vector<int> v(n);
        vector<int> c(n);
        
        for(int i=0; i<n; i++){
            cin>>v[i]; 
        }
        
        /*for(int i=0; i<n; i++){
            cin>>ind[i]; 
        }*/
        
        for(int i=0; i<n; i++){
            c[v[i] - 1] = i + 1;
            
        }
        
        for(int i=0; i<n; i++){
            cout<<c[i]<<" ";
        }
        /*cout<<"\n";
        for(int i=0; i<n; i++){
            cout<<ind[i]<<" ";
        }*/
        
    }
}
