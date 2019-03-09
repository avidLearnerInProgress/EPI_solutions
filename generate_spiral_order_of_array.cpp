//Reverse spiral order traversal of Array
//https://ide.geeksforgeeks.org/sFUw7Lqsr3
#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void generateSpiral(int n){
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            int x = min(min(i, j), min(n-1-i, n-1-j));
            if(i<=j){
                auto v = (n-2*x)*(n-2*x) - (i-x) - (j-x);
                cout<<v<<" ";
            }
            else{
                auto u = (n-2*x-2)*(n-2*x-2) + (i-x) + (j-x);
                cout<<u<<" "; 
            }
        }
        cout<<endl;
    }
}


int main(){
    int n; cin>>n;
    generateSpiral(n);
}

