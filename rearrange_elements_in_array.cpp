//https://ide.geeksforgeeks.org/nTZdBD2Pny
//rearrange elements in list

#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<int> A, int n){
    int i = 0, j = n - 1;
    while(i < j){
        if(A[i] %2 == 0) i++;
        else
        {
            swap(A[i], A[j]);
            j--;
        }
    }
    for(int i=0; i<n; i++)cout<<A[i]<<" ";
}

int main(){
    
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; i++)cin>>A[i];
    
    rearrange(A, n);
    
}
