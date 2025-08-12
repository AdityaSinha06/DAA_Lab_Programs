//let's enhance Mine merge_sort algo :: garchu
#include<bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

void mergeSortedArr(vector<int>& arr , int l , int m , int r , vector<int>& temp) {
    int i=l , j=m+1 , k=l;
    while(i<=m && j<=r) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            ++i;
        } else {
            temp[k] = arr[j];
            ++j;
        }

        ++k;
    }

    while(i <= m) {
        temp[k] = arr[i];
        ++k; ++i;
    }

    while(j <= r) {
        temp[k] = arr[j];
        ++k; ++j;
    }

    for(int idx=l; idx<=r; idx++) {
        arr[idx] = temp[idx];
    }
}

void mergeSort(vector<int>& arr , int l , int r , vector<int>& temp) {
    if(l >= r) return;

    int m = l + (r-l) / 2; 
    // l - m - m+1 - r
    mergeSort(arr , l , m , temp);
    mergeSort(arr , m+1 , r , temp);
    
    mergeSortedArr(arr , l , m , r , temp);
}

int main() {
    srand(time(0));
    int n ; cout << "Input the number of elements : ";
    cin >> n;

    vector<int> avgCase(n) , bestCase(n) , worstCase(n);

    for(int i=0; i<n; i++) {
        avgCase[i] = rand() % 10000;
    }

    //best-Case :> already-sorted
    bestCase = avgCase;
    sort(bestCase.begin() , bestCase.end());

    //worst-Case :> sorted > reverse
    worstCase = bestCase;
    reverse(worstCase.begin() , worstCase.end());

    vector<int> temp(n);

    //avg-Case
    auto start1 = high_resolution_clock::now();
    mergeSort(avgCase , 0 , n-1 , temp);
    auto end1 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << "Average-Case Time Taken: " << duration1.count() << " microseconds\n";

    //best-Case
    auto start2 = high_resolution_clock::now();
    mergeSort(bestCase , 0 , n-1 , temp);
    auto end2 = high_resolution_clock::now();

    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "Best-Case Time Taken: " << duration2.count() << " microseconds\n";

    //worst-Case
    auto start3 = high_resolution_clock::now();
    mergeSort(worstCase , 0 , n-1 , temp);
    auto end3 = high_resolution_clock::now();

    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << "Worst-Case Time Taken: " << duration3.count() << " microseconds\n";

    return 0;
}