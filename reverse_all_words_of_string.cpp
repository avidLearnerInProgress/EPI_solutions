//reverse all the words of string
//https://ide.geeksforgeeks.org/QcJrOsnfov

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()
{
    string s;
    getline(cin>>ws, s); //important --> reads whitespace
    
    reverse(s.begin(), s.end());
    size_t start = 0, end;
    while((end = s.find(" ", start))!= string::npos){
        reverse(s.begin() + start, s.begin() + end);
        start = end + 1;
    }
    reverse(s.begin() + start, s.end());
    cout<<s<<"\n";
    //s.find("to_find_character", next_occurence); next_occurence --> the length upto which you want to ignore the first occurence or upto what the first occurence has occured.
}
