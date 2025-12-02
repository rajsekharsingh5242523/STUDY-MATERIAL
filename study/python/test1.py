def binary_search(data,search):
    low = 0
    high = len(arr) - 1
    mid = 0
    while low <= high:
        
        mid=(high+low)//2

        if search<arr[mid]:
            high=mid-1
        elif search>arr[mid]:
            low=mid+1
        else:
            return mid
    
    return -1

arr = [ 2, 3, 4, 10, 40 ]
x = 10

# Function call
result = binary_search(arr, x)

if result != -1:
    print("Element is present at index", str(result))
else:
    print("Element is not present in array")

