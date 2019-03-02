//https://ide.geeksforgeeks.org/egew3jtW3j
//dutch national flag problem

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
            int n, pivot;
            cin>>n>>pivot;
            vector<int> A(n);
            for(int i=0; i<n; i++)cin>>A[i];
            
            //int pivot_ele = A[pivot]; //0 based
            int smallest = 0, current = 0, largest = n - 1;
            
            while(current < largest){
                if(A[current] < A[pivot]){
                    swap(A[smallest], A[current]);
                    smallest++; current ++;
                }
                else if(A[current] == A[pivot])
                    current++;
                else{
                    swap(A[current], A[largest]);
                    current++; largest--;
                }
            }
            
            for(int i=0; i<n; i++)cout<<A[i]<<" ";
        }
	return 0;
}
