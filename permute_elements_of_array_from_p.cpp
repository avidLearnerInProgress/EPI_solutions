//https://ide.geeksforgeeks.org/5JOqgYXtlR
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
        vector<int> ind(n);
        
        for(int i=0; i<n; i++){
            cin>>v[i]; 
        }
        
        for(int i=0; i<n; i++){
            cin>>ind[i]; 
        }
        
        for(int i=0; i<n; i++){
            
            while(ind[i] != i){
                int change_ind = ind[ind[i]];
                int change_val = v[ind[i]];
                
                int curr_ind = ind[i];
                int curr_val = v[i];
                
                ind[ind[i]] = curr_ind;
                v[ind[i]] = curr_val;
                
                ind[i] = change_ind;
                v[i] = change_val;
            }
        }
        
        for(int i=0; i<n; i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        for(int i=0; i<n; i++){
            cout<<ind[i]<<" ";
        }
        
    }
}
