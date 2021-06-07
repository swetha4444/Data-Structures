arr = [1,2,3,4,5,6,7,8,9,10]


def binarySearch(arr,left,right,query):
    if(left <= right):
        mid = ((right+left)//2)
        if(arr[mid] == query):
            return mid+1
        elif(arr[mid] > query):
            return binarySearch(arr,left,mid-1,query)
        elif(arr[mid] < query):
            return binarySearch(arr,mid+1,right,query)
    else:
        return "Not Found"
    
def binarySearchItr(arr,query):
    left = 0 
    right = len(arr)-1
    
    while(left<=right):
        mid = ((right+left)//2)
        if(arr[mid] == query):
            return mid+1
        elif(arr[mid] > query):
            right = mid-1
        elif(arr[mid] < query):
            left = mid+1
    return "Not Found"


print(binarySearchItr(arr,3))
print(binarySearch(arr,0,len(arr)-1,3))
