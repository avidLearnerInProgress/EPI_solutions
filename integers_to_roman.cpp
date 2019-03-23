//Convert from Integers to Roman numbers
//https://ide.geeksforgeeks.org/985mQo9jby

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


/*
        //{ {1, 2, 3, 4, 5, 6, 7, 8, 9},
        //  {10, 20, 30, 40, 50, 60, 70, 80, 90},
        //  {100, 200, 300, 400, 500, 600, 700, 800, 900},
        //  {1000, 2000, 3000} }

*/

int main()
 {
	//code
	
        FAST_INP;
        int T;
        cin>>T;
        while(T--)
        { 
            string roman[4][10] = {{"0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                               {"0", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                               {"0", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                               {"0", "M", "MM", "MMM"}};
            //Start from thousand's place                               
            int x;cin>>x;
            string res = "";
            int k = 1000; //reduce it at every iteration
            for(int i=3; i>=0; i--){
                
                if(x/k != 0){
                    res += roman[i][x/k];
                }
                x %= k;
                k/=10;
            }
            cout<<res<<"\n";
        }
 }

