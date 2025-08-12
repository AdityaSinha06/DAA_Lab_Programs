#include<bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

void bubble_Sort(vector<int>& arr) {
    int n = arr.size();

    for(int i=0; i<n-1; i++) {
        bool isSorted = true;
        for(int j=0; j<n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                isSorted = false;
                swap(arr[j] , arr[j+1]);
            }
        }

        if(isSorted) break;
    }

    return ;
}

int main() {
    int n; cout << "Input the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    for(auto &ele : arr) {
        ele = rand()%100;
    }

    //average-case:
    auto start = high_resolution_clock::now();
    bubble_Sort(arr);
    auto end = high_resolution_clock::now();

    auto duration_avg = duration_cast<milliseconds>(end - start);
    cout << "Average Case : " << duration_avg.count() << " milliSeconds\n";

    //now: arr is sorted :> best-Case
    start = high_resolution_clock::now();
    bubble_Sort(arr);
    end = high_resolution_clock::now();

    auto duration_best = duration_cast<milliseconds>(end - start);

    cout << "Best-Case Time Taken: " << duration_best.count() << " milliSeconds\n";
    


    //now: arr is reversed :> worst case
    reverse(arr.begin() , arr.end());

    start = high_resolution_clock::now();
    bubble_Sort(arr);
    end = high_resolution_clock::now();

    auto duration_worst = duration_cast<milliseconds>(end - start);

    cout << "Worst-Case Time Taken: " << duration_worst.count() << " milliSeconds\n";


    return 0;
}