iarr = [4,3,2,1]
darr = [1,2,3,4]


def bubbleSortInc(arr):
    n = len(arr)
    for k in range(n-1): 
        for i in range(0,n-1-k): 
            if(arr[i] > arr[i+1]):
                arr[i],arr[i+1] = arr[i+1],arr[i]
    return arr


def bubbleSortDec(arr):
    n = len(arr)
    for k in range(n-1):
        for i in range(0,n-1-k):
            if(arr[i] < arr[i+1]):
                arr[i],arr[i+1] = arr[i+1],arr[i]
    return arr

print(bubbleSortInc(iarr))
print(bubbleSortDec(darr))