#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr , int si , int ei) {
    int pivotElement = arr[(si+ei)/2];
    int smallerCount = 0;
    for(int i=si; i<=ei; i++) {
        if(i == (si+ei)/2) continue;
        else if(arr[i] <= pivotElement) ++smallerCount;
    }

    int correctIdx = si + smallerCount;
    swap(arr[correctIdx] , arr[(si+ei)/2]);

    int l = si , r = ei;
    while(l <= r) {
        if(arr[l] <= pivotElement) ++l;
        else if(arr[r] > pivotElement) --r;
        else {
            swap(arr[l++] , arr[r--]);
        }
    }

    return correctIdx;
}

void quickSort(vector<int>& arr , int si , int ei) {
    if(si <= ei) {
        int pivotIdx = partition(arr , si , ei);
        quickSort(arr , si , pivotIdx-1);
        quickSort(arr , pivotIdx+1 , ei);
    }
}

int main() {
    vector<int> arr = {1,2,5,6,7,8,9,3,4};
    cout << "Before Sorting : \n";
    for(auto it : arr) {
        cout << it << ' ';
    }

    cout << '\n';

    int n = arr.size();
    quickSort(arr , 0 , n-1);
    cout << "After sorting : \n";
    for(auto it : arr) {
        cout << it << ' ';
    }
}