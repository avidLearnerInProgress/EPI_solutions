//delete duplicates from sorted array

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int validEnteries(vector<int> *A_ptr){
    vector<int> &A = *A_ptr;
    int j = 0;
    for(int i=0; i< A.size() - 1; i++){
      if(A[i] != A[i+1]){
          A[j++] = A[i];
      }
    }
    A[j++] = A[A.size()-1];
    //for(int i=0; i<A.size();i++)cout<<A[i]<<" ";
    return j; //returns last valid entry after which 0's have to be inserted
}

int main()
 {
	//code
        FAST_INP;
        int T;
        cin>>T;
        while(T--)
        {   
              int m; cin>>m;
              if(m == 0) return 0;
              
              vector<int> A(m);
              
              for(int i=0; i<m; i++)
                  cin>>A[i];
              
              int ind = validEnteries(&A);
              cout<<"\n"<<ind<<"";
                
             for(int i=ind; i<m; i++)
                  A[i] = 0; //remaining enteries
              
             for(int i=0; i<A.size(); i++)
                  cout<<A[i]<<" ";
              
        }
}
