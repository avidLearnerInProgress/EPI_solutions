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
            string convert;
            cin>>convert;
            int final_sz = 0, curr = 0, dot_cnt = 0, comma_cnt = 0, ques_cnt = 0, exclm_cnt = 0;
            for(int i=0; i<convert.length(); i++){
                if(convert[i] == '.') dot_cnt++;
                else if(convert[i] == ',') comma_cnt++;
                else if(convert[i] == '?') ques_cnt++;
                else if(convert[i] == '!') exclm_cnt++;
                else{}
            }
            int td = dot_cnt;
            int tc = comma_cnt;
            int tq = ques_cnt;
            int te = exclm_cnt;
            
            int write_ind = convert.size() + 1; 
            dot_cnt *= (3 - 1);
            comma_cnt *= (5 - 1);
            ques_cnt *= (8 - 1);
            exclm_cnt *= (11 - 1);

            curr = write_ind - 1;
            write_ind = write_ind + dot_cnt + comma_cnt + ques_cnt + exclm_cnt - 1;
            final_sz = write_ind + 1;
            convert.resize(write_ind);
            cout<<convert.length()<<"\n";
            cout<<write_ind<<"\t"<<curr<<"\t"<<final_sz<<"\t";
            
            while(curr>=0 && convert.length() != -1){
                if(convert[curr] == '.'){
                    convert[write_ind--] = 'T';
                    convert[write_ind--] = 'O';
                    convert[write_ind--] = 'D';
                }
                else if(convert[curr] == '?'){
                    convert[write_ind--] = 'N';
                    convert[write_ind--] = 'O';    
                    convert[write_ind--] = 'I';    
                    convert[write_ind--] = 'T';    
                    convert[write_ind--] = 'S';    
                    convert[write_ind--] = 'E';
                    convert[write_ind--] = 'U';
                    convert[write_ind--] = 'Q';    
                }
                else if(convert[curr] == ','){
                    convert[write_ind--] = 'A';
                    convert[write_ind--] = 'M';    
                    convert[write_ind--] = 'M';    
                    convert[write_ind--] = 'O';
                    convert[write_ind--] = 'C';    
                }
                
                else if(convert[curr] == '!'){
                    convert[write_ind--] = 'N';
                    convert[write_ind--] = 'O';    
                    convert[write_ind--] = 'I';    
                    convert[write_ind--] = 'T';
                    convert[write_ind--] = 'A';    
                    convert[write_ind--] = 'M';    
                    convert[write_ind--] = 'A';    
                    convert[write_ind--] = 'L';    
                    convert[write_ind--] = 'C';    
                    convert[write_ind--] = 'X';    
                    convert[write_ind--] = 'E';    
                }
                
                else{
                    convert[write_ind--] = convert[curr];
                }
                curr--;
            }
            cout<<convert;
        }
	return 0;
}
