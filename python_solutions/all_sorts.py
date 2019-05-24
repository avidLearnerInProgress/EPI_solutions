#code
#https://ide.geeksforgeeks.org/RA1ODIyN5h
def insertionSort(A):
    for i in range(1, len(A) - 1):
        value, hole = A[i], i
        while hole > 0 and A[hole - 1] > value:
            A[hole] = A[hole - 1]
            hole -= 1 
        A[hole] = value
    
    return A

def callInsertionSort():
    print(insertionSort([4, 3, 2, 9, 10]))

#https://ide.geeksforgeeks.org/ub0kWiG01z
def lomutoPartition(A, low, high):
    pivot = A[high]
    i = low - 1
    for j in range(low, high):
        if A[j] <= pivot:
                i += 1
                A[i], A[j] = A[j], A[i]
    A[i + 1], A[high] = A[high], A[i + 1]
    return i + 1

def quickSort(A, low, high):    
    if low < high:
        p = lomutoPartition(A, low, high)
        quickSort(A, low, p - 1)
        quickSort(A, p + 1, high)
    return A

def callQuickSort():
    A = [10, 80, 60, 40, 90, 30, 70]
    low, high = 0, len(A) - 1
    print(quickSort(A, low, high))

def callMergeSort():
    pass

if __name__ == "__main__":
    callInsertionSort()
    callQuickSort()