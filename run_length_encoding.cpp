//run length encoding;
//https://ide.geeksforgeeks.org/Ty2FLOcZ3T

#include <bits/stdc++.h> 
using namespace std; 

void printRLE(string str) 
{ 
	int n = str.length(); 
	for (int i = 0; i < n; i++) { 

		// Count occurrences of current character 
		int count = 1; 
		while (i < n - 1 && str[i] == str[i + 1]) { 
			count++; 
			i++; 
		} 
		// Print character and its count 
		cout << str[i] << count; 
	} 
} 

int main() 
{ 
	string str;
	cin>>str;
	printRLE(str); 
	return 0; 
} 

