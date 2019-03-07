//https://ide.geeksforgeeks.org/yheZzAKMTH
//next greatest permutation

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
        int n;
        cin>>n;
        vector<int> a(n);
        
        for(int j=0; j<n; j++)cin>>a[j];
        
        int i = a.size() - 2;
        while(i>=0 && a[i] >= a[i+1]) i--;
        if(i == -1) return 0;
        
        /*if(a[i] < a[i+1]){
            int got_it = a[i];
            int ind = i;
        }*/
        
        /*Lambda functions in C++: https://stackoverflow.com/a/7627218/4588867*/
        /*int find = *find_if(a.rbegin(), a.rend(), [&](int x){ return x > a[i]; }); 
        swap(find, got_it);*/
        
        swap(*find_if(a.rbegin(), a.rend(), [&](int x){ return x > a[i]; }), a[i]);
        reverse(a.begin() + i + 1, a.end());
        
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        
    }
 }
