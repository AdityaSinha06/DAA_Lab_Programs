#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr , int target , int lo , int hi) {
    int n = arr.size();
    
    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;

        if(arr[mid] == target) {
            if(mid > 0 && arr[mid-1] == target) {
                return fun(arr , target , lo , mid - 1);
            } else {
                return mid;
            }
        } else if(arr[mid] < target) {
            return fun(arr , target , mid + 1 , hi);
        } else {
            return fun(arr , target , lo , mid - 1);
        }
    }

    return -1;
}

int fun_Last(vector<int>& arr , int target , int lo , int hi) {
    int n = arr.size();
    
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;

        if(arr[mid] == target) {
            if(mid < n-1 && arr[mid+1] == target) {
                return fun_Last(arr , target , mid + 1, hi);
            } else {
                return mid;
            }
        } else if(arr[mid] < target) {
            return fun_Last(arr , target , mid + 1, hi);
        } else {
            return fun_Last(arr , target , lo, mid - 1);
        }
    }

    return -1;
}

int main() {
    int n; cout << "Input the number of elements : ";
    cin >> n;

    cout << "Input the elements into the array in sorted order: ";
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Input the target Element: ";
    int target; cin >> target;

    int firstOccIdx = fun(arr , target , 0 , n-1);
    if(firstOccIdx == -1) {
        cout << "Element not Found";
        return 0;
    } else cout << "First Occ present at Idx : " << firstOccIdx << '\n';

    int lastOccIdx = fun_Last(arr , target , 0 , n-1);
    if(lastOccIdx == -1) {
        cout << "Element not Found";
        return 0;
    } else cout << "Last Occ present at Idx : " << lastOccIdx;

    return 0;
}