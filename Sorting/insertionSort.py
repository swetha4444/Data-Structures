iarr = [0,3,5,1,2]
darr = [1,2,3,4,0]

def insertionSortInc(arr):
    for i in range(1,len(arr)):
        element = arr[i]
        j = i-1
        while(j >= 0 and element < arr[j]):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = element 
    return arr
                

def insertionSortDec(arr):
    for i in range(1,len(arr)):
        element = arr[i]
        j = i-1
        while(j >= 0 and element > arr[j]):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = element 
    return arr

print(insertionSortInc(iarr))
print(insertionSortDec(darr))