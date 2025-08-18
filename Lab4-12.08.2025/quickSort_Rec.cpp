#include<bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr , int l , int r) {
    int randomPivot = l + rand() % (r-l+1); //random pivot
    int pivotEle = arr[randomPivot];

    int smallerCnt = 0;
    for(int i=l; i<=r; i++) {
        if(i == randomPivot) continue;
        if(arr[i] <= pivotEle) {
            ++smallerCnt;
        }
    }

    int correctIdx = l + smallerCnt;
    swap(arr[correctIdx] , arr[randomPivot]);

    int i=l , j=r;
    while(i < correctIdx && j > correctIdx) {
        if(arr[i] <= pivotEle) ++i;
        else if(arr[j] > pivotEle) --j;
        else {
            swap(arr[i] , arr[j]);
            ++i; --j;
        }
    }

    return correctIdx;
}

void quickSort(vector<int>& arr , int l , int r) {
    if(l >= r) return;
    int pivotIdx = partition(arr , l , r);
    quickSort(arr , l , pivotIdx-1);
    quickSort(arr , pivotIdx+1 , r);
}

int main() {
    int n; cout << "Input the number of Elements: ";
    cin >> n;

    vector<int> avgCase(n) , bestCase(n) , worstCase(n);
    
    for(int i=0; i<n; i++) {
        avgCase[i] = rand() % 1000;
    }

    bestCase = avgCase;
    sort(bestCase.begin() , bestCase.end());

    worstCase = bestCase;
    reverse(worstCase.begin() , worstCase.end());

    //avg-Case
    auto start1 = high_resolution_clock::now();
    quickSort(avgCase , 0 , n-1);
    auto end1 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << "Average-Case Time Taken: " << duration1.count() << " microseconds\n";

    //best-Case
    auto start2 = high_resolution_clock::now();
    quickSort(bestCase , 0 , n-1);
    auto end2 = high_resolution_clock::now();

    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "Best-Case Time Taken: " << duration2.count() << " microseconds\n";

    //worst-Case
    auto start3 = high_resolution_clock::now();
    quickSort(worstCase , 0 , n-1);
    auto end3 = high_resolution_clock::now();

    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << "Worst-Case Time Taken: " << duration3.count() << " microseconds\n";

    return 0;
}
