#include<bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

void insertion_Sort(vector<int>& arr) {
    int n = arr.size();

    for(int i=1; i<n; i++) {
        int j = i;
        while(j>0 && arr[j] < arr[j-1]) {
            swap(arr[j] , arr[j-1]);
            --j;
        }
    }

    return;
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
    insertion_Sort(arr);
    auto end = high_resolution_clock::now();

    auto duration_avg = duration_cast<milliseconds>(end - start);
    cout << "Average Case : " << duration_avg.count() << " milliSeconds\n";

    //now: arr is sorted :> best-Case
    start = high_resolution_clock::now();
    insertion_Sort(arr);
    end = high_resolution_clock::now();

    auto duration_best = duration_cast<milliseconds>(end - start);

    cout << "Best-Case Time Taken: " << duration_best.count() << " milliSeconds\n";
    


    //now: arr is reversed :> worst case
    reverse(arr.begin() , arr.end());

    start = high_resolution_clock::now();
    insertion_Sort(arr);
    end = high_resolution_clock::now();

    auto duration_worst = duration_cast<milliseconds>(end - start);

    cout << "Worst-Case Time Taken: " << duration_worst.count() << " milliSeconds\n";


    return 0;
}