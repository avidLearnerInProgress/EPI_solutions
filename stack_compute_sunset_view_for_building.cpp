//building having sunset views
//https://ide.geeksforgeeks.org/qnj7qZ0a75

#include<bits/stdc++.h>
using namespace std;

struct B{
    int id, height;
};

int ind = 0;

vector<int> building_with_sunset(vector<int> c){
    
    //keep track of maximum height of building that's it..!
    stack<B> candidates;
    
    for(int i=0; i<c.size(); i++){
        while(!candidates.empty() && c[i] >= candidates.top().height){
            candidates.pop();
        }
        candidates.emplace(B{ind++, c[i]});
    }
    vector<int> bws;
    
    while(!candidates.empty()){
        bws.emplace_back(candidates.top().id);
        candidates.pop();
    }
    return bws;
}


int main(){
    
    vector<int> building_heights = {300, 40, 234, 670, 120};
    vector<int> ids = building_with_sunset(building_heights);
    
    cout<<"Building with id's having sunset view are:\n ";
    for(int i=0; i<ids.size(); i++)
        cout<<ids[i]<<" ";
}
