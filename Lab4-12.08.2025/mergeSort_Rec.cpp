#include<bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

void mergeSortedArr(vector<int>& arr , int l , int m , int r) {
    int n1 = m-l+1 , n2 = r-m;

    vector<int> left(n1) , right(n2);
    for(int i=0; i<n1; i++) left[i] = arr[l+i];
    for(int i=0; i<n2; i++) right[i] = arr[m+1+i];

    int i=0 , j=0 , k=l;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr , int l , int r) {
    if(l >= r) return;

    int m = l + (r-l) / 2; 
    // l - m - m+1 - r
    mergeSort(arr , l , m);
    mergeSort(arr , m+1 , r);
    
    mergeSortedArr(arr , l , m , r);
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

    //avg-Case
    auto start1 = high_resolution_clock::now();
    mergeSort(avgCase , 0 , n-1);
    auto end1 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << "Average-Case Time Taken: " << duration1.count() << " microseconds\n";

    //best-Case
    auto start2 = high_resolution_clock::now();
    mergeSort(bestCase , 0 , n-1);
    auto end2 = high_resolution_clock::now();

    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "Best-Case Time Taken: " << duration2.count() << " microseconds\n";

    //worst-Case
    auto start3 = high_resolution_clock::now();
    mergeSort(worstCase , 0 , n-1);
    auto end3 = high_resolution_clock::now();

    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << "Worst-Case Time Taken: " << duration3.count() << " microseconds\n";

    return 0;
}
