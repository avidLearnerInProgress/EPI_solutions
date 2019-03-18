//Remove and replace
//https://ide.geeksforgeeks.org/J9YX65mteZ

using namespace std;

int main(){
    
    string x;
    cin>>x;
    
    int i, write_ind = 0, curr_ind = 0, total_sz = 0, a_cnt = 0;
    
    for(i=0; i<x.length(); i++){
        if(x[i] != 'b'){
            x[write_ind] = x[i];
            write_ind++;
        }
        if(x[i] == 'a') a_cnt++;
    }
    curr_ind = write_ind - 1;
    write_ind = write_ind + a_cnt - 1;
    total_sz = write_ind + 1;
    
    while(curr_ind>=0){
        if(x[curr_ind] == 'a'){
            x[write_ind--] = 'd';
            x[write_ind--] = 'd';
        }
        else{
            x[write_ind--] = x[curr_ind];
        }
        curr_ind--;
    }
    
    for(int i=0; i<x.size(); i++)cout<<x[i]<<" ";
    
    cout<<"\n"<<total_sz<<" ";
}
