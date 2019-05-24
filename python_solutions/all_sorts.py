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

#############-----------------------#############
def binarySearch(arr, value, low, high):
    if high <= low:
        return (low + 1) if value > arr[low] else low;
    mid = int((low + high)/2)

    if value == arr[mid]:
        return mid + 1
    elif value > arr[mid]:
        return binarySearch(arr, value, mid + 1, high)
    else:
        return binarySearch(arr, value, low, mid - 1)    

def binaryInsertionSort(arr):

    for i in range(1, len(arr)):
        value = arr[i]
        j = i - 1
        loc = binarySearch(arr, value, 0, j)

        while j >= loc:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = value
    return arr

def callBinaryInsertionSort():
    print(binaryInsertionSort([4, 3, 2, 9, 10]))

#############-----------------------#############

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

#############-----------------------#############
#https://ide.geeksforgeeks.org/ZZaMfOyMF4

def selectionSort(A):
    for i in range(len(A)):
        min_idx = i
        for j in range(i + 1, len(A)):
            if A[j] < A[min_idx]:
                min_idx = j
    
        A[i], A[min_idx] = A[min_idx], A[i]
    return A

def callSelectionSort():
    A = [10, 80, 60, 40, 90, 30, 70]
    print(selectionSort(A))

#############-----------------------#############
def bubbleSort(A):

    for i in range(len(A)):
        for j in range(i + 1, len(A)):
            if A[i] >= A[j]:
                A[i], A[j] = A[j], A[i]
    return A

def callBubbleSort():
    A = [10, 80, 60, 40, 90, 30, 70]
    print(bubbleSort(A))


if __name__ == "__main__":
    callInsertionSort()
    callQuickSort()
    callBinaryInsertionSort()
    callSelectionSort()
    callBubbleSort()