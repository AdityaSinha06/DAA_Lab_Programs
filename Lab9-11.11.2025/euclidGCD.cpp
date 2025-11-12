#include<bits/stdc++.h>
using namespace std;

int findGCD(int a , int b) {
    if(a == 0) return b;
    return findGCD(b%a , a);
}

int main() {
    int m = 3 , n = 17;
    cout << findGCD(m,n);

    return 0;
}