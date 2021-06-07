arr = [4,3,2,1]

def partition(arr,pivot):
    l = 0
    r = len(arr)-1
    while(l < r):
        while(arr[l] < pivot):
            l+=1
        while (arr[r] > pivot):
            r-=1
        arr[l],arr[r] = arr[r],arr[l]
        l+=1
        r-=1
    return l            #division index

def quickSortRec(arr,l,r):
    if(l>=r):
        return arr
    pivot = arr[(l+r)//2]
    index = partition(arr,pivot)
    quickSortRec(arr,l,index-1) #left arr
    quickSortRec(arr,index,r) #right arr
    

quickSortRec(arr,0,len(arr)-1)
print(arr)