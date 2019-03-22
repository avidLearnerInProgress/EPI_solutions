//Look and say problem
//https://ide.geeksforgeeks.org/zYlGqG5xZC

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

string generate(string s){
    
    string result = "";
    for(int i=0; i<s.size(); i++){
        int count = 1;
        while(i+1 < s.size() && s[i] == s[i+1]){ i++; count++; }
        result += to_string(count) + s[i];
    }
    return result;
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
            string s = "1";
            vector<string> res;
            for(int i=0; i<n ; i++){
              s = generate(s);
              res.push_back(s);
            } 
            cout<<s<<"\n";
            
            for(int i = 0; i<res.size(); i++)
                cout<<res[i]<<" ";
        }
	return 0;
}
