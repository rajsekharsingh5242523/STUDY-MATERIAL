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



#include<stdio.h>
int rec(int x);

int rec(int x) {
    int f;
    if (x == 1)
        return 1;
    else
        f = x * rec(x - 1);
    return f;
}

int main() {
    int fact;
    fact = rec(3);
    printf("%d",fact);
    return 0;
}


#include <stdio.h>

int main() {
    char s[] = "Learning";
    printf("%s", &s[2]);
    printf("\n%s", s);
    printf("\n%s", s);
    printf("\n%c", s[2]);
    return 0;
}

#include <stdio.h>

int main(){
    int myarr[10],val;
    for(int i=0;i<10;i++){
        scanf("%d ",&myarr[i]);
    }
    bool status=false;
    for (int i= 0;i<10;i++){
        for(int j=0;j<(10-1-i);j++){
            if(myarr[j]>myarr[j+1]){
                int holder=myarr[j+1];
                myarr[j+1]=myarr[j];
                myarr[j]=holder;
                status=true;
            }
        }
    }
    if(status){
        printf("Arranged elements are: ");
        for(int i=0;i<10;i++){
            printf("%d ",myarr[i]);
        }
    }else{
        printf("All elements are the same");
    }
    
    return 0;
}

#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];
    int rowZero[r], colZero[c];

    // Initialize helper arrays
    for(int i = 0; i < r; i++)
        rowZero[i] = 0;

    for(int j = 0; j < c; j++)
        colZero[j] = 0;

    // Read matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == 0) {
                rowZero[i] = 1;
                colZero[j] = 1;
            }
        }
    }

    // Modify matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(rowZero[i] || colZero[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    // Output matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}



#include <stdio.h>

/* Helper function: calculates sum of a square sub-matrix */
int comb(int row, int col, int size, int N, int arr[N][N]) {
    int sum = 0;

    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            sum += arr[i][j];
        }
    }

    return sum;
}

int main() {
    int N;
    scanf("%d", &N);

    int myarr[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &myarr[i][j]);
        }
    }

    int S;
    scanf("%d", &S);

    int count = 0;

    /* size = square dimension */
    for (int size = 1; size <= N; size++) {

        /* top-left corner of square */
        for (int i = 0; i <= N - size; i++) {
            for (int j = 0; j <= N - size; j++) {

                int sum = comb(i, j, size, N, myarr);

                if (sum == S) {
                    count++;
                }
            }
        }
    }

    printf("%d", count);
    return 0;
}



#include <stdio.h>

int neon(int n) {
    int square = n * n;
    int sum = 0;

    while (square > 0) {
        sum += square % 10;
        square /= 10;
    }

    return sum == n;
}

int main() {
    int N;
    scanf("%d", &N);

    if (neon(N)) {
        printf("%d is a neon number", N);
    } else {
        printf("%d is not a neon number", N);
    }

    return 0;
}


#include <stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    int sum=1;
    int prev=0;
    for(int i = 0;i<num;i++){
        int next=sum+prev;
        prev=sum;
        sum=next;
    }
    
    int ans=prev%10;
    printf("%d ",ans);


    return 0;
}



#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];
    int rowZero[r], colZero[c];

    // Initialize helper arrays
    for(int i = 0; i < r; i++)
        rowZero[i] = 0;

    for(int j = 0; j < c; j++)
        colZero[j] = 0;

    // Read matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == 0) {
                rowZero[i] = 1;
                colZero[j] = 1;
            }
        }
    }

    // Modify matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(rowZero[i] || colZero[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    // Output matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}


#include<stdio.h>

int main()
{
    int arr[3][4] = {
                        {11,22,33,44},
                        {55,66,77,88},
                        {11,66,77,44}
                    };

    int i, j;

    for(i = 0; i < 3; i++)
    {
        printf("Address of %d th array %u \n",i , *(arr + i));
        for(j = 0; j < 4; j++)
        {
             printf("arr[%d][%d]=%d\n", i, j, *( *(arr + i) + j) );
        }
        printf("\n\n");
    }

    // signal to operating system program ran fine
    return 0;
}


#include <stdio.h>
#include <stdbool.h>
bool DuckNumber(int num){
    
    if(num==0) {
        printf("0");
        return false;
    }
    
    
    if(num%10==0) return true;
    
    return DuckNumber(num/10);
    
} 

int main(){
    
    int num;
    scanf("%d",&num);
    if(DuckNumber(num)){
        printf("%d is a duck number.",num);
    }else{
        printf("%d is not a duck number.",num);
    }
    
    
    return 0;
}


#include <stdio.h>

int isAutomorphic(int n) {
    int square = n * n;
    int temp = n;

    while (temp > 0) {
        if (square % 10 != temp % 10)
            return 0;
        square /= 10;
        temp /= 10;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    if (isAutomorphic(n))
        printf("%d is an automorphic.", n);
    else
        printf("%d is NOT an automorphic.", n);

    return 0;
}


#include <stdio.h>
#include <string.h>

int isPalindrom(char s[],int left ,int right) {
    while(left < right){
        if (s[left] != s[right])
            return 0;
        left++;
        right--;
    }
    return 1;
}

int main() {
    char s[51];
    scanf("%s",s);
    
    int n = strlen(s);
    int maxLen = 1;
    
    for(int i =0; i<n;i++){
        for(int j=i;j<n;j++){
            if(isPalindrom(s,i,j)){
                int len =j-i+1;
                if(len > maxLen)
                    maxLen = len;
            }
        }
    }
    
    
    printf("%d",maxLen);
    return 0;
    
}


#include <stdio.h>
#include <string.h>

int main() {
    int num;
    scanf("%d", &num);

    char arr[10][101];

    for (int i = 0; i < num; i++) {
        scanf("%100s", arr[i]);
    }

    char check[101];
    scanf("%100s", check);

    for (int i = 0; i < num; i++) {
        if (strcmp(arr[i], check) == 0) {
            printf("Found in row: %d", i + 1);
            return 0;
        }
    }

    printf("Not found");
    return 0;
}


#include <stdio.h>
#include <ctype.h>

int main() {
    char s[150];
    fgets(s, 150, stdin);

    int vowels = 0, consonants = 0, digits = 0, special = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (isdigit(ch)) {
            digits++;
        } else if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                vowels++;
            else
                consonants++;
        } else if (ch != '\n') {
            special++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Special Characters: %d\n", special);

    return 0;
}



#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    scanf(" %c", &ch);

    if (isalpha(ch)) {
        ch = tolower(ch);
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            printf("Vowel");
        else
            printf("Consonant");
    } else {
        printf("Not an alphabet");
    }

    return 0;
}



#include <stdio.h>

int main() {
    char arr[10];

    for (int i = 0; i < 10; i++) {
        scanf(" %c", &arr[i]);
    }

    printf("%c", arr[0]);
    return 0;
}



#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char result[1000] = "";

    for (int i = 0; i < n; i++) {
        char temp[101];
        scanf("%100s", temp);
        strcat(result, temp);
        if (i < n - 1)
            strcat(result, " ");
    }

    printf("%s", result);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char arr[10][101];
    for (int i = 0; i < n; i++) {
        scanf("%100s", arr[i]);
    }

    char search[101];
    scanf("%100s", search);

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], search) == 0) {
            printf("Found in row: %d", i + 1);
            return 0;
        }
    }

    printf("Not found");
    return 0;
}


#include <stdio.h>
#include <string.h>

int isPalindrome(char s[], int l, int r) {
    while (l < r) {
        if (s[l] != s[r])
            return 0;
        l++;
        r--;
    }
    return 1;
}

int main() {
    char s[51];
    scanf("%s", s);

    int n = strlen(s);
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                int len = j - i + 1;
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    printf("%d", maxLen);
    return 0;
}
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int i;

    printf("Reversed array:\n");
    for (i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);

    return 0;
}
#include <stdio.h>
#include <ctype.h>

int main() {
    char s[150];
    fgets(s, 150, stdin);

    int vowels = 0, consonants = 0, digits = 0, special = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (isdigit(ch)) {
            digits++;
        } else if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                vowels++;
            else
                consonants++;
        } else if (ch != '\n') {
            special++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Special Characters: %d\n", special);

    return 0;
}
#include <stdio.h>

int main() {
    int arr[10][10], r, c, i, j, k, temp;

    scanf("%d %d", &r, &c);

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c - 1; j++) {
            for (k = 0; k < c - 1 - j; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

int main() {
    int arr[3][3] = {
        {3, 1, 2},
        {9, 5, 4},
        {8, 7, 6}
    };
    int i, j, temp;
    int total = 9;

    for (i = 0; i < total - 1; i++) {
        for (j = i + 1; j < total; j++) {
            int r1 = i / 3, c1 = i % 3;
            int r2 = j / 3, c2 = j % 3;

            if (arr[r1][c1] > arr[r2][c2]) {
                temp = arr[r1][c1];
                arr[r1][c1] = arr[r2][c2];
                arr[r2][c2] = temp;
            }
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

int main() {
    int arr[3][3] = {
        {3, 1, 2},
        {9, 5, 4},
        {8, 7, 6}
    };
    int i, j, k, temp;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2 - j; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}



#include <stdio.h>
#include <string.h>
int main(){
    int N;
    scanf("%d",&N);
    
    if (N <= 0){
        printf("Invalid");
        return 0;
    }
    
    int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    
    char *symbols[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    
    for (int i = 0;i<13;i++){
        while(N>=values[i]){
            printf("%s",symbols[i]);
            N -= values[i];
        }
    }
    
    
    return 0;
}




#include <iostream>
using namespace std;

class Box {
    public: // Initialize static member of class Box
        static int objectCount; // Constructor definition //NOTE : Here even if we create mutiple object that all have share same  data as we increment from time to time 
        void data(double l , double b, double h) {
        length = l; breadth = b; height = h; // Increase every time object is created
        objectCount++;
        }
    private:
        double length, breadth, height;
}; 

// Initialize static member of class Box

int Box::objectCount = 0; // we have initailze outside only we can not set default  value i nsidde .becase we are creeating new object then ever time we are or setting it's value to 0
int main() {
    Box Box1;
    Box1.data(3.3, 1.2, 1.5); // Declare box1
    Box Box2;
    Box2.data(8.5, 6.0, 2.0); // Declare box2 // Print total number of objects.
    cout << "Total objects: " << Box::objectCount << endl;
    cout << Box1.objectCount<<endl;
    return 0;
}




#include <iostream>
using namespace std;

class Box { 
    private: 
        static int length; 
        static int breadth; 
        static int height; 
        int my = 2;
        //static int my ;
    public:
        static void print(){ //a function that belongs to the class rather than any specific object of the class.so it can called with class like classname::function name
            cout << "The value of the length is: " << length << endl;  //it has accese to only static data memebers and function .
            cout << "The value of the breadth is: " << breadth << endl; 
            cout << "The value of the height is: " << height << endl; 
            //cout <<my<<endl; // this will cause a problem .say we removed the comment from that static int my add gave it value of 2 by Box::my =2 then commented int my = 2  then we crun this work ..so from this we understand it can access only ststsic data members 
        }

        static int sum();
}; 
int Box :: length = 10; 
int Box :: breadth = 20; 
int Box :: height = 30;
//int Box::my = 2;

int Box::sum(){
    cout << height + breadth + length <<endl;///we can declare inside the class also out side jsut by Box:: function name () {.................}
    return 0;
}

int main(){

    Box b; 
    cout << "Static member function is called through Object name: \n" << endl; 
    b.print(); //static memeber function can also be called using normal objects.

    cout << "\nStatic member function is called through Class name: \n" << endl; 
    Box::print();
    
    Box::sum();

    return 0; 
}




#include <iostream>
using namespace std;
class Test {
    int x, y;
    public:

    /*

    for method chaining
    
    Syntax:
        ClassName& functionName() {
            return *this;
        }
    
    */

        Test(int x = 0, int y = 0) {
            this->x = x;// this-> used for name confite as it have class memeber and valriable can have smae name . this-> refere to the current calling object this a hidden pointer
            this->y = y;
        }
        Test& setX(int a) {
            x = a;
            return *this;//here we deference this pointer because this it pointing a box that is holds  the class ka object the if return  just return this we send the ptr address but we tabve to send the onbject address so that we can work on it for chaining .so return type is class name& here & mean adrees is return type  .so by deference we send this ka inside the adrres of  the obj cueenting wokring   
        }
        Test& setY(int b) {
            y = b;
            return *this;
        }

        void print() {
            cout << "x = " << x << " y = " << y << endl;
        };
};


main() {
    Test obj;
    obj.setX(10).setY(20).print();//as here we want the obje ct the location then wee call the fanction using . dot operarted 
}




#include <iostream>
using namespace std;

class Test {
    public:
        int a;
        Test(){
            a = 10;
            std::cout << "Constructor is executed\n"<<this<<endl;
        }
        ~Test() { 
            std::cout << "Destructor is executed\n "<<this<<endl; 
        }
};

int main(){


    Test a;

    //static Test b;

    Test b; // as we can see the output in this form that the object called lattest is destriod first and then the oldest destrocted is called after that .here b dedstructor is called first then a .as a is construdec forst and b n

    return 0;
}


# ----------------------------------
Generic Programming
# <iostream>
using namespace std; 

template <class myType> 
myType GetMax (myType a, myType b){ 
    return (a>b?a:b); 
}

int main () {
    int x,y; 
    GetMax <int> (x,y);
}




#include <iostream> 
using namespace std; 
template <class T, class U> 
bool are_equal (T a, U b) { 
return (a==b); 
} 
int main () { 
if (are_equal(10,10.0)) 
cout << "x and y are equal\n"; 
else 
cout << "x and y are not equal\n"; 
return 0; 
}


// template arguments 
#include <iostream>
using namespace std;
template <class T, int N>
T fixed_multiply (T val, int N) {
return val * N;
}
int main() {
cout << fixed_multiply<int,2>(10) << '\n';
cout << fixed_multiply<float,3>(10.5) << '\n';
}

