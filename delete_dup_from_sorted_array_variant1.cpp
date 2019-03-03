//https://ide.geeksforgeeks.org/qnleuyqqnI
//delete duplicates from sorted array - variant 1

#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

/*int binarySearch(vector<int> A, int find){
    
    int left = A.begin(), right = A.end();
    int mid = left + (right - left)/2;
    while(left <= right){
        if(A[mid] == find) return mid;
        else if(find < A[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}*/
int validEnteries(vector<int> *A_ptr, int n){
    vector<int> &A = *A_ptr;
    int j = 0, k = 0, tmp = 0;
    //int location = binarySearch(A, n);
    for(int i=0; i< A.size(); i++){
      if(A[i] == n)
          k++; 
      else 
          cout<<A[i]<<" ";
    }
    
    return A.size() - k; //returns last valid entry after which 0's have to be inserted
}

int main()
 {
	//code
        FAST_INP;
        int T;
        cin>>T;
        while(T--)
        {   
              int m,n; cin>>m>>n;
              if(m == 0) return 0;
              
              vector<int> A(m);
              
              for(int i=0; i<m; i++)
                  cin>>A[i];
              
              int ind = validEnteries(&A, n);
              cout<<"\n"<<ind<<"";
              
        }
}
