#include <stdio.h>

void pointer (int *i, int j) {
    *i = *i * *i ;
    j = j * j ;
}

int main() {
    int i = 4, j = 2 ;
    pointer(&i, j) ;
    printf("%d %d", i, j);
    return 0;
}

#include <stdio.h>
int main() {
    int num[] = {24, 34, 12, 44, 56, 17};
    int i;
    for (i = 0 ; i <= 5 ; i++){
        printf("%d %d", *(i + num), i[num]);
    }
    return 0;
}

#include <stdio.h>
    
int main() {
    static int a[] = {0, 1, 2, 3, 4};
    int *p[] = {a, a + 1, a + 2, a + 3, a + 4};
    printf("%d", *(*p));
    return 0;
}

#include<stdio.h>
 
int main() {
    char *a = {'p', 'r', 'o', 'g'};
    printf("%s", a);
    return 0;
} 

#include<stdio.h>
int b = 5;

int* a() {
    return &b;
}

int main() { 
    *a() = 10;
    printf("%d", b);
    return 0;
}


#include <stdio.h>

int main() {
    int days;
    int *pdays = &days;
    int size1 = sizeof(days); 
    int size2 = sizeof(days + 1); 
    int size3 = sizeof(pdays);
    printf("%p %d %d %d", (void *)&pdays, size1, size2, size3);
    return 0;
}

#include <stdio.h>

int main() {
    double val = 9.7;
    double array[] = { 3.2, 4.3, 5.4 };
    double *pa[] = { &val, array + 1, NULL };
    printf("%.1lf", *pa[1]);
    return 0;
}

#include <stdio.h>
    
int main() {
    int a[10];
    *a = 7;
    *(a+1) = 12;
    int p = *(a+1) / *a;
    printf("%d", p);
    return 0;
}


#include<stdio.h>
int main(){
    printf("%c",*"abcde");
    return 0;
}


#include <stdio.h>
    
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    printf("%d", *(ptr++));
    return 0;
}

#include <stdio.h>
void modifyValue(const int *ptr) { 
    int newVal = 10;
    ptr = &newVal;
}
int main() {
    int num = 5;
    modifyValue(&num);
    printf("%d", num);
    return 0;
}


#include <stdio.h>
    
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = &arr[3];
    printf("%d", *(ptr - 2));
    return 0;
}

#include <stdio.h>
    
int main() {
    int x = 10;
    int *ptr1 = &x;
    int *ptr2 = ptr1;
    (*ptr2)++;
    printf("%d %d", *ptr1, *ptr2);
    return 0;
}


#include <stdio.h>
    
int main() {
    int a[] = {1,2,3,4,5};
    int *p;
    p = a;
    ++*p;
    printf("%d ", *p);
    p += 2;
    printf("%d ", *p);
    return 0;
}

#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr + 4;
    printf("%d", ptr[-1]);
    return 0;
}

#include <stdio.h>

void change(int *ptr) {
    ptr = NULL;
}

int main() {
    int a = 7;
    int *ptr = &a;
    change(ptr);
    if (ptr == NULL)
        printf("NULL ");
    else
        printf("Not NULL ");
    return 0;
}

#include <stdio.h>

void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int x = 5, y = 10;
    int *px = &x, *py = &y;
    swap(px, py);
    printf("%d %d", x, y);
    return 0;
}

#include <stdio.h>
void update(int *a, int *b) {
    int temp = *a;
    *a = *a + *b;
    *b = temp - *b;
}
int main() {
    int x = 7, y = 3;
    update(&x, &y);
    printf("x: %d, y: %d\n", x, y);
    return 0;
}

#include <stdio.h>

void modify(int *x) {
    *x = x + 10;
}

int main() {
    int num = 5;
    modify(&num);
    printf("%d", num);
    return 0;
}

#include <stdio.h>
void modifyRefValue(int *ptr) {
    int newVal = 50;
    ptr = &newVal;
}
int main() {
    int value = 30;
    int *ptr = &value;
    modifyRefValue(ptr);
    printf("%d\n", *ptr);
    return 0;
}

#include <stdio.h>

int main(){
    int m,n;
    int *a,*b;
    scanf("%d %d",&m,&n);
    a=&m;
    b=&n;
    printf("%d %d",*a,*b);

    return 0;
}



void findMaxMinDigits(int n, int *ptr_max, int *ptr_min){
    int max=0;
    int min=9;
    
    int sum=0;
    while(n>0){
        sum=n%10;
        if(sum<min){
            min=sum;
        }
        if(sum>max){
            max=sum;
        }
        n /=10;
    };
    *ptr_max=max;
    *ptr_min=min;

    return;
}

void calculateSum(int *ptr_max, int *ptr_min, int *ptr_sum){
    int cal=(*ptr_max)+(*ptr_min);
    *ptr_sum=cal;
    return ;
}


#include <stdio.h>

int main(){
    
    int pop1,pop2,pop3;
    char name[50];
    scanf("%s %d",name,&pop1);
    scanf("%s %d",name,&pop2);
    scanf("%s %d",name,&pop3);
    
    int sum=(pop1+pop2+pop3);
    printf("%d",sum);
    float avg=sum/3;
    printf("%.2f",avg);
    
    
    return 0;
}