//Convert from Roman Numbers to Plain Integers
//https://ide.geeksforgeeks.org/zfKr6PVtzi

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
            map<char, int> rti = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
            
            string x; cin>>x;
            int sum = rti[x.back()];
            for(int i=x.size() - 2; i>=0; i--){
                if(rti[x[i]] < rti[x[i+1]])
                    sum-=rti[x[i]];
                else
                    sum+=rti[x[i]];
            }
            
            cout<<sum<<"\n";
            
        }
 }

