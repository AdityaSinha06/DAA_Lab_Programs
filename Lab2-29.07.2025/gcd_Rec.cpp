#include<bits/stdc++.h>
using namespace std;

int gcd_It(int a , int b) {
    int hcf = 1;
    for(int i = min(a , b); i>=1; i--) {
        if((a%i == 0 )&& (b%i == 0)) {
            return i;
        }
    }
}


int gcd_rec(int a , int b) {
    if(a == 0) {
        return b;
    }

    return gcd_rec(b%a , a);
}

int main() {
    int a , b; cout << "Input the numbers : ";
    cin >> a >> b;

    cout << "Using-Iterative: " << gcd_It(a , b) << '\n';
    cout << "Using_recursive: " << gcd_rec(a , b) << '\n';

    return 0;
}