//recursively solving the question
#include<bits/stdc++.h>
using namespace std;

//fibonacci: 0 1 1 2 3 ..
void printFibonacci(int n) {
   if(n < 1) return ;

   else if(n == 1) {
    cout << 0 ;
    return;
   }

   else if(n == 2) {
    cout << 0 << ' ' << 1;
    return ;
   }

   else {
    int i = 3 , a = 0 , b = 1;
    cout << a << ' ' << b << ' ';
    while(i <= n) {
        cout <<a+b << ' ';
        int temp = a;
        a = b;
        b = b+temp;

        i++;
    }
   }

   return;
}

void printFibonacci_rec(int i , int a , int b , int n) {
    if(i > n) return;
    if(n < 1) return;
    if(n == 1) {
        cout << 0 ;
        return;
    }
    if(n == 2) {
        cout << 0 << ' ' << 1;
        return;
    }

    if(i == 1) {
        cout << 0 << ' ';
        printFibonacci_rec(i+1 , a , b , n);
    } else if(i == 2) {
        cout << 1 << ' ';
        printFibonacci_rec(i+1 , a , b , n);
    } else {
        cout << a+b << ' ';
        printFibonacci_rec(i+1 , b , a+b , n);
    }
    


}

int main() {
    int n; cout << "Input n: ";
    cin >> n;

    printFibonacci_rec(1 , 0 , 1 , n);


    return 0;
}