def Create_file(filename):
    try: 
        with open(filename,'w') as file_handle:
            user=input('what do you want to enter in the file:')
            file_handle.write(user)
    except :    # here for any error it show same message
        print('Error')


def Append_file(filename):
    try:
        with open(filename,'a') as file_handle:      #generly it is read only mode if you file in some other location then write it location but provide // (double slash) if you want to use / put r at the front know as row string
            user=input('what do you want to append to the file:')
            file_handle.write(f"{user}\n")
    except FileNotFoundError:       #here for perticular problem it print the solution
        print(f'Create the file first name {filename}')



file_handle=open('testfile','r')      # if the file does not exist then it rise I/O error other 'r+'
print(file_handle.read())
print(file_handle.readline(1))
print(file_handle.readlines())
file_handle.close()

file_handle=open('testfile','w')
file_handle.write('<string>') 
file_handle.writelines(['<list>'])