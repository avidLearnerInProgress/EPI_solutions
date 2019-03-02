//https://ide.geeksforgeeks.org/cHBu6QMdQO
//dutch national flag problem - variant 2

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<char> Keys = {'A', 'B', 'C', 'D'};

void dutchNationalFlagV1(vector<char> A, int n){
            int smallest = 0, current = 0, largest = n - 1;
            int s1 = 0, s2 = 0;
            while(current < largest){ 
            // [A, A, A, [_, _, _, _,] D, D, D, D] //This sorts all the A's and D's
                if(A[current] == Keys[0]){
                    s1 = smallest;
                    swap(A[smallest], A[current]);
                    smallest++; current ++;
                } 
                else if(A[current] == Keys[1] || A[current] == Keys[2])
                    current++;
                else{
                    s2 = largest;
                    swap(A[current], A[largest]);
                    largest--;
                } 
            }
            current = smallest = s1++;
            largest = s2--;
            
            while(current < largest){
                // [A, A, A, [_, _, _, _,] D, D, D, D] //This sorts all the _, _, i.e. B and C's
                if(A[current] == Keys[1]){
                    //s1 = smallest;
                    swap(A[smallest], A[current]);
                    smallest++; current ++;
                } 
                else{
                    //s2 = largest;
                    swap(A[current], A[largest]);
                    largest--;
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
