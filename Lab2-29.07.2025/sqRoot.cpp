#include<bits/stdc++.h>
using namespace std;

int find_sqRoot(int n) {
    int lo = 0 , hi = n;

    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if(mid*mid == n) return mid;
        else if(mid*mid < n) lo = mid + 1;
        else hi = mid -1;
    }

    return -1;
}

int main() {
    int n; cout << "Input a positive integer: ";
    cin >> n;

    int sqRoot = find_sqRoot(n);
    if(sqRoot == -1) cout << "Not a perfect square";
    else cout << sqRoot;
    
    return 0;
}