#include<bits/stdc++.h>
using namespace std;


#define n 3
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


void printRight(int Spiral[n][n], int rnum, int cStart, int cEnd ){
    for(int i=cStart; i<=cEnd; i++)
    cout<<Spiral[rnum][i]<<" ";
}

void printDown(int Spiral[n][n], int cnum, int cStart, int cEnd ){
    for(int i=cStart; i<=cEnd; i++)
    cout<<Spiral[i][cnum]<<" ";
}


void printLeft(int Spiral[n][n], int rnum, int cStart, int cEnd ){
    for(int i=cStart; i>=cEnd; i--)
    cout<<Spiral[rnum][i]<<" ";
}

void printTop(int Spiral[n][n], int cnum, int rStart, int rEnd ){
    for(int i=rStart; i>=rEnd; i--)
    cout<<Spiral[i][cnum]<<" ";
}

void printSpiral(int Spiral[n][n], int row, int col){
    
    int cStart = 0, cEnd = col;
    int rStart = 0, rEnd = row;
    
    while(cStart < cEnd && rStart < rEnd){
        printRight(Spiral, rStart++, cStart, cEnd);
        printDown(Spiral, cEnd--, rStart, rEnd);
        printRight(Spiral, rEnd--, cEnd, cStart);
        printRight(Spiral, cStart++, rEnd, rStart);
        
    }
}


int main()
 {
	//code
	    
    FAST_INP;
    int T;
    cin>>T;
    while(T--)
    {
 //       int n; cin>>n;
        int Spiral[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n;j ++){
                cin>>Spiral[i][j];
            }
        }
        printSpiral(Spiral, n-1, n-1);
        
         for(int i=0; i<n; i++){
            for(int j=0; j<n;j ++){
                cout<<Spiral[i][j]<<" ";
            }
            cout<<"\n";
        }
       
               
    }
 }
