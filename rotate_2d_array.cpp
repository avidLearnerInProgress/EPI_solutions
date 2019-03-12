//rotate an array inplace by 90 degree
//https://ide.geeksforgeeks.org/3qlUyTvXzi
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
            for(int j=0; j<n;j ++){
                cin>>Rotate[i][j];
            }
        }
        
        for(int i=0; i<n/2; i++){
            for(int j=i; j<n-i-1; j++){
                int temp = Rotate[i][j];
                Rotate[i][j] = Rotate[j][n-i-1];
                Rotate[j][n-i-1] = Rotate[n-i-1][n-j-1];
                Rotate[n-i-1][n-j-1] = Rotate[n-j-1][i];
                Rotate[n-j-1][i] = temp;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n;j ++){
                cout<<Rotate[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
 }
