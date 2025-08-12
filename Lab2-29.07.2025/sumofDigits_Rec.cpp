#include<bits/stdc++.h>
using namespace std;

int nRecCalls = 0;
int calculateDigisum(int sum , int n) {
    ++nRecCalls;
    if(n <= 0) {
        return sum;
    }

    sum += n%10;
    n /= 10;
    calculateDigisum(sum , n);
}

int main() {
    int n ; cout << "Input the number: ";
    cin >> n;

    int digiSum = calculateDigisum(0 , abs(n));
    cout << digiSum ;
    cout << '\n' << "No of calls : " << nRecCalls ;

    return 0;
}