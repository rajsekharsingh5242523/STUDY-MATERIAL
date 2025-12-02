# --------------------------- Book Class ---------------------------

class Book:
    def __init__(self, name, author):
        """
        Initializes a new Book object with name, author, and sets availability to 'True'
        """
        self.name = name
        self.author = author
        self.available = 'True'  # Stored as a string for compatibility with dictionary structure

    def add_book(self):
        """
        Converts the Book object into a dictionary to be added to the Library list
        """
        return {
            'name': self.name,
            'author': self.author,
            'states': self.available  # 'states' key indicates availability
        }   

# --------------------------- Borrower Class ---------------------------

class borrower:
    def __init__(self, name):
        """
        Initializes a borrower with a name and an empty list of borrowed books
        """
        self.name = name
        self.borrowed_books = []

    def checkout_book(self, book_name, library):
        """
        Allows the borrower to checkout a book by name from the library if it's available
        """
        for book in library:
            # Book is available for borrowing
            if book['name'] == book_name and book['states'] == 'True':
                book['states'] = 'False'  # Mark as borrowed
                self.borrowed_books.append(book_name)  # Track in borrower's list
                print(f"{self.name} has borrowed the book '{book_name}'")
                return

            # Book already borrowed
            elif book['name'] == book_name and book['states'] == 'False':
                print(f"'{book_name}' is not available")
                return

        # Book not found in the library
        print(f"'{book_name}' not found in the library.")

    def return_book(self, book_name, library):
        """
        Allows the borrower to return a book back to the library
        """
        if book_name in self.borrowed_books:
            for book in library:
                if book['name'] == book_name and book['states'] == 'False':
                    book['states'] = 'True'  # Mark book as available
                    self.bosrrowed_books.remove(book_name)  # Remove from borrower's list
                    print(f"{self.name} has returned the book: '{book_name}'")
                    return
        else:
            # Borrower tried to return a book they never borrowed
           print(f"{self.name} didn't borrow '{book_name}'")




# ============================== Define the Class ==============================
# This section defines a simple RobotDog class with attributes and behavior

class RobotDog:
    """
    A simple class representing a robot dog.
    """

    def __init__(self, name, breed):
        """
        Constructor method that initializes the robot dog's name and breed.

        Args:
            name (str): The name of the robot dog.
            breed (str): The breed/type of the robot dog.
        """
        self.name = name        # Store the robot dog's name
        self.breed = breed      # Store the robot dog's breed/type

    def bark(self):
        """
        Simulates the robot dog barking.
        """
        print('Woof Woof!')     # Output a bark sound


# ============================== Main Program ==============================

# Create an instance (object) of RobotDog
my_dog = RobotDog('Spot', 'Chihuahua')

# Print the robot dog's attributes
print(f'Name  : {my_dog.name}')
print(f'Breed : {my_dog.breed}')

# Make the robot dog bark
my_dog.bark()


# ============================== INHERITANCE EXAMPLE ==============================
# This section shows how a child class can inherit from a parent class and override methods

# ---------------------- Parent Class ----------------------
class Robot:
    """
    Parent class representing a general robot.
    """
    def __init__(self, name):
        self.name = name                      # Store robot's name
        self.position = [0, 0]                # Robot starts at position (0, 0)
        print('My name is:', self.name)       # Print robot's name

    def motion(self, x, y):
        """
        Move the robot by updating its position.
        """
        self.position[0] += x
        self.position[1] += y
        print('New position is:', self.position)

    def eat(self):
        """
        Simulate the robot being hungry.
        """
        print("I'm hungry!")


# ---------------------- Child Class ----------------------
class RobotDog(Robot):
    """
    Child class that inherits from Robot and adds dog-like behavior.
    """

    def make_noise(self):
        """
        RobotDog makes a barking sound.
        """
        print('Woof Woof!')

    def eat(self):
        """
        Override the eat method to add custom dog-like behavior.
        """
        super().eat()            # Call the parent class's eat method first
        print('I like bacon!')   # Add extra behavior specific to RobotDog


# ============================== Main Program with Inheritance ==============================

# Create a RobotDog object — uses the parent's __init__ because none is defined in child
my_robot_dog = RobotDog('Bob')

# Move the robot dog to a new position (x = +10, y = +5)
my_robot_dog.motion(10, 5)

# Make the robot dog bark
my_robot_dog.make_noise()

# Feed the robot dog (calls the overridden eat method)
my_robot_dog.eat()


# ============================= Import Required Classes ==============================
# Import all the employee-related classes from another file/module named 'employee'
# These classes represent different employee types and their salary structures.

from employee import (
    Employee,                            # Base class for all employee types
    weeklySalaryEmployee,               # Fixed weekly salary employee
    HourlyMonthlySalaryEmployee,        # Employee paid hourly
    weeklyCommissionSalaryEmployee      # Employee with fixed salary + commission
)

# ================================ Company Class =====================================
# The Company class demonstrates aggregation, polymorphism, and encapsulation.

class Company:
    """
    Represents a company that manages multiple employees.
    Aggregates Employee objects and handles payroll.
    """

    def __init__(self):
        self.employees = []  # List to store all employee objects

    def add_employee(self, new_employee):
        """
        Adds a new employee to the company's employee list.
        Demonstrates aggregation: Company 'has-a' relationship with Employee(s).
        """
        self.employees.append(new_employee)

    def display_employees(self):
        """
        Displays all employee names currently working in the company.
        """
        print('\n🧑‍💼 ---------- Current Employees ----------')
        for emp in self.employees:
            # Access each employee's first and last name
            print(f'👤 {emp.fname} {emp.lname}')
        print('-----------------------------------------\n')

    def pay_employees(self):
        """
        Calculates and prints weekly paychecks for all employees.
        Demonstrates polymorphism:
        Each employee type can define its own cal_weekly_paycheck() method.
        """
        print('💰 ----------- Weekly Payroll ------------')
        for emp in self.employees:
            print(f'👤 {emp.fname} {emp.lname}')
            # Dynamically call the appropriate method for each employee type
            print(f'   💵 Paycheck Amount: ₹{emp.cal_weekly_paycheck():,.2f}')
            print('-----------------------------------------')
        print()


# ================================ Main Function =====================================
# Entry point for running the script and demonstrating functionality.

def main():
    """
    Entry point of the program.
    Creates a Company instance, adds employees of various types,
    and invokes methods to display them and process pay.
    """

    # Create a company instance
    my_company = Company()

    # Create and add a fixed-salary employee
    employee1 = weeklySalaryEmployee('Rajsekhar', 'Singh', 'Developer', 100000)
    my_company.add_employee(employee1)

    # Create and add an hourly-paid employee
    employee2 = HourlyMonthlySalaryEmployee('Dipannita', 'Singh', 'Sales Agent', 40, 500)
    my_company.add_employee(employee2)

    # Create and add a commission + salary employee
    employee3 = weeklyCommissionSalaryEmployee('Chandrasekhar', 'Singh', 'Manager', 120000, 15, 1000)
    my_company.add_employee(employee3)

    # Display employees and process payroll
    my_company.display_employees()   # Show all employees in the company
    my_company.pay_employees()       # Print each employee's weekly pay


# Run the main function only when this script is executed directly
if __name__ == "__main__":
    main()



# Import the pickle module for binary file operations (saving and loading Python objects)
import pickle


# 👨‍🍳 Recipes Class: Handles creation of a recipe
class Recipes:
    def __init__(self, name):
        """
        Initialize the recipe with a name and an empty list of ingredients.
        """  
        self.name = name
        self.ingredients = []

    def add(self, no_ingredients):
        """
        Adds a specified number of ingredients and recipe instructions.
        Returns a dictionary representing the full recipe.
        """
        for _ in range(no_ingredients):
            # Prompt user for ingredient details
            ingredient_name = input("What is the name of the ingredient? ")
            ingredient_quantity = input("What is the quantity of the ingredient? ")
            
            # Store each ingredient as a dictionary
            ingredient = {
                "IngredientName": ingredient_name,
                "Quantity": ingredient_quantity
            }

            # Append the ingredient to the list
            self.ingredients.append(ingredient)

        # Ask for recipe instructions
        instructions = input("What are the instructions? ")

        # Return full recipe data as a dictionary
        recipe_data = {
            "Name": self.name,
            "Ingredients": self.ingredients,
            "Instructions": instructions
        }

        return recipe_data


# 💾 BinaryFile Class: Handles saving and loading recipes to a binary file
class BinaryFile:
    def __init__(self, filename):
        """
        Initialize the class with the filename to be used for storing recipes.
        """
        self.filename = filename

    def add_recipe(self, recipe_book):
        """
        Save the entire recipe_book list to a binary file using pickle.
        """
        try:
            with open(self.filename, 'wb') as file:
                pickle.dump(recipe_book, file)
        except pickle.PicklingError:
            print("❌ Failed to save recipes.")

    def load_recipes(self):
        """
        Load recipes from the binary file.
        Returns an empty list if file doesn't exist.
        """
        try:
            with open(self.filename, 'rb') as file:
                return pickle.load(file)
        except FileNotFoundError:
            return []


# 🚀 Main function: Command-Line Interface (CLI) for the recipe app
def main():
    filename = 'recipes.pkl'  # File to store recipes
    storage = BinaryFile(filename)

    # Load existing recipes from file
    recipe_book = storage.load_recipes()

    print("👨‍🍳 Welcome to the Recipe Book CLI Application!")

    # Start infinite loop for menu options
    while True:
        print("\n📋 Choose an option:")
        print("1. List all recipe names")
        print("2. Add a new recipe")
        print("3. Save and Exit")

        choice = input("Enter the number of your choice: ").strip()

        if choice == "1":
            # List all saved recipes
            if not recipe_book:
                print("📭 No recipes added yet!")
            else:
                print("📚 Recipes:")
                for recipe in recipe_book:
                    print(f"- {recipe['Name']}")

        elif choice == "2":
            # Add a new recipe
            name = input("Enter the recipe name: ").strip()
            recipe = Recipes(name)

            try:
                no_ingredients = int(input("How many ingredients? "))
                recipe_data = recipe.add(no_ingredients)
                recipe_book.append(recipe_data)
                storage.add_recipe(recipe_book)
                print(f"✅ Recipe '{name}' added successfully!")
            except ValueError:
                print("⚠️ Invalid number. Please enter a valid integer.")

        elif choice == "3":
            # Save and exit the application
            print("👋 Exiting the application. Goodbye!")
            break

        else:
            # Handle invalid input
            print("❌ Invalid choice. Please choose a valid option (1–3).")


# 🟢 Run the main program
main()





# ============================== 📚 IMPORT LIBRARIES ==============================

import pickle  # Used for saving (serializing) and loading (deserializing) Python objects from files


# ============================== 👨‍🍳 RECIPE CLASS ==============================

class Recipe:
    # A class-level list to store all recipe objects (shared across all instances)
    all_recipes = []

    # ---------------- 🛠️ STATIC METHODS ----------------

    @staticmethod
    def load_recipes(filename):
        """
        Load recipes from a binary file using pickle.
        If the file doesn't exist, start with an empty list.
        """
        try:
            with open(filename, 'rb') as file:
                Recipe.all_recipes = pickle.load(file)
                print("📂 Recipes loaded successfully.")
        except FileNotFoundError:
            print("⚠️ File not found. Starting with an empty recipe book.")
            Recipe.all_recipes = []
        except Exception as e:
            print(f"❌ Error loading recipes: {e}")
            Recipe.all_recipes = []

    @staticmethod
    def save_recipes(filename):
        """
        Save all current recipes to a file using pickle.
        This keeps the data safe for future use.
        """
        try:
            with open(filename, 'wb') as file:
                pickle.dump(Recipe.all_recipes, file)
                print("💾 Recipes saved successfully.")
        except pickle.PicklingError:
            print("❌ Failed to save recipes.")

    @staticmethod
    def pickle_to_bytes():
        """
        Convert all recipe objects to raw bytes (e.g., for network use).
        """
        return pickle.dumps(Recipe.all_recipes)

    @staticmethod
    def unpickle_from_bytes(pickled_data):
        """
        Restore recipe data from bytes back to Python objects.
        """
        Recipe.all_recipes = pickle.loads(pickled_data)

    # ---------------- 🧱 CONSTRUCTOR ----------------

    def __init__(self, name):
        """
        Create a new Recipe object with a name.
        Ingredients and instructions are added later.
        """
        self.name = name
        self.ingredients = []       # List of ingredients (each is a dictionary)
        self.instructions = ""      # String to hold cooking instructions

    # ---------------- 🧑‍🍳 INSTANCE METHODS ----------------

    def add_ingredients(self, count):
        """
        Collect ingredients from the user.
        Each ingredient has a name and an amount (e.g., '2 cups of flour').
        """
        for _ in range(count):
            ingredient_name = input("Ingredient name: ")
            ingredient_amount = input("Ingredient amount: ")
            self.ingredients.append({"name": ingredient_name, "amount": ingredient_amount})

    def add_instructions(self):
        """
        Collect cooking instructions from the user.
        """
        self.instructions = input("Instructions: ")

    def display(self):
        """
        Show the full recipe: name, ingredients, and instructions.
        """
        print(f"\n📝 Recipe: {self.name}")
        print("🍽 Ingredients:")
        for ing in self.ingredients:
            print(f"  - {ing['amount']} of {ing['name']}")
        print(f"📋 Instructions:\n  {self.instructions}")

    @classmethod
    def list_all(cls):
        """
        Print all recipes saved in the recipe list.
        """
        if not cls.all_recipes:
            print("📭 No recipes available yet.")
        else:
            for recipe in cls.all_recipes:
                recipe.display()


# ============================== 🚀 MAIN APPLICATION ==============================

def main():
    """
    Entry point for the command-line recipe manager.
    Provides options to list, add, and save recipes.
    """
    print("👨‍🍳 Welcome to the Recipe Book CLI Application!")

    # File to save/load recipes from
    FILENAME = "recipes.pkl"

    # Load existing recipes from file (if any)
    Recipe.load_recipes(FILENAME)

    # Main menu loop
    while True:
        print("\nChoose an option:")
        print("1. 📜 List all recipes")
        print("2. ➕ Add a new recipe")
        print("3. 💾 Save and Exit")

        choice = input("Enter the number of your choice: ").strip()

        if choice == "1":
            # Display all saved recipes
            Recipe.list_all()

        elif choice == "2":
            # Create a new recipe
            name = input("Enter the recipe name: ").strip()
            recipe = Recipe(name)

            # Ask how many ingredients to add
            try:
                no_ingredients = int(input("How many ingredients? "))
            except ValueError:
                print("❌ Invalid number. Please enter a number.")
                continue

            # Add ingredients and instructions
            recipe.add_ingredients(no_ingredients)
            recipe.add_instructions()

            # Save the recipe to the list
            Recipe.all_recipes.append(recipe)
            print(f"✅ Recipe '{name}' added successfully!")

        elif choice == "3":
            # Save all recipes and exit the app
            Recipe.save_recipes(FILENAME)
            print("👋 Exiting the application. Goodbye!")
            break

        else:
            # Handle any input that doesn't match menu options
            print("❌ Invalid choice. Please choose a valid option (1, 2, or 3).")


# ============================== 🏁 ENTRY POINT ==============================

# Only run main() if this script is run directly
main()



# ============================= Import Module =============================

import csv  # CSV module provides functionality to read/write CSV files


# ============================= Read CSV Function =============================

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
read_csv(r'd:\study\python 3 funamentail course-1\name.csv', ',')

# Writing to a CSV file example (uncomment below lines to test)
# write_csv(
#     r'd:\study\python 3 funamentail course-1\output.csv',
#     ['Name', 'Age', 'Location'],
#     ['Rajsekhar', '25', 'India']
# )



# =========================== 📘 ACRONYMS DICTIONARY ===========================

# A simple dictionary mapping acronyms to their full meanings
acronyms = {
    'LOL': 'laugh out loud',
    'IDK': "I don't know"
}

# ✅ Safely attempt to retrieve a value using get()
definition = acronyms.get('BTW')  # 'BTW' is not in the dictionary

# 🛡 Check if the key was found
if definition:
    print(definition)
else:
    print("⚠️ Key doesn't exist")  # Fallback message if key is not found

# 🔍 Direct dictionary access (when key is known to exist)
print(f"😂 LOL means: {acronyms['LOL']}")

# 📦 Display all key-value pairs in the dictionary
print("📚 Acronym Dictionary Contents:")
print(acronyms.items())  # Outputs a list-like view of tuples


# ======================== 🍽️ MENU DICTIONARY WITH LISTS ========================

# Nested dictionary: meal names as keys, food item lists as values
menus = {
    'Breakfast': ['Egg Sandwich', 'Bagel', 'Coffee'],
    'Lunch': ['BLT', 'PB&J', 'Turkey Sandwich'],
    'Dinner': ['Soup', 'Salad', 'Spaghetti', 'Taco']
}

# 🌀 Loop over both keys and values using .items()
print("\n🍴 Today's Menu:")
for meal_name, items in menus.items():
    print(f"{meal_name}: {', '.join(items)}")





# Import the regular expressions module to work with patterns in text
import re

# -------------------------------
# Reading Email Addresses from a File
# -------------------------------

# Open the file named 'info.txt' in read mode ('r')
# The 'with' statement automatically closes the file after reading
with open('info.txt', 'r') as data:
    # Read the entire contents of the file into a variable
    contents = data.read()

# Use a regular expression to search for an email address pattern in the contents
# Explanation of the pattern:
# \w+      : One or more word characters (letters, digits, or underscores)
# \@       : The '@' symbol (escaped with \ to treat it as a literal character)
# \w+      : One or more word characters again (for the domain name)
# \.       : A dot '.' symbol (escaped to be treated as a literal dot)
# \w+      : One or more word characters (for the domain extension like com, org, etc.)
result = re.search(r'\w+@\w+\.\w+', contents)

# Print the matched email address (if found)
# .group() gives you the actual string that was matched
print(result.group())




from dataclasses import dataclass

# ======================== 📁 Project Class (DataClass) ========================

@dataclass
class Project:
    name: str
    payment: int
    client: str

    def __str__(self):
        return f'📌 Project Name: {self.name}, 💰 Payment: ₹{self.payment}, 👤 Client: {self.client}'

# ⚠️ Avoid redefining with same class name: renaming second 'project' class for clarity
class LegacyProject:
    def __init__(self, name, payment, client):
        self.name = name
        self.payment = payment
        self.client = client

    def __str__(self):
        return f'📌 Project Name: {self.name}, 💰 Payment: ₹{self.payment}, 👤 Client: {self.client}'


# =============================== 👨‍💼 Base Employee Class ===============================

class Employee:
    """
    🧱 Base class for all employee types.
    Stores general employee details.
    """
    def __init__(self, fname, lname, position, project='Fresher'):
        self.fname = fname
        self.lname = lname
        self.position = position
        self.project = project

    def employee_info(self):
        print(f"👨‍💼 Employee Name: {self.fname} {self.lname}")

    @classmethod
    def change_minimum_wage(cls, new_wage):
        if new_wage > 3000:
            raise ValueError("⚠️ Company is bankrupt.")
        cls.minimum_wage = new_wage


# ============= ⏱ Hourly + Monthly Salary Employee =============

class HourlyMonthlySalaryEmployee(Employee):
    """
    🕒 Employee paid based on hours worked at an hourly rate.
    """
    def __init__(self, fname, lname, position, hours, hourly_rate):
        super().__init__(fname, lname, position)
        self.hours = hours
        self.hourly_rate = hourly_rate

    def cal_weekly_paycheck(self):
        return self.hours * self.hourly_rate


# ============= 💼 Weekly Fixed Salary Employee =============

class WeeklySalaryEmployee(Employee):
    """
    💼 Fixed salary employee with weekly paycheck.
    """
    def __init__(self, fname, lname, position, salary):
        super().__init__(fname, lname, position)
        self.salary = salary

    def cal_weekly_paycheck(self):
        return self.salary / 52  # Assumes 52 weeks in a year

    def __str__(self):
        return f'{self.fname} {self.lname} - 💰 ₹{self.salary}'


# ============= 🧾 Weekly Commission + Salary Employee =============

class WeeklyCommissionSalaryEmployee(WeeklySalaryEmployee):
    """
    💼+📈 Employee with base salary + sales commission.
    """
    def __init__(self, fname, lname, position, salary, sales_num, sales_rate):
        super().__init__(fname, lname, position, salary)
        self.sales_num = sales_num
        self.sales_rate = sales_rate

    def cal_weekly_paycheck(self):
        base_salary = super().cal_weekly_paycheck()
        commission = self.sales_num * self.sales_rate
        return base_salary + commission


# =============================== 🧪 Example Usage ===============================

employee1 = WeeklySalaryEmployee('Rajsekhar', 'Singh', 'AI/Data Engineer', 100000)
employee2 = Employee("Ji-Soo", "Lauren", "Tester")

print("📌 Position:", employee1.position)
print("🧾 Internal Dictionary:", employee1.__dict__)
print("🔍 Accessing fname from dict:", employee1.__dict__['fname'])

# Calling instance method using both ways:
Employee.employee_info(employee1)       # Standard way
employee1.employee_info()               # Shortcut/Instance way


# ============================test ===========================================
class Employees:
    def __init__(self,name,age,position,salary):
        self.name=name
        self.age=age
        self.position=position
        self.salary=salary

    def info(self): 
        print(f'employee name is {self.name},his position is {self.position}and his salary is ₹{self.salary}')


employees1=Employees('rajsekhar singh',18,'data engineers',1000000)

print(employees1.__dict__)              #In the back end information is saved like in the form of dictionary
print(employees1.__dict__['name'])      #Proof of that it's in the form of dictionary saved

Employees.info(employees1)              #Accessing thefunction from the class by mentioning the class
employees1.info()                       #A shortcut to access the functions of the class without mentioning the class



"""1. Write a Python program that takes a string as input and determines if it is a 
palindrome (reads the same forwards and backward, ignoring case and 
spaces). For example, "Racecar" and "A man a plan a canal Panama" are 
palindromes."""

text=input('what is the text :')
lower_text = text.lower()
reversed=''
n=len(text)+1
for i in range(-1,-n,-1):
    print(lower_text[i])
    reversed=reversed+lower_text[i]
print(f' Foreward : {lower_text} ,Backward :{reversed} ')  
if lower_text==reversed :
    print('the sentance is a palindrome .')  
else:
    print('Bro did you fail in EPT !')    





# ===========================================================
# 🔍 FILE SEARCH UTILITY USING PATTERNS, METADATA & ZIP
# ===========================================================

import os           # To interact with the file system
import fnmatch      # For pattern-based file matching (wildcards)
import shutil       # For file/folder copy and move operations
import zipfile      # For creating and extracting ZIP archives
from datetime import datetime, timezone  # For file modification timestamps

# ===========================================================
# 📁 FILE MATCHING FUNCTIONS — Find Files Using Patterns
# ===========================================================

# Finds the first file that matches a wildcard pattern
def match(path, search):
    for filename in os.listdir(path):
        if fnmatch.fnmatch(filename, search):
            print(f"[MATCH] {filename}")
            break

# Finds the first file that starts with the given string
def start_with(path, search):
    for filename in os.listdir(path):
        if filename.startswith(search):
            print(f"[STARTS WITH] {filename}")
            break

# Lists all files that end with the given extension/suffix
def end_with(path, search):
    for filename in os.listdir(path):
        if filename.endswith(search):
            print(f"[ENDS WITH] {filename}")

# ===========================================================
# 🗓️ FILE METADATA FUNCTIONS — Modified Date of Files
# ===========================================================

# Converts a timestamp to a readable date
def get_date(timestmp):
    return datetime.fromtimestamp(timestmp, tz=timezone.utc).strftime('%d %b %Y')

# Lists all files in the folder with their last modified date
def get_file_attrs(folder_path):
    with os.scandir(folder_path) as entries:
        for file in entries:
            if file.is_file():
                info = file.stat()
                print(f"[MODIFIED] {get_date(info.st_mtime)} - {file.name}")

# ===========================================================
# 🧭 FOLDER TRAVERSAL — Walk Through All Files and Subfolders
# ===========================================================

# Recursively walks through a directory and prints all files
def traverse(folder_path):
    for fldpath, dirs, fls in os.walk(folder_path):
        print(f'[FOLDER] {fldpath}')
        for fn in fls:
            print(f'\t[FILE] {fn}')

# ===========================================================
# 🛠️ FILE OPERATIONS — Copy, Move, Rename
# ===========================================================

def copyfile(src, dst):
    """Copy a single file from src to dst"""
    shutil.copy(src, dst)

def copyfolder(src, dst):
    """Copy an entire folder from src to dst"""
    shutil.copytree(src, dst)

def mv_file(src, dst):
    """Move a file or folder"""
    shutil.move(src, dst)

def rename(src, dst):
    """Rename a file or folder"""
    os.rename(src, dst)

# ===========================================================
# ❌ FILE REMOVAL — Delete a File with Safety Check
# ===========================================================

def remove_file(f):
    """Delete a file if it exists"""
    if os.path.isfile(f):
        try:
            os.remove(f)
            print(f"[REMOVED] {f}")
        except OSError as e:
            print(f"[ERROR] Could not remove {f}: {e.strerror}")
    else:
        print(f"[ERROR] {f} is not a valid file")

# ===========================================================
# 📦 ZIP FUNCTIONS — Create and Extract ZIP Files
# ===========================================================

def create_zip_file(zipn, files):
    """Create a ZIP file from a list of file paths"""
    with zipfile.ZipFile(zipn, 'w', allowZip64=True) as archive:
        for i in files:
            archive.write(i)
            print(f"[ZIPPED] {i}")

def read_zip_file(zipn):
    """List contents of a ZIP file with file sizes"""
    with zipfile.ZipFile(zipn, 'r') as archive:
        for i in archive.namelist():
            zinfo = archive.getinfo(i)
            print(f"[ZIP ENTRY] {i} => {zinfo.file_size} bytes")

def extract_zip_file(zipn, fn, path):
    """Extract a single file from ZIP to a target directory"""
    with zipfile.ZipFile(zipn, 'r') as archive:
        archive.extract(fn, path=path)
        print(f"[EXTRACTED] {fn} to {path}")

def extract_all_zip_file(zipn, path):
    """Extract all files from ZIP to a target directory"""
    with zipfile.ZipFile(zipn, 'r') as archive:
        archive.extractall(path=path)
        print(f"[EXTRACTED ALL] to {path}")

# ===========================================================
# 🧪 USAGE EXAMPLES — Run These to See It in Action
# ===========================================================

FOLDER = r'd:\study\python 3 funamentail course-1'

# 📁 Pattern Matching Examples
start_with(FOLDER, 'acronyms')      # Files starting with 'acronyms'
end_with(FOLDER, '.txt')            # Files ending with '.txt'
match(FOLDER, 'donkey*')            # Files matching wildcard pattern
match(FOLDER, '*_.py')              # Files matching wildcard pattern

# 🗓️ File Metadata
get_file_attrs(FOLDER)

# 🧭 Folder Traversal
traverse(r'd:\study')

# ❌ Delete a File (if it exists)
remove_file(r'./files/text.txt')

# 📦 ZIP Operations
files_to_zip = [
    rf'{FOLDER}\acronyms.txt',
    rf'{FOLDER}\weather.py',
    rf'{FOLDER}\file-handling.py',
    rf'{FOLDER}\employee.py',
    rf'{FOLDER}\donkey.py',
]

# Create ZIP Archive
create_zip_file(rf'{FOLDER}\python3.zip', files_to_zip)

# List ZIP Contents
read_zip_file(rf'{FOLDER}\python3.zip')

# Extract All ZIP Contents to a Subfolder
extract_all_zip_file(
    rf'{FOLDER}\python3.zip',
    rf'{FOLDER}\unzipped'
)

import requests  # To make HTTP requests to external APIs

# ============================================================
# 🚀 ASTRONAUTS IN SPACE — Using the Open Notify API
# ============================================================

# Make a GET request to get data about people currently in space
response = requests.get('http://api.open-notify.org/astros.json')

# Convert the response to a Python dictionary (JSON format)
json = response.json()

# Print the entire JSON response (for debugging or exploration)
print(json)

# Print just the names of the people in space
print('People in space:')
for person in json['people']:
    print(person['name'])       

# ============================================================
# ☁️ CURRENT WEATHER REPORT — Using WeatherAPI
# ============================================================

# NOTE: Replace this API key with your own if it stops working
# The API returns current weather for the city 'bangalore'
weather_api = requests.get(
    'http://api.weatherapi.com/v1/current.json?key=d73af82268fa4a64a3c200007231402&q=bangalore&aqi=no'
)

# Parse the JSON weather response
weather_report = weather_api.json()

# Safely extract nested values using `.get()`
temp = weather_report.get('current', {}).get('temp_c')                   # Temperature in Celsius
condition = weather_report.get('current', {}).get('condition', {}).get('text')  # Weather description
location = weather_report.get('location', {}).get('name')               # Location name

# Display a clean and friendly weather message
print(f"Weather in {location} is {condition} and temperature is {temp}° Celsius")

# ============================================================
# 🌡️ TEMPERATURE CHECK — Decision Based on Temperature
# ============================================================

temperature = 18  # Example temperature value in °C

# Check if the temperature is outside a comfortable range
if temperature > 26 or temperature < 5:
    print("🌡️ It's extreme outside — Stay inside!")
else:
    print("🌤️ Weather looks pleasant — Enjoy outside!")

# ============================================================
# 🌦️ FORECAST CHECK — Based on Textual Description
# ============================================================

forecast = "rainy"  # Example forecast; could be 'sunny', 'cloudy', etc.

# Decide whether to go outside based on forecast
if forecast.lower() != "rainy":
    print("☀️ No rain — Go outside!")
else:
    print("🌧️ It's rainy — Stay inside.")

# ============================================================
# ✅ BOOLEAN CHECK — Raining or Not Using a Flag
# ============================================================

is_raining = True  # This flag represents if it's currently raining (True or False)

# Use the boolean flag to decide activity
if is_raining:
    print("☔ It’s raining — Stay inside.")
else:
    print("🕶️ No rain — Go outside!")



#promble 1
amount=int(input('how money do you have :'))
no_cholcolate=amount/1
no_exchange_cholcolate=no_cholcolate/5
print(f'''extra no of cholcolate : {no_exchange_cholcolate}
total  no chocolate Bob eat {no_exchange_cholcolate + no_cholcolate }''')


print('\n',1,'\n')

# python provide a build in function to convert an interger into binary ,octal & hexadecima
"""
Ob-binary , Oo-octave , Ox-hexdecimal 
"""
print(bin(11))
print(oct(11))
print(hex(11))

# TO covert any conbinatio of a+bj
x,y=10,20 ;A=complex(x,y)
print(A)
print(A.real)
print(A.imag)

string_input = input('what is string :') #by default input store it in string  data type
print(f' This is the intrger {int(string_input)} , This is the float {float(string_input)}')

spam='Spam' # here ther will be box name spam contain Spam 
dance,ham='Yum','Dance'  # it is a positional tuple assignment 
a,b,c,d='spam'
a,*b='spam'         # here the output for  print(b)---> ['p', 'a', 'm']

print(dance)

# Write a program to find the factorial of a number n?

def factorial(number):
    holder=1
    for i in range(1, number + 1):
        holder*= i
    return (holder)    

print(factorial(4))


# Write a program to display few odd multiples of a odd number n ?

num=int(input('what is your odd number : '))
for i in range(num,100):
    data=num*i
    if data%2!=0:
        print(data)
    else:
        continue   
    
#5. The Head Librarian at a library wants you to make a program that calculates the fine for returning the book after the return date. You are given the actual and the expected return dates. Calculate the fine as follows: 
	#a. If the book is returned on or before the expected return date, no fine will be charged, in other words fine is 0. 
	#b. If the book is returned in the same month as the expected return date, Fine = 15 Rupees × Number of late days 
	#c. If the book is not returned in the same month but in the same year as the expected return date, Fine = 500 Rupees × Number of late months 
	#d. If the book is not returned in the same year, the fine is fixed at 10000 Rupees. 
    
return_date=input('what day was the book returned :')   
expired_date=input('what is the expired data :') 



#Given the number of hours and minutes browsed, write a program to calculate bill for Internet Browsing in a browsing center. The conditions are given below.
#(a) 1 Hour Rs.50
#(b) 1 minute Re. 1
#(c) Rs. 200 for five hours
#Boundary condition:  User can only browse for a maximum of 7 hours  Check boundary conditions 

total_time=int(input('total time spend browsing in secounds :'))
hours=total_time//3600
if hours <= 7 :
    left=total_time-hours*3600
    minute=left//60
    left2=left-minute*60
    print(f'time spend : {format(hours,'.2f')} HOURS  , {minute : .2f} MINUTE  , {left2} SECONDS')              # DIFFENT ways to print answer using format
    print(f'for hour rate {hours * 50}  ,for minute rate {minute *1} ')

elif hours == 5:
    print('Rs.200')

else :
    print('you are crossing the boundary condition')    


# ===============================================================
# 💸 EXPENSE TRACKER — Add Transactions and Calculate Total
# ===============================================================

# Create an empty list to store expense amounts
expenses = []

# Ask user how many transactions/records they want to enter
num = int(input('How many records do you want to enter: '))

# Use a loop to take inputs that many times
for i in range(num):  # i will range from 0 to num-1
    print(i)  # Shows the current iteration (optional)
    
    # Ask for the transaction amount and convert it to an integer
    transaction = int(input('What is your transaction: '))
    
    # Add the transaction to the expenses list
    expenses.append(transaction)

# Calculate the total amount spent using sum()
total = sum(expenses)

# Print the total spent — 'sep' is used to avoid space between $ and amount
print('You spent $', total, sep='')


# ===============================================================
# 🍽️ MENU ACCESS & NESTED LIST INDEXING
# ===============================================================

# A list of lists, where each inner list represents a meal menu
menus = [
    ['Egg Sandwich', 'Bagel', 'Coffee'],          # Breakfast
    ['BLT', 'PB&J', 'Turkey Sandwich'],           # Lunch
    ['Soup', 'Salad', 'Spaghetti', 'Taco']        # Dinner
]

# Access and print the entire breakfast menu (index 0)
print('Breakfast:', menus[0])

# Access and print the second item in the breakfast menu (index 1)
print('Breakfast (second item):', menus[0][1])


# ===============================================================
# 🔁 LIST MUTABILITY — Changing List Items
# ===============================================================

# Create a sample list of items (originally a breakfast menu)
dance = ['Egg Sandwich', 'Bagel', 'Coffee']

# Change the second item in the list to something else (e.g., "Dosa")
dance[1] = "Dosa"  # Lists are mutable — we can modify their contents

# Print the modified list to see the change
print(dance)

# ============================== 🔐 PASSWORD VALIDATION ==============================

# Ask the user to enter a password
data = input("What is your password: \n")

# ---------------- LENGTH CHECK ----------------
# Check if password length is at least 8 characters
if len(data) >= 8:
    print("✅ Length-wise check passed (at least 8 characters).")
else:
    print("❌ Length-wise check failed (less than 8 characters).")

# ---------------- ALPHANUMERIC CHECK ----------------
# Check if the password contains letters and/or numbers
# NOTE: isalnum() should be used as a function (with parentheses)
if data.isalnum():
    print("✅ Password contains letters and/or numbers.")
else:
    print("❌ Password should contain only letters and/or numbers (no special symbols).")

# ---------------- UPPERCASE CHECK ----------------
# Initialize a flag to track if uppercase letters are found
condition_upper = False

# Loop through each character to check for uppercase letters
for i in data:
    if i.isupper():
        print("✅ Uppercase check passed (contains at least one uppercase letter).")
        condition_upper = True
        break  # No need to check further once found

# If no uppercase letter was found
if not condition_upper:
    print("❌ Uppercase check failed (no uppercase letters found).")

# ---------------- LOWERCASE CHECK ----------------
# Check if there is at least one lowercase character in the password
if any(char.islower() for char in data):
    print("✅ Lowercase check passed (contains at least one lowercase letter).")
else:
    print("❌ Lowercase check failed (no lowercase letters found).")

#Check Prime Number in Python

from sympy import * # type: ignore

g1 = isprime(30)
g2 = isprime(13)
g3 = isprime(2)

print(g1) 
print(g2) 
print(g3)


#===========================================

n = 11
if n <= 1:
    print(False)
else:
    is_prime = True
    for i in range(2,n):
        if n % i == 0:
            is_prime = False
            break
    print(is_prime)


    
    class add_book:
        def __init__(self,name,author):
            self.name=name
            self.author=author
            self.states='true'
        

# ---------------------------------------------------------------------------------------------------------------------------------------------------

contacts = {
    'number': 4,
    'students': [
        {'name': 'Sarah Holderness', 'email': 'sarah@example.com'},
        {'name': 'Harry Potter', 'email': 'harry@example.com'},
        {'name': 'Hermione Granger', 'email': 'hermione@example.com'},
        {'name': 'Ron Weasley', 'email': 'ron@example.com'}
    ]
}
print('Student emails:')
for student in contacts['students']:
    print(student['email'])

file=open(r"d:\study\python 3 funamentail course-1\test\log_data.log")
seach_obj=input('what are searching:\n')
for data in file:
    if seach_obj in data :
        print(f'match found : {data}')
file.close()


#====================addition info ==========

x = "awesome"       #global

def myfunc():
  x = "fantastic"       #local   
  print("Python is " + x)

myfunc()

print("Python is " + x)



x = "awesome"

def myfunc():
  global x          #makes this x globals
  x = "fantastic"

myfunc()

print("Python is " + x)


List=[1,2,3]
X,Y,Z=List
print(X,Y,Z)

print("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ " )


import pickle

data = {"name": "John", "age": 30}
filename = "recipes.pkl"

# Serialize (save) the data to a file
with open(filename, 'wb') as file:
    pickle.dump(data, file)

# Deserialize (load) the data from the file
def load_recipes(filename):
    with open(filename, 'rb') as file:
        unpickled_data = pickle.load(file)
        print(f"✅ Loaded data: {unpickled_data}")
        return unpickled_data

# Example usage
load_recipes(filename)




p=int(input('number of pizza :'))
s=int(input('no of slices in pizza :'))
f=int(input('no of friends :'))
total_slices=p*s
each_share=total_slices//(f+1)
Emilys_share=each_share+3
print(f'no slices Emily eats in total : {Emilys_share}')


def read_text_file(fn):
    with open(fn,'r') as fholder:
        print(fholder.read())
    
def read_line_text_file(fn):
    with open(fn,'r') as fholder:
        lines=fholder.readlines()
        for line in lines:
            print(line)

string='LOL laugh out loud \n'     

def write_append_text_file(fn,string):
    with open(fn,'a+') as fholder:
        fholder.write(string)
      
iterable=['LOL laugh out loud \n',
'NASA National Aeronautics and Space Administration \n',
'HTML HyperText Markup Language \n',]

def writelines_append_text_file(fn,iterable):
    with open(fn,'a+') as fholder:
        fholder.writelines(iterable)



# Import the regular expression module
import re

# Define a function that checks if a password is valid based on certain rules
def validate_password(password):
    # Regular expression pattern explanation:
    # ^               : Start of the string
    # (?=.*\d)        : Must contain at least one digit (0–9)
    # (?=.*[a-z])     : Must contain at least one lowercase letter
    # (?=.*[A-Z])     : Must contain at least one uppercase letter
    # .{8,}           : Must be at least 8 characters long
    # $               : End of the string
    # r" "            : sayes the python to contider \ as raw string 
    pattern = r"^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,}$"

    # Use re.match() to see if the password matches the pattern
    match = re.match(pattern, password)

    # Return True if it matches the pattern, otherwise False
    return bool(match)

# Assign a sample password to test
password1 = "P@ssjbln123"  # This contains uppercase, lowercase, digit, and more than 8 characters

# Call the function and print the result (True means valid password)
print(validate_password(password1))

# You can also store the result in a variable to use it later
result = validate_password(password1)


# ------------------- OPTIONAL EXPLANATION BELOW -------------------
# The below line is commented out because it's not correct Python syntax.
# It seems to be from JavaScript style (due to '/g' at the end).
# Correct Python version would be something like:
# print(re.search(r"^(?=[a-zA-Z])(?=.*\d).{8,12}$", password))

# Explanation of that pattern:
# ^               : Start of the string
# (?=[a-zA-Z])    : First character must be a letter (uppercase or lowercase)
# (?=.*\d)        : Must contain at least one digit
# .{8,12}         : Total length must be between 8 and 12 characters
# $               : End of the string




