//https://ide.geeksforgeeks.org/a8MTMemeSg
//dutch national flag problem - variant 1

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<char> Keys = {'A', 'B', 'C'};

void dutchNationalFlagV1(vector<char> A, int n){
            int smallest = 0, current = 0, largest = n - 1;
            
            while(current < largest){
                if(A[current] == Keys[0]){
                    swap(A[smallest], A[current]);
                    smallest++; current ++;
                }
                else if(A[current] == Keys[1])
                    current++;
                else{
                    swap(A[current], A[largest]);
                    current++; largest--;
                }
            }
            
            for(int i=0; i<n; i++)cout<<A[i]<<" ";
            
            
}

int main()
 {
	//code
	    
        FAST_INP;
        int T;
        cin>>T;
        while(T--)
        { 
            int n; cin>>n;
            vector<char> A(n);
            for(int i=0; i<n; i++)cin>>A[i];
            dutchNationalFlagV1(A, n);
        }
	return 0;
}
