//Find first node of overlapping linked list 
//https://ide.geeksforgeeks.org/VfiZD33w8O

#include<bits/stdc++.h>
using namespace std;

/*
3 cases:
a. Both ll are cyclic -->
b. Either one of the ll is cyclic -->
c. None of them is cyclic -->
*/


struct Node{
    int data;
    struct Node* next;
};

Node* newNode(int key) 
{ 
    Node* temp = (struct Node*) malloc(sizeof(struct Node*)); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 

int Length(Node* L){
    int length = 0;
    while(L!=NULL){
        ++length, L = L->next;
    }
    return length;
}

// Advances L by k steps.
void AdvanceListByK(int k, Node** L){
    while(k--){
        *L =(*L)->next;
    }
}

int Distance(Node* a, Node* b){
    int dis = 0;
    while(a->data != b->data){
        a = a->next, ++dis;
    }
    return dis;
}

int OverlappingNoCycleLists(Node* l0, Node* l1){
	cout<<"Hey.."<<"\n";
	int l0_len = Length(l0), l1_len = Length(l1);
	cout<<l0_len<<"\t"<<l1_len<<"\n";
	
	// Advances the longer list to get equal length lists.
	AdvanceListByK(abs(l0_len - l1_len), l0_len > l1_len ? &l0 : &l1);
	
	while(l0->data && l1->data && l0->data != l1->data){
		l0 = l0->next, l1 = l1->next;
	}
	return l0->data;  // nullptr implies there is no overlap between l0 and l1.
}

Node* HasCycle(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast && fast->next){
        slow = slow->next, fast = fast->next->next;
    if(slow == fast){
      // There is a cycle, so now let's calculate the cycle length.
      int cycle_len = 0;
      do{
        ++cycle_len;
        fast = fast->next;
      } while(slow != fast);
    
      // Finds the start of the cycle.
      auto cycle_len_advanced_iter = head;
      while(cycle_len--){
        cycle_len_advanced_iter = cycle_len_advanced_iter->next;
      }
    
      auto iter = head;
      // Both iterators advance in tandem.
      while(iter != cycle_len_advanced_iter){
        iter = iter->next;
        cycle_len_advanced_iter = cycle_len_advanced_iter->next;
      }
      return iter;  // iter is the start of cycle.
    }
  }
}

int OverlappingLists(Node* l0, Node* l1){
    // Store the start of cycle if any.
    cout<<"Inside main.."<<"\n";
    auto root0 = HasCycle(l0), root1 = HasCycle(l1);
    cout<<"Start of cycles are: "<<root0->data<<"\t"<<root1->data<<"\n";
    
    if(!root0 && !root1){
    // Both lists don't have cycles.
        cout<<"Inside case3.."<<"\n";
        return OverlappingNoCycleLists(l0, l1);
    } 
    else if((root0 && !root1) ||(!root0 && root1)){
    // One list has cycle, and one list has no cycle.
        cout<<"Inside case2.."<<"\n";    
        //return nullptr;
        return 0;
    }
    cout<<"Inside case1.."<<"\n";
    // Both lists have cycles.
    auto temp = root1;
    do{
        temp = temp->next;
    }while(temp->data != root0->data && temp->data != root1->data);
    
    // l0 and l1 do not end in the same cycle.
    if(temp->data != root0->data){
        //return nullptr;  // Cycles are disjoint.
        return 0;
    }
    
    // l0 and l1 end in the same cycle, locate the overlapping node if they
    // first overlap before cycle starts.
    int stem0_length = Distance(l0, root0), stem1_length = Distance(l1, root1);
    AdvanceListByK(abs(stem0_length - stem1_length), stem0_length > stem1_length ? &l0 : &l1);
    
    while(l0->data != l1->data && l0->data != root0->data && l1->data != root1->data){
        l0 = l0->next, l1 = l1->next;
    }
    
    // If l0 == l1 before reaching root0, it means the overlap first occurs
    // before the cycle starts; otherwise, the first overlapping node is not
    // unique, so we can return any node on the cycle.
    
    return l0->data == l1->data ? l0->data : root0->data;
   
}

int main() 
{ 
    
  	Node* head1 = newNode(50); 
	head1->next = newNode(20); 
	head1->next->next = newNode(15); 
	head1->next->next->next = newNode(4); 
	head1->next->next->next->next = newNode(10);
	
	head1->next->next->next->next->next = head1->next->next; 
    //printLL(head1);

	Node* head2 = newNode(15); 
	head2->next = newNode(4); 
	head2->next->next = newNode(10);
	head2->next->next->next = head2; 
    
    cout<<"\nFound start of overlapping list: "<<OverlappingLists(head1, head2)<<"\n";
    return 0; 
} 
