//https://ide.geeksforgeeks.org/yVoA0hzepN
//buy sell stock twice variant 1

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a, b, var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

double min(double a, double b) {
    return a<b ?a:b;
}

int main(){
    
    FAST_INP;
    int n, j; cin>>n;
    vector<int> A(n);
    F(0, n, j) cin>>A[j];
        
    double oneBuy = numeric_limits<double>::max(), twoBuy = numeric_limits<double>::max();
    double oneBuyOneSell = 0, twoBuyTwoSell = 0;
    
    for(int i=0; i<n; i++){
        oneBuy = min(oneBuy, A[i]);
        oneBuyOneSell = max(oneBuyOneSell, A[i] - oneBuy);
        twoBuy = min(twoBuy, A[i] - oneBuyOneSell);
        twoBuyTwoSell = max(twoBuyTwoSell, A[i] - twoBuy);
    }
    cout<<twoBuyTwoSell<<" ";
}

