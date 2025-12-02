
"""
    '''
    This is a comment
    written in
    more than just one line
    
    '''
"""

# ==============================================================================
# 🧮 ARITHMETIC OPERATORS
# ==============================================================================

"""
    OPERATORS  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    === 🔢 Arithmetic Operators ===
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        + - / // * ** %
        ➕ UNARY OPERATOR: acts on only one operand  
            + --> returns operand value  
            - --> reverses the sign of the operand's value  
                ex: if a = -4 then -a is 4

    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    === ➗ BINARY OPERATOR ===  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        ➕ ADDITION OPERATOR (+): returns the sum of the operands  
        ➖ SUBTRACTION OPERATOR (-): subtracts the value of the right operand from the left operand  
        / : gives the float value as output  
        // : gives the output as a whole number form  
                📝NOTE: if we have floating number as argument, then the output is also floating  
        % : gives the remainder as a whole number form  
            ex:  
                19 % 6 --> the output is 1, because we divide 19 by 6 and the remainder is 1  
        ** : exponential operator  
            ⚠️ Remember: it operates from right to left, whereas in general it goes from left to right  

            📝 NOTE  
            🧪 Exercise:  
                9.2 / 4 --> 2.3  
                9.2 // 4 --> 2  
                9.2 % 4 --> 1.2  # divide and take the remainder  
                5 // -3 --> -2  
                -5 // 2 --> -3  # normally -2.5 but rounded off to -3  
                -7 / 4 --> -1.75  
                -7 // 4 --> -2  # divide and round toward more negative  
                -7 % 4 --> 1    # 4 * 2 = 8, since 8 > -7, remainder is positive  
                7 % -4 --> -1   # sign adjusted to get closer to dividend  
"""

# ==============================================================================
# 🧮 TIME CONVERSION EXAMPLE
# ==============================================================================

"""
    Q) user : will enter how many secounds he study and we have to convert it into in hours , minutes , secounds format 

    total_time=int(input('total time you study in secounds'))
    hours=total_time//3600
    left_time=total_time-hours*3600
    minutes=left_time//60
    secounds=left_time-minutes*60
    print(f'Study time : {hours:.0f} hours , {minutes:.0f} minutes , {secounds:.0f}secounds')
"""

# ==============================================================================
# 📝 AUGMENTED ASSIGNMENT OPERATORS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    === 🧮 AUGMENTED ASSIGNMENT OPERATORS ===
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 

        a += 1 ---> a = a + 1
"""

# ==============================================================================
# 📊 RELATIONAL & COMPARISON OPERATORS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    
    === 📏 RELATIONAL OPERATORS === 
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 

        <  
        >  
        <=  
        >=  
        ==   📝NOTE: here it does type conversion for integer and float  
        !=

    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    
    == 🔍 COMPARISON OPERATOR ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        🔡 For strings, we compare ASCII codes  
        a (97) > A (65) — length of string not considered  
        # Get ASCII code using ord(<string>)  
            'Apple' > ' Apple' iss True — space has ASCII 32, which is less than 'A' (65)  
        3 >= 3.0 --> returns True  

        📝 NOTE  
            0.1 + 0.1 + 0.1 == 0.3 --> returns False  
            Because print(0.1 + 0.1 + 0.1) gives 0.30000000000000004 — due to floating point approximation  
"""

# ==============================================================================
# 🆔 IDENTITY OPERATORS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    
    == 🆔 IDENTITY OPERATORS ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        a is b      : True if both point to the same object (same memory location)  
        a is not b  : True if both point to different objects  

        # Find memory location using: print(id(a))
        # Find the boolean of the argument: bool(-5) --> True

        📝 NOTE  
            s1 = 'abc'  
            s2 = input('enter the string')  
            enter the string: abc  
            print(s1 == s2) --> True  
            print(s1 is s2) --> False  
            s3 = s1  
            print(s1 == s3) --> True  
            print(s1 is s3) --> True  

            Similarly,  
            i = 2.3 + 5j  
            k = 2.3 + 5j  

            Similarly,  
            k = 2.5  
            s2 = float(input('enter the float number:'))  
            print(k == s2)  
            print(k is s2)  
            print(f's2 : {id(s2)}')  
            print(f'k : {id(k)}')

        🧠 NOTE  
            This happens in the following cases:  
            → only for string input type  
            → very big integers  
            → floating-point and complex numbers  
"""

# ==============================================================================
# 🧠 LOGICAL OPERATORS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == 🧠 LOGICAL OPERATORS ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        x or y      if x is False then return y as result, else x  
                    it only evaluates second argument if first is False  
        x and y     if x is False then return x as result, else y  
                    it only evaluates second argument if first one is True  
        not x       it does complement
"""

# ==============================================================================
# 🔢 BITWISE OPERATORS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == 🔢 BINARY OPERATORS ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        & (and) : does multiplication  
        | (or)  : does OR  
        ^ (XOR) : exclusive OR  
        ~ (not) : NOT gate  

        ex:  
            use bin() to get the binary representation of the argument inside  

            print(bin(13))  
            print(bin(12))  
            print(13 & 12)  
            print(bin(13 & 12))
"""

# ==============================================================================
# 🎯 BITWISE OPERATIONS EXAMPLES
# ==============================================================================

"""
         Q) Emily is studying bitwise operations and is working on a project that involves isolating specific bits from integers. 
            She needs to write a program that takes an integer and the number of bits N as input and outputs the value of the lowest N bits of the integer.
            Help Emily in her project to understand and visualize how bitwise operations work in practical scenarios.

            Input format :
            The first line of input consists of an integer A, representing the given integer.

            The second line consists of an integer N, representing the number of bits to extract.

            Output format :
            The output displays "Result: " followed by an integer representing the value of the lowest N bits of the given integer
            -----------------------------------------
            A=int(input())
            N=int(input())          #here we take the number above and then select how many last bits form the above to display
            print(f'Result: {A&(1<<N)-1}')     
            ------------------------------
            EXPLANATION :

            1 << N  --- #Shifts the binary 1 left by N positions.

            Example: 
                if N = 4,
                1 << 4 = 16   → binary: 10000


            (1 << N) - 1  ---# Subtracts 1, giving a mask of N ones in binary.

            Example: 
                if N = 4,
                (1 << 4) - 1 = 15   → binary: 1111

            A & ((1 << N) - 1)  --# Performs bitwise AND between A and the mask. This keeps only the last N bits of A, all other bits become zero.
   
            
         Q) Jhon was given two numbers, and he need to swap the values without using any temporary variables. Instead, he'll use the XOR operation to achieve this. 
            Help him by writing a program that takes the two numbers as input from the user and swaps their values using XOR. Finally, display the swapped values.

            a=int(input())
            b=int(input())
            a=a^b               # here ^ act like XOR 
            b=b^a
            a=a^b
            print('''After swapping:''')
            print(a)
            print(b)   
"""

# ==============================================================================
# 🎯 OPERATOR PRECEDENCE
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == 🎯 OPERATOR PRECEDENCE (ORDER OF MULTIPLE OPERATORS) == 
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        ()  
        **  
        * , / , // , %  
        + , -  
        &  
        ^  
        |  
        < , <= , > , >= , != , ==  
        is , is not  
        not  
        and  
        or  

        ex:  
            print(7 >= 7 and 7 + 7 > 7) --> True  

        📝NOTE   
            If you get an equation where the operators are of the same order, then it takes associativity.  
            Generally it is from left to right.  
            BUT in case of ** we do from right to left.  
            ex:  
                3 ** 3 ** 2  
                correct: 3 ** (3 ** 2)  
                    wrong  : (3 ** 3) ** 2
"""

# ==============================================================================
# ➕ CONCATENATION & REPLICATION
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == ➕ CONCATENATION == 
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        'and' + 'then' --> andthen  
        'and' + ' ' + 'then' --> and then  

    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    ==  🔁 REPLICATION  == 
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        'and' * 2 --> andand  
"""

# ==============================================================================
# 🧮 EXPRESSION EVALUATION
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == 🧮 EVALUATING ARITHMETIC EXPRESSIONS ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        first have the expression and evaluate sub-expressions  
        performs implicit conversion: converts int to float, bool to int, int to complex  
            📝NOTE  
                a = 3  
                b = 2.5  
                output = a / b          # here int to floating-point conversion  
                print(output)  

                print(3 + (2 + 2j)) --> (5+2j)  

    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == 📊 EVALUATING RELATIONAL EXPRESSIONS ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        The output format is bool  
        a < b < c is evaluated as a < b and b < c  

    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == 🧮 EVALUATING LOGICAL EXPRESSIONS ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        ex:  
        (5 < 10) and (10 < 5) or (3 < 18) and not 8 < 18 --> False  
"""

# ==============================================================================
# 🔄 DATA TYPE CONVERSION
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == 🔄 DATA TYPE CONVERSION (TYPE CASTING) ==
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        int()  
        float()  
        str()  
        complex()            # you can provide real part, and also the imaginary part separated by comma  
        bool()  

        #If you want to specify the data type of a variable, this can be done with casting.

            x = str(3)    
            y = int(3)    
            z = float(3)

        #You can get the data type of a variable with the type() function.

            print(type(x)) --> <class 'str'>
            print(type(y)) --> <class 'int'>
            print(type(z)) --> <class 'float'>

            
        # Python provides a built-in function to convert an integer into binary, octal & hexadecimal  
            0b - binary , 0o - octal , 0x - hexadecimal  

            print(bin(11))  
            print(oct(11))  
            print(hex(11))  

            # To convert any combination of a + bj  
            x, y = 10, 20  
            A = complex(x, y)  
            print(A)  
            print(A.real)  
            print(A.imag)  

            string_input = input('what is string :')   # by default input stores it as string data type  
            print(f' This is the integer {int(string_input)} , This is the float {float(string_input)}')  

            spam = 'Spam'                   # here there will be box named spam which will be storing 'Spam' as string  
            dance, ham = 'Yum', 'Dance'     # it is a positional tuple assignment  
            a, b, c, d = 'spam'  
            a, b, c, d = 0   # cannot unpack non-iterable int object here zero is not a list or iterable can seein below for print(b)
            print(a) --> s
            print(b) --> p
            print(c) --> a
            print(d) --> n
            a, *b = 'spam'                  # here the output for print(b) ---> ['p', 'a', 'm']  

            print(dance)  
"""

# ==============================================================================
# 📚 STANDARD LIBRARY MODULES
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    ==📚 STANDARD LIBRARY  ==
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  

        # math  
            Python provides a standard library function called math  
            step1: import math  
            step2: to use any function of the module do math.<function-name>  

            math.ceil(arg)              # return the ceiling value of the argument  
            math.sqrt(arg)  
            math.exp(arg)  
            math.fabs(arg)              # return the absolute value of the argument  
            math.floor(arg)  
            math.log(num, [base])  
            math.log10(num)  
            math.pow(base, exp)  
            math.sin(arg)  
            math.cos(arg)  
            math.tan(arg)  
            math.degrees(arg)  
            math.radians(arg)  

            math provides us two variables:  
            a = math.pi  
            b = math.e  

        # random  
            .random()                           # generate number between 0 <= number < 1  
            .randint(a, b)                      # generate number from a <= N <= b  
            .randrange(start, stop, step)       # internally it generates a list from start to stop with step then randomly chooses number from the list  
            .choice([......])                   #Computer randomly chooses one from the list     
            print(random.randint(1, 10))        # Prints a random integer between 1 and 10 (inclusive)

        # statistics  
            📝NOTE: here we pass a list as argument  i.e.. []  

            .mean(seq)    
            .median(seq)  
            .mode(seq)                                         

        PROBLEM : predict the output  
        5 < 5 or 10           --> 10  
        5 < 10 or 5           --> True  
        5 < (10 or 5)         --> True  
        5 < (5 or 10)         --> False  

        print(3 + 5 / 8)

  

        ---------------------------------------------------  
            what is the output for the following code  
            a) -5 ** 2           --> -25        # because ** has higher priority and also it does from right to left  
            b) math.pow(-5, 2)   --> +25  
            c) -5 * -5           --> +25  
        ---------------------------------------------------  
            bool('0') == bool(0) --> False  
        ---------------------------------------------------  
            13 or len(5)         --> True  
            len(5) or 13         --> Error      # len() only takes string as the argument  
"""

# ==============================================================================
# 🎯 CONDITIONAL STATEMENTS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == 🎯 CONDITIONAL STATEMENTS (if-elif-else)  ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        x = int(input('what is x :'))  
        y = int(input('what is y :'))  
        z = int(input('what is z :'))  
        if x > y:  
            if x > z:  
                print(x)  
            print(z)                           # here if condition false also it will print (z) → wrong -- add an else before  
        else:   
            if y > z:  
            print(y)  
        print(z)   
"""

# ==============================================================================
# 🎮 ROCK, PAPER, SCISSORS GAME
# ==============================================================================

"""
        # -------------------- 🎮 ROCK, PAPER, SCISSORS GAME EXAMPLE --------------------
            import random
        
            # Computer randomly chooses one from the list
            computer_choice = random.choice(["rock", "paper", "scissors"])

            # Prompt user for input
            user_choice = input('What do you choose? rock, paper, or scissors: ').lower()

            # Display computer's choice
            print('Computer chose:', computer_choice)

            # Game logic
            if computer_choice == user_choice:
                print("It's a tie! Try again.")
            elif computer_choice == "rock" and user_choice == "scissors":
                print('You lose 😏')
            elif computer_choice == "scissors" and user_choice == "paper":
                print('You lose 😏')
            elif computer_choice == "paper" and user_choice == "rock":
                print('You lose 😏')
            else:
                print('You win! 🎉')
"""

# ==============================================================================
# 🧮 CONDITIONAL EXAMPLES
# ==============================================================================

"""
        Q)
        progam (pg -230)


        n1,n2,n3=int(input('first no:')),int(input('secound no :')),int(input('third no:'))
        sum1=n1+n2+n3
        sum2=0
        if n1==n2 and n2!=n3:
            sum2=n3
        elif n2==n3 and n2!=n1:
            sum2=n1
        elif n1==n3 and n2!=n1:         # you can have multiple elif block 
            sum2=n2
        elif n1==n2==n3 :
            sum2=0    
        else:           # this block only executed when none of the block above satifyes
            sum2=sum1
        print(f'Input  of the number {n1},{n2},{n3} will give {sum1} and {sum2}')      
"""

# ==============================================================================
# 🔄 NESTED CONDITIONALS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    ==  NESTED if -elif - else ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        num1,num2,num3=int(input('enter your  1 number:')),int(input('enter your 2 number:')),int(input('enter your 3 number:'))
        max=0
        mid=0
        min=0
        if num1>num2 and num1>num3:
            max=num1
            if num2>num3:
                mid,min=num2,num3
            else:    
                mid,min=num3,num2
        if num2>num3 and num2>num1:
            max=num2
            if num1>num3:
                mid,min=num1,num3
            else:    
                mid,min=num3,num1       
        if num3>num2 and num1<num3:
            max=num3
            if num1>num2:
                mid,min=num1,num2
            else:    
                mid,min=num2,num1
        print(min,mid,max)
"""

# ==============================================================================
# 🔤 STRING METHODS IN CONDITIONALS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == USE OF .isupper, .islower , .isnumeric , .isalnum ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        user_input=input('Enter a Character :')
        if user_input.isupper():
            print('upper')
        elif user_input.islower():
            print('lower')    
        elif user_input.isnumeric():
            print('number')
        elif user_input.isalnum():
            print('number')
        else:
            print('you enter a special character !')  
"""

# ==============================================================================
# 💡 MODERN CONDITIONAL STYLING
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == STORING CONDITIONS ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━   

        traditional method
        -------------------

        deposit,years=int(input('what is the amount deposit : ')),int(input('how many years : '))
        if deposit<2000 and years >= 2 :
            print('interest rate  5% ')
        elif deposit >= 2000 and deposit<6000 and years <= 2 :
            print('interest rate  7% ') 
        elif deposit > 6000 and years >= 1 :
            print('interest rate  8% ')
        else:
            print('Invalid enters')           

        modern way
        ----------

        deposit,years=int(input('what is the amount deposit : ')),int(input('how many years : '))
        eligible_for_5percent= deposit<2000 and years >= 2 
        eligible_for_7percent= deposit >= 2000 and deposit<6000 and years <= 2
        eligible_for_8percent= deposit > 6000 and years >= 1

        if eligible_for_5percent :
            print('interest rate  5% ')
        elif eligible_for_7percent :
            print('interest rate  7% ') 
        elif eligible_for_8percent :
            print('interest rate  8% ')
        else:
            print('Invalid enters')    
"""

# ==============================================================================
# 📊 RANGE FUNCTION
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == 📊 RANGE FUNCTION ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━   
    range(<start>,<stop>,<step>) --> [start,start+1,.............,stop-1]

        range(0,5) --> [0,1,2,3,4]
        range(5) --> [0,1,2,3,4]
        range(0,6,2) --> [0,2,4]
        range(6,1,-1) --> [6,5,4,3,2]
    ex
        x = 2
        for i in range(x):      NOTE here the x value still remain 2 even if we are later incrementing 
            x += 1
            print (x, end=" ")
"""

# ==============================================================================
# 🔍 MEMBERSHIP OPERATORS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == OPERATURES  in AND not in  ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 

    check where the argument is in the strings,lists and tuple    
    "a" in 'trade' -->True
    1 not in [1,2,3,4,5,6] --> False
    "ade" in 'trade' -->True
"""

# ==============================================================================
# 🔁 LOOP STRUCTURES
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == for loop  ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 
    for i  in [1,2,3,4]:    #it good to use list for small things
        print(i**2)         #here does square 


    for i in range(100):    #it good to use list for large things
        print((i+1)**2)     #it does sqaure up to 100

        
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == while loop  ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 
    the code inside the while body runs until the while condition is false

    n=10    #initialization expreesion
    while n>0:      #test expression
       
        print(n)
        n-=1        #update expression
"""

# ==============================================================================
# ⏹️ LOOP CONTROL STATEMENTS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == break statements ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

    the brack statement immediately terminate the loop which is in and just get out of the present loop

    LIST=[]
    import random
    for i in range(10,51):
        LIST.append(i)
    COMPUTR_CHOICE=random.choice(LIST)
    time=0
    print('you have only five change to guess the number !')
    while time<5:
        user=int(input('what is your guess:'))
        if user==COMPUTR_CHOICE:
            print('you win')
            break               #even if the loop condition time<5 still True . it will terminate  the loop 
        else:                   NOTE there the  break statment directly goes to line 589 does not consider the while loop
            time+=1
    print(f'''you lose :( 
    COMPUTR_CHOICE is {COMPUTR_CHOICE}''') 

    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == continue statements ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

    this  forces the next iterattion of th e loop to take place

    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == break & continue statements  difference ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        print('the loop wiht " break " produces output as :')
        for i in range (1,11):
            if i%3 ==0:
                break       NOTE as i hit 3 and i%==3 is true it break the stament and jump out of loop if else and also for 
            else:
                print(i)
        print('the loop with "continue " produes output as :')            
        for i in range (1,11):
            if i%3==0;:
                continue
            else:
                print(i)    
"""


# ==============================================================================
# ➿ PASS STATEMENT
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == pass statment ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

    for i in range(0,10):
        pass
    print(i) -->9

    NOTE
        HERE 9 is output ,because inside the for loop it act like continue and at last i take value 9 and so it store i is 9 and send it print statement
"""

# ==============================================================================
# 🔄 NESTED LOOPS
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == NESTED LoopS==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

    for i in range(1, 6):
            for j in range(1, i + 1):
                print(i, end='')
            print()
"""

# ==============================================================================
# 💬 STRING FORMATTING
# ==============================================================================

"""
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    == F STRING &  format decimal ==  
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

    ----------------------------- Age Breakdown Script -------------------------------
        This script takes the user's age and breaks it down into decades and leftover years

        age = int(input("What is your age:\n"))         # \n moves the cursor to the next line after the prompt for neat input

        # Calculate how many full decades the user has lived
                                                        # Example: if age = 27 → 27 // 10 = 2 → 2 full decades
        decade = age // 10                              # Integer division gives the number of complete 10-year blocks

        # Calculate the number of leftover years after removing full decades
                                                        # Example: if age = 27 → 27 % 10 = 7 → 7 remaining years
        year = age % 10                                 # Modulus (%) gives the remainder

        # Display the breakdown of age using an f-string for clear formatting
        print(f'🧓 You are {decade} decade(s) old and {year} year(s) old.')

    ------------------------------- TAX CALCULATION TOOL -------------------------------
        # This section calculates the total amount after applying tax to a base price

        base_amount = 200  # in ₹ (Rupees)      # Original amount before tax

        tax_percentage = 0.11                   # The tax rate (in decimal) → 11% = 0.11

        total_amount = base_amount + (base_amount * tax_percentage)         # Calculate the total amount including tax

        # Display the final price after tax
        
        print(f"🧾 Total amount after 11% tax: ₹{total_amount:.2f}")        NOTE .2f formats the result to show 2 decimal places (like 222.00)
"""




#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#============= lambda fuction ========== 
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

nums = [1, 2, 3, 4]
squared = list(map(lambda x: x**2, nums))       #if you try to print map it give the address location
print(squared)  # [1, 4, 9, 16]
                #lambda x: x**2 → a quick function that squares x.
                #map() applies it to every item in nums.

