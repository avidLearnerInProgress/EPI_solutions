//https://ide.geeksforgeeks.org/yVoA0hzepN
//buy sell stock once

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

/*double min(double a, double b){
    return a<b ? a:b;
}*/

int main()
 {
	//code
        FAST_INP;
        int T;
        cin>>T;
        while(T--)
        {   
            int n; cin>>n;
            vector<double> prices(n);
            for(int i=0; i<n; i++) cin>>prices[i];
            
            vector<double> track_first_max_profit(n); //TO track the profit of first pass
            
            double min_seen_so_far = numeric_limits<double>::max(), max_profit = 0;
            double max_seen_so_far = numeric_limits<double>::min(), max_total_profit = 0;
            
            for(int i=0; i<prices.size(); i++){
                double max_profit_today = prices[i] - min_seen_so_far;
                cout<<max_profit_today<<"|";
                max_profit = max(max_profit_today, max_profit);
                track_first_max_profit[i] = max_profit;
                min_seen_so_far = min(prices[i], min_seen_so_far);
            }
            
            for(int i=n-1; i>0; i--){
                max_seen_so_far = max(max_seen_so_far, prices[i]);
                max_total_profit = max(max_seen_so_far - prices[i] + track_first_max_profit[i-1],max_total_profit);
            }
            cout<<"\nMax profit: "<<max_total_profit<<"\n";
        }
}
