import copy,csv

class BOOK:
    book_list = []   # shared by all objects

    def __init__(self, name, author, publisher):
        self.name = name
        self.author = author
        self.publisher = publisher
        self.book_list=[]       #Here it create a list specific to the current object. But when you try to create one more book it rest this list  
        data = {'TITLE': self.name, 'DATA': (author, publisher)}
        BOOK.book_list.append(data)   # append to the class list
        print(f'CURRENT BOOK ADDED :{self.name}')
    
    def display_book(self):
        print(f'whole book colletion :{BOOK.book_list}')
        for i in BOOK.book_list:
            print(f'Book name:{i["TITLE"]}')
            
class LIBARY:
    
    def __init__(self):
        # make a deep copy of the book list  
        '''
            🔍 Case 1: Normal Assignment (=)
            a = [1, 2, 3]
            b = a


            Here:

            b is not a new list — it points to the same list in memory as a.

            Changing one will change the other.

            b[0] = 99
            print(a)   # [99, 2, 3]
            print(b)   # [99, 2, 3]


            So assignment only makes another reference, not a copy.

            🔍 Case 2: Shallow Copy (copy() or [:])
            import copy

            a = [[1, 2], [3, 4]]
            b = a.copy()     # or b = a[:]


            Now b is a new list object (different from a),

            BUT the inner lists ([1,2], [3,4]) are still shared references.

            b[0][0] = 99
            print(a)   # [[99, 2], [3, 4]]   <-- inner list changed in both
            print(b)   # [[99, 2], [3, 4]]


            👉 Shallow copy = copies only the outer list, not nested objects.

            🔍 Case 3: Deep Copy (copy.deepcopy())
            import copy

            a = [[1, 2], [3, 4]]
            b = copy.deepcopy(a)


            b is a completely independent copy,

            and all nested lists (or dicts, objects, etc.) are also copied.

            b[0][0] = 99
            print(a)   # [[1, 2], [3, 4]]   <-- unchanged
            print(b)   # [[99, 2], [3, 4]]
        '''
        
        self.HOLDER = copy.deepcopy(BOOK.book_list)
        self.BORROW_LIST=[]

        # now you can safely modify HOLDER
        for i in self.HOLDER:
            i['STATUS'] = True

        print("LIBRARY COPY :", self.HOLDER)

    def display_books(self):
        for i in self.HOLDER:
            print(f'Book:{i["TITLE"]},Status:{i["STATUS"]}')
            
    def return_books(self,borrow_name,Book_name):
        self.borrow_name=borrow_name
        self.Book_name=Book_name
        found = False
        for i in self.BORROW_LIST:
            if i['BorrowerName']==borrow_name and Book_name in i['BookData']:
                for j in self.HOLDER:
                    if j['STATUS']==False  and j["TITLE"]==Book_name:
                        i['BookData'].remove(Book_name)
                        print(f"{self.borrow_name} has returned the book: '{Book_name}'")
                        j['STATUS']=True
                        found = True
                        break
        if not found:
            # Borrower tried to return a book they never borrowed
            print(f"{self.borrow_name} didn't borrow '{Book_name}'")

    def Borrowed_Book_Display(self):
        for i  in self.BORROW_LIST:
            print(f"{i['BorrowerName']} has borrowd :{i['BookData']} ")
            
    def list_of_available_books(self):
        for i  in self.HOLDER:
            if i['STATUS'] == True:
                print(i['TITLE'])

    def checkout_book(self,borrow_name,Book_name):
        choice = input('Do you want to borrow a book (YES/NO): ')
        if choice.upper() != 'YES':
            return
        self.borrow_name=borrow_name
        self.Book_name=Book_name
        found = False
        for i in self.HOLDER:
            print(f'i here :{i}')
            if i['TITLE'] == Book_name and i['STATUS'] == True:
                print('The book is available.')
                i['STATUS'] = False
                print(f"{borrow_name} has borrowed the book '{Book_name}'")
                # ✅ Check if borrower already exists
                for entry in self.BORROW_LIST:
                    if entry['BorrowerName'] == borrow_name:
                        entry['BookData'].append(Book_name)
                        break
                else:
                    # borrower not found → create new record
                    self.BORROW_LIST.append({'BorrowerName': borrow_name, 'BookData': [Book_name]})
                print(self.BORROW_LIST)
                found = True
                break
            elif i['TITLE'] == Book_name and i['STATUS'] == False:
                print(f"'{Book_name}' is not available")
                found = True
                break
        
        if not found:
            print(f"'{Book_name}' not found in the library.")

class CSV_FUNCTION:
    import csv  # CSV module provides functionality to read/write CSV files

    def read_csv(fn, user_delimiter):
        """
        Reads and prints each row of a CSV file using the specified delimiter.

        Parameters:
        - fn (str): File path of the CSV
        - delimiter (str): Character separating values (e.g., ',' or ';')
        """
        try:
            with open(fn, mode='r', newline='') as fhandle:
                rows = csv.reader(fhandle, delimiter=user_delimiter)
                print("\n📄 Reading CSV content:\n")
                for row in rows:
                    print("➡️", row)
        except FileNotFoundError:
            print("❌ File not found.")
        except Exception as e:
            print(f"⚠️ Error: {e}")


    # ============================= Write CSV Function =============================

    def write_csv(fn, header_list, row):
        """
        Writes a header and a single row to a CSV file.

        Parameters:
        - fn (str): File path of the CSV
        - header_list (list): List of column names
        - row (list): List of values for one row
        """
        try:
            with open(fn, mode='w', newline='') as fhandle:
                filewriter = csv.writer(fhandle, delimiter=',')
                filewriter.writerow(header_list)
                filewriter.writerow(row)
                print(f"✅ Data written successfully to {fn}")
        except Exception as e:
            print(f"❌ Error writing to file: {e}")


    # ============================= Function Call =============================

    # Reading a CSV file (you can replace path as needed)
    #read_csv(r'd:\study\python 3 funamentail course-1\name.csv', ',')

    # Writing to a CSV file example (uncomment below lines to test)
    write_csv(
        r'D:\study\python\name.csv',
        ['Name', 'Age', 'Location'],
        ['Rajsekhar', '25', 'India'])

class TXT_FILE_SEARCHING:
    def __init__(self):
        #━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        #== TXT FILE SEARCHING ==  
        #━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    
    
        # -------------------- ACRONYM LOOKUP TOOL --------------------
        # This tool allows you to search for and add acronyms to a file.
        # Acronyms are stored in a text file called 'acronyms.txt'
        # Each line in the file follows the format: ACRONYM Full form/description

        # -------------------- FUNCTION: SEARCH --------------------

        def Search_TextFile_Acronym(filename):
            # Search for an ACRONYM in the file and display its meaning.
            
            search_term = input("🔍 Enter the acronym to search:\n").strip().upper()

            found = False  # Track whether the ACRONYM is found

            try:
                # Open the file in read mode                # Also here with makes it close the file when not in use
                with open(filename, 'r') as file:     #also we simpled the file=open('achrony.txt','r')........close file
                    # Go through each line in the file
                    for line in file:
                        # Convert the line to uppercase and check if it starts with the search term followed by a space
                        if line.upper().startswith(search_term + ' '):
                            print(f"✅ Found: {line.strip()}")  # Display the line
                            found = True  # Mark as found
                            break  # Stop after finding the first match
            except FileNotFoundError:
                # If the file doesn't exist, show this message
                print('❗ File not found. Please create it first')      #Here you put 'filename' inside {} — Python tries to interpret it as a variable, but it’s just a string, so it crashes.
                return

            # If nothing was found, show this message HERE not(NOT GATE)
            if not found:
                print("❌ Acronym not found in the list.")
            else:
                return    

        # -------------------- FUNCTION: CREATE --------------------

        def create_TextFile_Acronym():
            
            # Add a new acronym and its description to the file.
            
            # Ask user for acronym and its meaning
            # .strip() removes extra spaces
            # .upper() makes the acronym consistent in uppercase
            acronym = input("➕ Enter new acronym: ").strip().upper()
            description = input("📝 Enter its description: ").strip()

            # Open the file in append mode to add new entries
            # 'with' automatically closes the file after writing
            with open('acronyms.txt', 'a') as file:     #here the file will be create where the code file is located
                file.write(f"{acronym} {description}\n")  # Write the new acronym and description       # if dont use \n then it will add from where you left 

            print(f"✅ Acronym {acronym} added successfully!")

        # -------------------- FUNCTION: MAIN MENU --------------------


        # Display menu and handle user choice for searching or creating acronyms.

        # Print the main menu options
        print("\n🔠 Acronym Tool - Options")
        print("S → Search an acronym")
        print("C → Create a new acronym")


        # Ask user to choose an option
        choice = input("\nEnter your choice (S/C): ").strip().upper() #
        # .strip() removes any spaces before/after input
        # .upper() converts input to uppercase (so 'nasa' becomes 'NASA')
        # Handle the user's choice
        if choice == 'S':
            Search_TextFile_Acronym("acronyms.txt")
        elif choice == 'C':
            create_TextFile_Acronym("acronyms.txt")
        else:
            print("⚠️ Invalid choice! Please enter 'S' or 'C'.")

# ==============================================================================
# ========= TXT FILE  WORD SEARCHING ===========
# ==============================================================================
test=TXT_FILE_SEARCHING() 


# ==============================================================================
# ============ 📚 LIBRARY MANAGEMENT SYSTEM ===========
# ==============================================================================

# --------------------------- Book Creation ---------------------------

no_book_add=int(input('How many book you want to add :'))

for i in range(no_book_add):
    Book_name=input('what is the name of the book :').lower()
    Book_author=input('what is the author of the book :').lower()
    Book_publisher=input('what is the publisher of the book :').lower()
    
    # Add dictionary versions of the books into the Library list using the class method
    print('\nAdd dictionary versions of the books into the Library list using the class method')
    book1 = BOOK(Book_name, Book_author, Book_publisher)

# Display all books currently in the library
print('\n Display all books currently in the library')
book1.display_book()

# -------- Borrower Creation & Borrowing Book for Shreya libary--------------

# Create  Book instances with title and author for a perticular libary
print('\nCreate  Book instances with title and author for a perticular libary')
ShreyaBooks=LIBARY()     
# Display all books currently in the library with there sataues
print('\nDisplay all books currently in the library with there sataues')
ShreyaBooks.display_books()

# Shreya attempts to borrow "dance monkey"
print("\nShreya tries to borrow 'dance monkey'.")
ShreyaBooks.checkout_book('shreya','dance monkey')

ShreyaBooks.display_books()  # Print current library state (for debugging)

# Jane tries to borrow the same book, should fail since it's already borrowed
print("\nJane tries to borrow 'dance monkey'.")
ShreyaBooks.checkout_book('Jane','dance monkey')

# Shreya attempts to borrow 'rich dad'
print("\nShreya tries to borrow 'rich dad'.")
ShreyaBooks.checkout_book('shreya','rich dad')

# Jane tries to borrow 'moving like a fish'
ShreyaBooks.checkout_book('Jane','moving like a fish')

# --------------------------- Borrowed Book Display ---------------------------

# Show the name of books borrowerd by a person
print("\nBooks borrowed by each person :")
ShreyaBooks.Borrowed_Book_Display()

# --------------------------- Available Books ---------------------------
print("\nAvailable books in the library:")
ShreyaBooks.list_of_available_books()

# --------------------------- Book Return Attempts ---------------------------

# Jane tries to return a book she never borrowed - should print an error
print("\nJane tries to return 'dance monkey'")
ShreyaBooks.return_books('Jane','dance monkey')

print("\nShreya tries to return 'rich dad'.")
ShreyaBooks.return_books('shreya','rich dad')

# --------------------------- Available Books ---------------------------
print("\nAvailable books in the library:")
ShreyaBooks.list_of_available_books()

# -------- Borrower Creation & Borrowing Book for sonu libary--------------
print('==== TEST ===')
sonuBooks=LIBARY()
sonuBooks.display_books()
print('To prove that two libary have different book data')


'''recipes=[{'NAME':'PANCAKE','TOOLS':['FLOWE','WATER']}]
save_recipes(recipes,r'D:\study\python\recipes.pkl')
load_recipes(r'D:\study\python\recipes.pkl')
'''
