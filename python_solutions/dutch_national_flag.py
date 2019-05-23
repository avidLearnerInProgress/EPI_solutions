RED, WHITE, BLUE = range(3)

def dutch_flag_partition(A):

    smallest, current, largest = 0, 0, len(A) - 1
    while current <= largest:
        if A[current] == RED:
            A[smallest], A[current] = A[current], A[smallest]
            smallest += 1
            current += 1
        elif A[current] == WHITE:
            current += 1
        else:
            A[largest], A[current] = A[current], A[largest]
            largest -= 1
    return A

print(dutch_flag_partition([0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]))

