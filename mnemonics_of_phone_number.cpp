//compute all mnemonics of phone number
//https://ide.geeksforgeeks.org/vzLQgnt2tq

#include <bits/stdc++.h>
using namespace std;

void recurviseSolve(string digits, string cycle, vector<string>& combinations, int start, int n, string mapper[10]){
    
    if(start == n){
        combinations.push_back(cycle);
        return;
    }
    
    int first = digits[start] - '0';
    int len = mapper[first].length();
    
    for(int i=0; i<len; i++){
        recurviseSolve(digits, cycle + mapper[first][i], combinations, start + 1, n , mapper);
    }
}


/* Iterative approach:
vector<string> letterCombinations(string digits) {
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}
*/


int main() {
	
	//int y; cin>>y;
	string digits; cin>>digits;
	/*for(int i=0; i<y; i++)
		cin>>digits[i];
	*/
	string cycle = "";
	
	
	vector<string> combinations;
	string mapper[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	int start = 0, n = digits.length();
	
	recurviseSolve(digits, cycle, combinations, start, n, mapper);
	
	for(string x: combinations) cout<<x<<" ";
	
	
	return 0;
}
