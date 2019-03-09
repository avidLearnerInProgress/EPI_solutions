//generate spiral traversal of array in increasing order
//https://ide.geeksforgeeks.org/TTITPZmqkv
#include<bits/stdc++.h>
using namespace std;

#define n 4
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int val = 1;

void printRight(int Spiral[n][n], int rnum, int cStart, int cEnd ){
    for(int i=cStart; i<cEnd; i++)
        Spiral[rnum][i] = val++;
}

void printDown(int Spiral[n][n], int cnum, int rStart, int rEnd ){
    for(int i=rStart; i<rEnd; i++)
        Spiral[i][cnum - 1] = val++;
}


void printLeft(int Spiral[n][n], int rnum, int cStart, int cEnd ){
    for(int i=cStart - 1; i>=cEnd; i--)
        Spiral[rnum - 1][i] = val++;
}

void printTop(int Spiral[n][n], int cnum, int rStart, int rEnd ){
    for(int i=rStart- 1; i>=rEnd; i--)
        Spiral[i][cnum] = val++;
}

void printSpiral(int Spiral[n][n], int row, int col){
    
    int cStart = 0, cEnd = col;
    int rStart = 0, rEnd = row;
    
    while(cStart < cEnd && rStart < rEnd){
        printRight(Spiral, rStart++, cStart, cEnd);
        printDown(Spiral, cEnd--, rStart, rEnd);
        printLeft(Spiral, rEnd--, cEnd, cStart);
        printTop(Spiral, cStart++, rEnd, rStart);
        
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
        int Spiral[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n;j ++){
                cin>>Spiral[i][j];
            }
        }
        printSpiral(Spiral, n, n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n;j ++){
                cout<<Spiral[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
 }
