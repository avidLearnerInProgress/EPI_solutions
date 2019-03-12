//rotate an array inplace by 90 degree
//https://ide.geeksforgeeks.org/A3Qzo6mFII
#include<bits/stdc++.h>
using namespace std;

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
        int Rotate[n][n];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                if(i == j || j==0) Rotate[i][j] = 1;
                else Rotate[i][j] = Rotate[i-1][j-1] + Rotate[i-1][j];
                cout<<Rotate[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
 }
