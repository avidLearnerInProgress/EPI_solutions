//https://ide.geeksforgeeks.org/eAfrUsdGjm
//check valid sudoku arrangement

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

bool isValidRow(char board[][9], int row){
    set<char> s;
    for(int i=0; i<9; i++){
        if(s.find(board[row][i]) != s.end()) return false;
        if(board[row][i] != '.') s.insert(board[row][i]);
    }
    return true;
}

bool isValidCol(char board[][9], int col){
    set<char> s;
    for(int i=0; i<9; i++){
        if(s.find(board[i][col]) != s.end()) return false;
        if(board[i][col] != '.') s.insert(board[i][col]);
    }
    return true;
}

bool isValidBox(char box[][9], int sRow, int sCol){
    
    set<char> s;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            char current = box[i + sRow][j + sCol];
            if(s.find(current) != s.end()) return false;
            if(current != '.') s.insert(current);
        }
    }
    return true;
}

bool isValidBoard(char board[][9], int row, int col){
    return isValidBox(board, row - row%3, col - col%3) && isValidRow(board, row) && isValidCol(board, col);
}

bool isValidConfig(char board[][9], int n){
        for(int i=0; i<n ;i++){
            for(int j=0; j< n; j++){
                if(!isValidBoard(board, i, j)) return false;
            }
        }
        return true;
}

int main()
 {
	//code
	    
    FAST_INP;
    int T;
    cin>>T;
    while(T--)
    { 
        //int n; cin>>n;
        char board[9][9] = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, 
						{ '6', '.', '.', '1', '9', '5', '.', '.', '.' }, 
						{ '.', '9', '8', '.', '.', '.', '.', '6', '.' }, 
						{ '8', '.', '.', '.', '6', '.', '.', '.', '3' }, 
						{ '4', '.', '.', '8', '.', '3', '.', '.', '1' }, 
						{ '7', '.', '.', '.', '2', '.', '.', '.', '6' }, 
						{ '.', '2', '.', '.', '.', '.', '2', '8', '.' }, 
						{ '.', '.', '.', '4', '1', '9', '.', '.', '5' }, 
						{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };;
        cout<<isValidConfig(board, 9);
    }
 }
