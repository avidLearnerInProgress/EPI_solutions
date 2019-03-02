//advance through array

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
              int m; cin>>m;
              vector<int> A(m);
              
              for(int i=0; i<m; i++){
                  cin>>A[i];
              }
              
              int curr_steps = 0;
              for(int i=0; i<=curr_steps && curr_steps<m; i++){
                  curr_steps = max(curr_steps, A[i] + i);
              }
              if(curr_steps>=m)cout<<"True";
              else cout<<"False";
        }
}
