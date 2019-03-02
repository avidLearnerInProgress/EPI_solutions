//https://ide.geeksforgeeks.org/EIsdA1Bqh5
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
              
              int curr_max = A[0];
              int steps = A[0];
              int jumps = 1;
              int i = 1;
              
              for(int i=1; i<m; i++){
                  if(i == m-1) cout<<jumps;
                  curr_max = max(curr_max, i + A[i]);
                  steps--;
                  if(steps == 0){
                      jumps++;
                      if(i >= curr_max) cout<<-1;
                      steps = curr_max - i;
                  }
              }
              
        }
}
