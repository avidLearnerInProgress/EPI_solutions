RED, WHITE, BLUE = range(3)

def dutch_flag_partition(pivot_ind, A):
    '''pivot = A[pivot_ind]
    smaller = 0
    for i in range(len(A)):
        if A[i] < pivot:
            A[i], A[smaller] = A[smaller], A[i]
            smaller += 1
    larger = len(A) - 1
    for i in reversed(range(len(A))):
        if A[i] < pivot:
            break
        elif A[i] > pivot:
            A[i], A[larger] = A[larger], A[i] 
            larger -= 1      
    return A'''

    small, current, large = 0, 0, len(A) - 1


print(dutch_flag_partition(6, [10, 40, 80, 70, 90, 12, 13]))


'''
  int smallest = 0, current = 0, largest = n - 1;
            
            while(current < largest){
                if(A[current] < A[pivot]){
                    swap(A[smallest], A[current]);
                    smallest++; current ++;
                }
                else if(A[current] == A[pivot])
                    current++;
                else{
                    swap(A[current], A[largest]);
                    current++; largest--;
                }
            }
          
'''