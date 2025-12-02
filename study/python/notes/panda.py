# to create a DataFram from a dictcanry

import pandas as pd

mydataset = {
  'cars': ["BMW", "Volvo", "Ford"],
  'passings': [3, 7, 2]
}

myvar = pd.DataFrame(mydataset)

print(myvar)

# to create a DataFram from a Seriess

import pandas as pd

a = [1, 7, 2]

myvar = pd.Series(a,index=['row1','row2','row3'])    

print(myvar)        #here the indexing start from 0 to len -1 without title


# here  we directy specify the index without title

import pandas as pd

calories = {"day1": 420, "day2": 380, "day3": 390}

myvar = pd.Series(calories)

print(myvar)



#Create a simple Pandas DataFrame:

import pandas as pd

data = {
  "calories": [420, 380, 390],      # allows in the list form
  "duration": [50, 40, 45]
}

#load data into a DataFrame object:
df = pd.DataFrame(data)
print(df.to_string(index=False))        #Default print(df) adds index numbers (0,1,2...) in the first column but this hides them

'''
Result

     calories  duration
  0       420        50
  1       380        40
  2       390        45'''

# Locate Row


#As you can see from the result above, the DataFrame is like a table with rows and columns.
#Pandas use the loc attribute to return one or more specified row(s)

#refer to the row index:
print(df.loc[0])
'''
Result

  calories    420
  duration     50
  Name: 0, dtype: int64

Note: This example returns a Pandas Series.'''


#use a list of indexes:
print(df.loc[[0, 1]])       #print(holder.loc[0,1])   this willl give errors
'''
Result

     calories  duration
  0       420        50
  1       380        40

Note: When using [], the result is a Pandas DataFrame.'''
