//https://ide.geeksforgeeks.org/aqbILcstou
//increment arbitary precision integer

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
            vector<int> A(n);
            for(int i=0; i<n; i++)cin>>A[i];
            int i;
            A.back()++; //increment last digit
            for(i = A.size() - 1; i > 0 && A[i] == 10; i--){
                A[i] = 0;
                A[i - 1] ++;
            }
            
            //Now we are at the beginning of vector
            if(A[i] == 10){
                A[i] = 0;
                A.insert(A.begin(), 1);
            }
            for(int i=0; i<A.size(); i++){
                cout<<A[i]<<" ";
            }
        }
	return 0;
}
