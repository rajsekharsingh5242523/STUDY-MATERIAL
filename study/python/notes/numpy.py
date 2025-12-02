'''
NUMpy vs list

1)speed
    numpy is afaster than list,numpy can store data in 1D,2D,3D....matrix but list only 1D.
    say we have saved array ,ever element in the list is represented by some oppcode .SO here list have a very long oppcode compred to numpy 
    which uses less oppcode for reperesnting the same elememnt .list take the element and needs a oppcode to reprent each of this for ever element
    ->size
    ->reference Count
    ->Object Type
    ->object Value

    NOTE No type checking when iterating throught elements.
    
    AS numpy only allow one type of data inside it not like list which can store and type of data:- string,float,int,blooen,list,dict,tuple,.....

2)Memory allotement
    list -> random
    numpy-> contiguous memory (continueos memory like-> all array are sotred in one block )

    effective cache utilizartion

'''

import numpy as np

# how to make a array
a=np.array([1,2,3])
print(a)

#multi dimenetional array
b=np.array([[1,2,3],[4,5,6]])
print(b)


# to a list or tuple and make your desire dimention will making even if less element
c=np.array((1,2,3,4,5),ndmin=3)
print(c)

#get Dimenstion
print('dimention of a:',a.ndim)
print('dimention of b:',b.ndim)

#it get it shape-->(row,columb) 
print('shape of a:',a.shape)
print('shape of b:',b.shape)

# Get a specific element [r,c]
print('specifiv location',b[0,1])       # here it start from 0 indexing 

# Get specific row and column
print("first row:",b[0,:])      #here : --> mean startindex:stopindex:step for slicing see down example
print("secound colum:",b[:,1])

#To get a specific section of the array 
data=np.array([[1,2,3,4,5,11,12,13,14,15],[6,7,8,9,10,16,17,18,19,20]])
print(data[1,1:7:2])

#create a matxic only containing '0' of dimention [r,c]
zero_matrix=np.zeros((2,3))
print(zero_matrix)

#create a matxic only containing '1' of dimention [r,c]
one_matrix=np.ones((3,3))
print(one_matrix)

# all same value 
same_matrix=np.full((2,2),69)
print(same_matrix)

#create a square identity matxic of dimention n
indentity_matrix=np.eye(3)
print(indentity_matrix)

# modify value inside arrray
data[0,4]=-1

#3-D 
user=np.array([[[1,2],[3,4]],[[5,6],[7,8]]])
print(user)

# NOTE user=np.array([[[1,2],[3,4]],[[5,6],[7,8],[9,10]]]) ---> this is wrong as it sholud be same dimention mean r,c

#to select value from this 3D  ---> work from outside to in like plealing onion
print(user[0,1,1])

#print all the top set
print(user[:,0,:])


#random matrix from --> start,end,(r,c)
array = np.random.randint(0,10,(3,3))

#repeat an array
holder1=np.repeat(user,3,axis=0)
holder2=np.repeat(user,3,axis=1)

#EXAMPLE

import numpy as np

b=np.array([[1,1,1,1,1],[1,0,0,0,1],[1,0,9,0,1],[1,0,0,0,1],[1,1,1,1,1]])
print('attept1',b)

a2=np.ones((5,5),dtype='int16')
a2[1:4,1:4]=[[0,0,0],[0,9,0],[0,0,0]]
print('attept2',a2)

a3=np.ones((5,5),dtype='int16')
zero_mid=np.zeros((3,3))
zero_mid[1,1]=9
a3[1:4,1:4]=zero_mid
print('attept3',a3)

# EXAMPLE


import numpy as np
sentence = "The quick brown fox jumps over the lazy dog"
np_sentence = np.char.array(sentence)
S1 = np_sentence[0][:3]    
s2 = np_sentence[0][4:9]
S3 = np_sentence[0][10:15]  
print(S1)
print(s2)
print(S3)

# Broadcasting Example in NumPy
import numpy as np

# 1D array (shape: (3,))
a = np.array([1, 2, 3])

# 2D column array (shape: (3, 1))
b = np.array([[1],
              [2],
              [3]])

# Broadcasting automatically expands both arrays:
# a → (1, 3)
# b → (3, 1)
# Result → (3, 3)
# Then elementwise addition occurs.
result = a + b

# Print arrays and result for clarity
print("Array a (1D):")
print(a)

print("\nArray b (2D column):")
print(b)

print("\nResult of broadcasting (a + b):")
print(result)


#maths function

m=np.array([1,2,3,4,5])
n=np.array([6,7,8,9,10])
print(m*2)
print(m+5)
print(m/10)
print(m+n)

#MANIPULATION FUNCTION

np.concatenate((m,n, ...), axis=0, out=None, dtype=None)

'''axis: The axis along which the arrays will be joined. Default is 0 (rows). If None, all arrays are flattened before concatenation.

out: Optional. If provided, the result is placed in this array.

dtype: Optional. Specifies the data type of the resulting array.'''

#Example 1: Concatenating 1D Arrays

import numpy as np

a = np.array([1, 2, 3])
b = np.array([4, 5, 6])

result = np.concatenate((a, b))
print(result)   #--->[1 2 3 4 5 6]

#Example 2: Concatenating 2D Arrays Along Rows (axis=0)  NOTE the columns should of same size 

a = np.array([[1, 2], [3, 4]])
b = np.array([[5, 6]])

result = np.concatenate((a, b), axis=0)
print(result)

'''
[[1 2]
[3 4]
[5 6]]
'''

#Example 3: Concatenating 2D Arrays Along Columns (axis=1) 

a = np.array([[1, 2], [3, 4]])
b = np.array([[5], [6]])

result = np.concatenate((a, b), axis=1)
print(result)

'''
[[1 2 5]
[3 4 6]]
'''

#Joining Arrays Using Stack Functions  

'''
here it take tthe axis ka element one by one and then sort nicly
'''

import numpy as np

arr1 = np.array([1, 2, 3])

arr2 = np.array([4, 5, 6])

arr = np.stack((arr1, arr2), axis=1)

print(arr)      

'''[[1 4]
 [2 5]
 [3 6]]'''


# NOTE  for concatenation along axis=1, the arrays must have at least 2 dimensions

import numpy as np
a = np.array([1, 2, 3]).reshape(1, 3)  # Reshape to 2D: (1, 3)
b = np.array([4, 5, 6]).reshape(1, 3)  # Reshape to 2D: (1, 3)
result = np.concatenate((a, b), axis=1)  # Concatenate along axis=0
print(result)


#Example 4: Flattening Arrays with axis=None

a = np.array([[1, 2], [3, 4]])
b = np.array([[5, 6]])

result = np.concatenate((a, b), axis=None)
print(result)       #-->[1 2 3 4 5 6]


#reshape
import numpy as np
a = np.array([1, 2, 3]).reshape(1, 3)
print(a)

# here at the begenning shape was (3,) so to make (1,3) we take to 2D 

#Reshape From 1-D to 3-D

'''Convert the following 1-D array with 12 elements into a 3-D array.

The outermost dimension will have 2 arrays that contains 3 arrays, each with 2 elements:'''

import numpy as np

arr = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])

newarr = arr.reshape(2, 3, 2)

print(newarr)

#We can reshape an 8 elements 1D array into 4 elements in 2 rows 2D array but we cannot reshape it into a 3 elements 3 rows 2D array as that would require 3x3 = 9 elements.

#Unknown Dimension

'''Meaning that you do not have to specify an exact number for one of the dimensions in the reshape method.

Pass -1 as the value, and NumPy will calculate this number for you.'''

#Convert 1D array with 8 elements to 3D array with 2x2 elements:

import numpy as np

arr = np.array([1, 2, 3, 4, 5, 6, 7, 8])

newarr = arr.reshape(2, 2, -1)

print(newarr)

#Flattening array means converting a multidimensional array into a 1D array.

#We can use reshape(-1) to do this.

import numpy as np

arr = np.array([[1, 2, 3], [4, 5, 6]])

newarr = arr.reshape(-1)

print(newarr)



#In a nutshell, this is because it's one-dimensional array (hence the one-element shape tuple). so it just give the size as it is not needed for (r,c)

np.array([1, 2, 3]).shape       #-->(3,)
np.array([[1, 2, 3]]).shape     #-->(1, 3)
np.array([[1], [2], [3]]).shape     #-->(3, 1)

# nd.squeeze()
'''
here this function bring the array from any  higher dimention to 1 dimention
'''
data=np.array(user,ndmin=2)
answer1=np.squeeze(data)
print(f'''Original array:
{answer1}''')


#Iterate on the elements of the following 1-D array:

import numpy as np

arr = np.array([1, 2, 3])

for x in arr:
  print(x)


#Iterating 2-D Arrays

import numpy as np

arr = np.array([[1, 2, 3], [4, 5, 6]])

for x in arr:
  print(x)      #In a 2-D array it will go through all the rows.IT WILL print only the rows.

#To return the actual values, the scalars, we have to iterate the arrays in each dimension.

#Iterate on each scalar element of the 2-D array:

import numpy as np

arr = np.array([[1, 2, 3], [4, 5, 6]])

for x in arr:
  for y in x:
    print(y)


#Iterating Arrays Using nditer() -->  here say we have very array of very higher dimention then to loop elements we have have to have many loop!


import numpy as np

arr = np.array([[1, 2, 3], [4, 5, 6]])

for i in np.nditer(arr):
  print(i)

#The NumPy ndarray object has a function called co(), that will sort a specified array.

#Sort the array:

import numpy as np

arr = np.array([3, 2, 0, 1])  #--> [0,1,2,3 ]
print(arr)


#Sorting a 2-D Array
#If you use the sort() method on a 2-D array, both arrays will be sorted inside the sub list only

#Sort a 2-D array:

#np.sort(<array>,axis=0/1)

import numpy as np

arr = np.array([[3, 2, 4], [5, 0, 1]])

print(np.sort(arr))     #-->[[2 3 4] [0 1 5]]


'''
in defalut axis is 1  it does from left to right

0 --> it does from top to bottom

'''

# MATHS FUNCTION

mean_array=np.mean('<array>')
variance = round(np.var(data, ddof=1), 2) if len(data) > 1 else 0.00
std_dev = round(np.std(data, ddof=1), 2) if len(data) > 1 else 0.00

