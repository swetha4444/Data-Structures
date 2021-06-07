iarr = [0,3,5,1,2]
darr = [1,2,3,4,0]

def selectionSortInc(arr):
    for i in range(len(arr)):
        index =  arr.index(min(arr[i:]))
        arr[i],arr[index] = arr[index],arr[i]
    return arr
                

def selectionSortDec(arr):
    for i in range(len(arr)):
        index =  arr.index(max(arr[i:]))
        arr[i],arr[index] = arr[index],arr[i]
    return arr

print(selectionSortInc(iarr))
print(selectionSortDec(darr))