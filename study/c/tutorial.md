# -----------------
# variables
# -----------------


it can only start form Alphabate,_ not and number or character
case sensative
no other sumbol other than  _
no comma,space

// THIS IS SINGLE LINE COMMENT

/*
this is a mulitple line comment
*/
# -----------------
# skeleton
# -----------------

#include<stdio.h>

int main(){
    printf("Hello World");
    return 0;
}


# -----------------
# print statment 
# -----------------

printf("Hello World");
printf("Hello World");
// here it print all in one line to make in differencr line

printf("Hello World\nraj");  // here ever sentence end with ; it like full stop 


# format printing

# INTEGERS
int age=25;
printf("age is %d",age);

# REAL NUMBER
float pi = 3.14
printf("name is %f",pi);

# character
char star="*"
printf("character is %c",star)

# -----------------
# input statment 
# -----------------
int age;
scanf("%d",&age);   // here before saveing the value we have to define the variable to hold it and & is like search in this location at the first we seficify what type of data to take 


# -----------------
# type declaration instruction
# -----------------

// just make a variable
int number;

int d=2,e       // here we make a int variale d and assignent value of 2 also a variale e with no value

// in c we can not assign multiple variable and make variable same time

int a=b=c=32;       // here it give error

int a=32,b=32,c=32;     // this will be correct

int a,b,c;
a=b=c=32;       // her it give correct answer

printf("multiplication of the number are:%d",a*b)


# -----------------
# artimetical instruction
# -----------------

#include<math.h>

int d =pow(a,b)         // in here it is like  a^b or a**b

int d = a % b       // only for interger but does not work for float
