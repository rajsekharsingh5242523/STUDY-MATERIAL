def sum(a=0,b=0,c=0):
    return a+b+c
def avg(x,y,z):
    ans=sum(x,y,z)/3
    return ans

print('AVGERAGEof the numbers are:',avg(2,3,4))


'''
here see it follows LEGB rule 
L-local environment
E-enclosed environment
G-global environment
B-built in environment

first see if the varialble is ther in the local variable if not it gots to the higtht level i.e...E -> G-> B
see below
'''

def dance():
    tiger=15    # here all do there is tiger in the main environment but it first take the variable in local variable 
    print(tiger)

tiger=25
print(tiger)
dance()
print(tiger)    


def global_explanation():
    global donkey       #here it says not to create a new variable in the local but says to refer the variable in main code
    print(donkey)
    donkey=30
    print(donkey)

donkey=95
print(donkey)
global_explanation()


item_cost=float(input('whatg is yournumber'))
SALES_TAX_RATE =0.08
def total_cost(item_cost):
    holder=item_cost*SALES_TAX_RATE +item_cost
    return holder
print('Item Cost:',f'{item_cost:.2f}')
print('Sales Tax Rate:',SALES_TAX_RATE )
print('Total Cost:',total_cost(item_cost))

