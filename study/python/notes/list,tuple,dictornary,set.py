#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== CREATING & APPENDING & UPDATING  LIST ======= 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
l1=list('<sequence>')
l2=['<values>']
string_list=list("hello")
intput_list = list(input("enter your list elements :"))
integer_list = list(map(int, input().split()))
string_list[0]='m'

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== list slicing & list concatenating and replication =========== 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

print(string_list['<start>':"<stop>":'<step>']) #step can be -1 for reverse reading    

combine_list=l1+l2
replicated_list=string_list*'<num>'


#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== comparing list ======= 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
print([1,2,8,9]<[9,1])  #HERE it check first element
print([1,2,8,9]<[1,2,9,1])      #here itr check the 3 element


#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== list function ======= 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

del l1['<index>']
del l1['<start>:<stop>']
l1.pop('<index>')
l1.remove('<item>')
l1.extend('<[list]>')
l1.append("<item>")
l1.sort(reverse=True)
l1.insert('<pos>,<item>')
l1.reverse()
sum(l1)

"""
example
"""
l1 = [1, 'h', 3, 4,5,6,7]

del l1[0]
print('1',l1)

l1.remove('h')
print('2',l1)

l1.pop()
print('3',l1)

l1.pop(0)
print('4',l1)

l1.reverse()
print(l1)

l1.extend([3,2])
print('5',l1)

l1.sort()
print('6',l1)

l1.append(1)
print('7',l1)

l1.sort(reverse=True)
print('6',l1)

l1.insert(0,7)
print('8',l1)

print(l1[::-1])

print(len(l1))



#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== sort & sorted ======= 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
store_set = list(map(int, input().split()))      #a alternate not to take input as string split based on gap then loop throught it the convert it into interger and then add to some other list
#map(function, iterable)
#function → the function you want to apply.
#iterable → a sequence (list, tuple, string, etc.) of items to process.

store_set.sort()
#there we sort the orginal means alternating the original data
print(store_set)

sorted_list = sorted(store_set)
#here make a new not effecting the orginla list
print(store_set)
print(sorted_list)


#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== list comprehension ======= 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
'''new_list=[ expression               # what you want to store
  for variable in iterable  # loop over items
  if condition             # optional filter
]'''
'''new_list → the resulting list after comprehension.

expression → some operation or value applied to each item.

item → a variable representing each element of the iterable.

iterable → any sequence or collection, e.g., list, tuple, string, range, etc.'''

#example:
numbers = [1, 2, 3, 4]
squares = [x**2 for x in numbers]
print(squares)      #output is in tuple 


numbers = [1, 2, 3, 4, 5, 6]
evens = [x for x in numbers if x % 2 == 0]
print(evens)

"""
NOTE it is the short version of this 

evens = []
for x in numbers:
    if x % 2 == 0:
        evens.append(x)

"""

'''
    here it first evalute for x in number
    then condition,and add to evens
'''


# ==============================================================================
# 🔢 PRIME NUMBER EXAMPLES
# ==============================================================================

"""
    ---
    Q)
    ---  

    user=int(input('What is your number :'))
    LIST=[]
    for num in range(2,user+1):
        for i in range(2,num):
            if num%i==0 :
                print(f'{num} is not prime in the sequaence of number till {user}')
                break    
        else:
            LIST.append(num)
            continue
    print(f'\n === prime number in range 0 - {user} === \n')    
    for i in LIST:
        print(i)

    ---
    Q)
    ---
    Write a program that takes an integer n as input and prints all the prime numbers less than n. 
    Ensure that the program efficiently identifies and displays the prime numbers.   

    L1 = []  # List to store prime numbers
    user = int(input('enter your upper number :'))

    for i in range(2, user):  # Start from 2 since 0 and 1 are not prime
        for j in range(2, int(i**0.5) + 1):  # Check divisibility up to sqrt(i) NOTE as i % i=0 if we say   #i = 5 now here aldo 5 is a prime number get discarded
    for j in range(2,i+1):                                                                                  #j = 2 3 4 5
            if i % j == 0:
                break
        else:
            L1.append(i)

    for i in L1:
        print(i)    
        
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == for if  ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
                    
    L1 = []  # List to store prime numbers
    user = int(input('enter your upper number :'))

    for i in range(2, user):  
        count = 0
        for j in range(2, i+1):  # Check divisibility including i itself
            if i % j == 0:
                count += 1          NOTE after the counter is finished it get og inner if loop and continue to next line of code that is outer if
        if count == 1:  # Only divisible by itself → prime  
            L1.append(i)

    for i in L1:
        print(i)
"""

#-------------------------------------------------------------------------------------------------------------------------------------------------------------

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== CREATING & APPENDING & UPDATING  TUPLE ======= 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
t1=tuple('<sequence>')
t2=('<values>',)     #if you put (1) then treated as a interger experssion, hence  a <,>
string_tuple=tuple("hello")
intput_tuple = tuple(input("enter your list elements :"))
integer_tuple = tuple(map(int, input().split()))
string_tuple[0]='m'      #it will show ERROR as tuple is inmutable

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== TUPLE slicing & TUPLE concatenating and replication =========== 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

print(string_list['<start>':"<stop>":'<step>']) #step can be -1 for reverse reading    

combine_tuple=t1+t2

#note
t1+(1)  #wrong
t1+(1,)     #correct

replicated_tuple=string_list*'<num>'


#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== UNPACKING TUPLE  ======= 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
t=(1,2,'A','B')
l,m,n,o=t
print(l,m,n,o)


#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== TUPLE function ======= 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

del t1[0]       #ERROR as tuple is immutable so it wil is like modifing a single element
max('<tuple>')
min('<tuple>')
"<tuple>".index('<iteam>')
"<tuple>".count('<iteam>')

#NOTE say you want to modify a element in the tuple then what you can you first unpack it and change and then pack it back

#--------------------------------------------------------------------------------------------------------------------------------------


#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#====== CREATING & APPENDING & UPDATING DICTIONARY ======
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

"""
<dictionary-name>={<key>:<value>,<key>:<value>,........}
"""
teachers={'Dimple':"computational stucerecr",'salary':1150000,'family':('tumka','tom','john')}

#multi line dict creating 

teachers2={'danoj':"computational stucerecr" ,\
           'salary':1150000,\
           'family':('tumka','tom','john')}

#to acccess the value we use key as it act as index here NOTE the index should be immutable type (string ,tuples)
print(teachers['Dimple'])
teachers['salary']=1000000000

# adding new key:value pair

teachers['wife']='suzuma'
print(teachers)

#using =

employee1=dict(name='John',salary=1000000,age=24)       # NOTICES that keys are not enclosed in quotes here : the values are given after = sign.

#using 

employee2=dict({'name':'John','salary':1000000,'age':24})        #NOTICES that you need to inclose them in curly bracket

#zip()

employee3=dict(zip(('name','salary','age'),('John',100000000,24)))      #IF you try to print only zip it will only give memory location.due to dict() it format into dict`````  `

#using []

employee4=dict([['name','John'],['salary',100000000],['age',24]])      #here it can inclose in [] or () no problem


#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#====== TRAVERSING DICTIONARY ======
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

for i in teachers:
    print(i,":",teachers[i])      #here i take the keys 


#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== DICTIONARY function ======= 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

teachers2={'Dimple':"computational stucerecr" ,\
           'salary':1150000,\
           'family':('tumka','tom','john'),\
           '3':{'NAME':'PANCAKE','TOOLS':['FLOWE','WATER']},\
            (4,5):'value for a tuple-as-a-key'}

dict_keys=teachers2.keys()  
print(dict_keys)

print(teachers2.values())

del teachers2['<key>']

print(teachers2.pop('<key>'))       #it remove the key:value pair

"""
note:-
"""
# here in pop allows you to specify what to display when the given agrument key doesnot exits, rather than normal output it show personal message.

teachers2.pop('dance',"the given key is not in DICTIONARY")

print(teachers2.get('<key>')) #---> value

holder=teachers2.items()      #here the key AnD VALuE ARE GROUP INTO A TUPLE THEN COMBINE INTO big TUPLe
for i in holder : 
    print(i)

teachers.update(teachers2)


#-------------------------------------------------------------------------------------------------------------------------------------------------------------

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#====== CREATING SET ======
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

set1={"<iterrable>"}        #itterable i.e.. list string typle

iterrable=[1,2,2,3,4,5,5,6]
s=set(iterrable)
print(s)       #here you can see Duplicate values are removed automatically and  we get random answer ever time

print(s[0])     #here it give error -> The elements have no fixed position so we can acces using indexing and 

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#=========== SET function ======= 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

s.add(7)
print(s)

s.remove(5)     #takes exactly one argument
print(s)

s.update([8,9])
print(s)

print(s.pop())

#---Union---
a = {1, 2, 3}
b = {3, 4, 5}
print(a | b)           # {1, 2, 3, 4, 5}
print(a.union(b))      # {1, 2, 3, 4, 5}


#--------- Intersection-----------
a = {1, 2, 3}
b = {2, 3, 4}
print(a & b)           # {2, 3}
print(a.intersection(b))  # {2, 3}


#---- Difference — Elements in a but not in b-----
a = {1, 2, 3}
b = {2, 3, 4}
print(a - b)           # {1}
print(a.difference(b)) # {1}

# ------ Symmetric Difference — Elements in either a or b, but not both----

a = {1, 2, 3}
b = {2, 3, 4}
print(a ^ b)           # {1, 4}
print(a.symmetric_difference(b))  # {1, 4}

'''
| Operation                     | Meaning                    | Example                                  |
| ----------------------------- | -------------------------- | ---------------------------------------- |
|  a == b                       | Both sets equal            |  {1,2} == {2,1}  →    True               |
|  a.issubset(b)  or  a <= b    | All elements of  a  in  b  i.e.. b big |  {1,2} <= {1,2,3}            |
|  a.issuperset(b)  or  a >= b  | All elements of  b  in  a  i.e.. a big |  {1,2,3} >= {2}              |
|  a.isdisjoint(b)              | No common elements         |  {1,2}  &  {3,4}  →   True               |'''
