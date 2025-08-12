#include<bits/stdc++.h>
using namespace std;

int reversed_Num(int rev , int n) {
    if(n <= 0) return rev;

    rev *= 10;
    rev +=(n%10);
    n /= 10;

    reversed_Num(rev , n);
}

int main() {
    int n ; cout << "Input n: ";
    cin >> n;

    cout << reversed_Num(0 , n);


    return 0;
}