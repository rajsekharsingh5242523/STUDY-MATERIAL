#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#======== bubble sorting ===========
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
alist=[15,6,13,22,3,52,2]
print("Orginal lost:",alist)
length=len(alist)
for i in range(length):
    for j in range(length-i-1):     #here we don't have to compare the heavier elements that have already settled at correct posotion so n-1,n-2,n-3,n-4,n-5,n-6,.....
        if alist[j]>alist[j+1]:     #FOR making it decenting order just interchangge this j+1 and j
            alist[j+1],alist[j]=alist[j],alist[j+1]
print("Sorted lost:",alist)

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#======== insert sorting ===========
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

alist=[15,6,13,22,3,52,2]
print("Orginal lost:",alist)
for i in range(1,len(alist)):       #NOTE here we just maae the first element to the sorted list so we diont consider also there we also take care of sign
    key=alist[i]   #Note: 6 (the key) isn’t lost! It’s still stored in key,just not in the list right now   
    j=i-1          
    while j>=0 and key < alist[j]:    #so here when j=0 after first time so it goes to else and the key is place in it correct place.
        print('before index of of the key that start from the 1 to len',j)
        alist[j+1]=alist[j]       
        j=j-1    #so here j will become 0
    else:
        alist[j+1]=key    
    print('intermedeate step:',alist)  
print("Sorted lost:",alist)


#NOTE both take n-1 passes to sort an array of n-elements .NOTE al see the intermediate step

def insert_sorting(l):
    for i in range(1,len(l)):
        key=l[i]
        j=i-1
        while l[j]>key and j>=0 :
            l[j+1]=l[j]
            j=j-1
        else:
            l[j+1]=key
    print('final my answer',l)        

insert_sorting(alist)              




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



