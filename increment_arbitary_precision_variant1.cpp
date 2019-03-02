//https://ide.geeksforgeeks.org/7D30KCqnDN
//increment arbitary precision number - variant 1

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
            string x, y;
            //1 0 1 1
            //0 1 1 1
            cin>>x>>y;
            int i, sum_of_bits;
            int m = x.length(), n = y.length(); //find greatest and set the loop via greatest
            i = (m >= n) ? m : n;
            //cout<<i;
            string z; z.resize(i);
            //cout<<z.length();
            int varying = abs(m - n);
            if(m > n)
                y = y.insert(0, varying, '0'); 
            else if(m < n)
                x = x.insert(0, varying, '0'); 
            else{}    
            
            for(int j=i-1; j>0; j--){
                //cout<<j;
                int first = x[j] - '0';
                int second = y[j] - '0';
                sum_of_bits = first + second;
                //cout<<sum_of_bits;
                if (sum_of_bits == 0) z[j] = '0';
                else if (sum_of_bits == 1 ) z[j] = '1';
                else if(sum_of_bits == 2){
                    z[j] = '0';
                    //cout<<z[j];
                    char tmp = x[j-1];
                    int inc = (tmp - '0') + 1;
                    x[j-1] = char(inc + '0');
                }
                else if(sum_of_bits == 3) {
                    z[j] = '1';
                    char tmp = x[j-1];
                    int inc = (tmp - '0') + 1;
                    x[j-1] = char(inc + '0');
                };
            }   
            //if([0] == '2' || z[0] == '3'){
            //  z[0] = '1';
              //z.insert(z.begin(), 1);
              //string tmp = '1'+ z;
              //cout<<tmp;
            //} 
            //else if(z[0] == '1');
             //   cout<<z<<"";
            int first = x[0] - '0';
            int second = y[0] - '0';
            sum_of_bits = first + second;
            if(sum_of_bits == 1){
                string final = "1" + z;
                cout<<final;
            }
            else if(sum_of_bits == 2){
                string final = "11" + z;
                cout<<final;
            }
            else if(sum_of_bits == 3){
                string final = "11" + z;
                cout<<final;
            }
            else{
                string final = "0" + z;
                cout<<final;
            }
                
        }
}
