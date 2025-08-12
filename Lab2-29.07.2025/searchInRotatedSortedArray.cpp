#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr , int target , int lo , int hi) {
    int n = arr.size();
    
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if(arr[mid] == target) {
            return mid;
        }

        if(arr[lo] <= arr[mid]) { //I'm in left sorted part
            // nums[lo] - nums[mid] :> one of my sorted part :> check whether tg is in this part or not
            if(arr[lo] <= target && target <= arr[mid]) {
                return search(arr , target , lo , mid-1);
            } else {
                return search(arr , target , mid + 1 , hi);
            }
        }   

        else { // I'm in right sorted part
            //nums[mid] - nums[hi] :> other sorted part :> check whether tg is in this part or not
            if(arr[mid] <= target && target <= arr[hi]) {
                return search(arr , target , mid + 1 , hi);
            } else {
                return search(arr , target , lo , mid - 1);
            }
        }   
    }

    return -1;
}

int main() {
    int n; cout << "Input n: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Input a rotated sorted array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int target; cout << "Input target Element: ";
    cin >> target;


    // 1 2 3 4 5 6 7 8 9 :> if we rotate by 3 eles :> 7 8 9 1 2 3 4 5 6
    //now , the array is divided into 2 sorted arrays.

    int Idx = search(arr , target , 0 , n-1);
    if(Idx == -1) {
        cout << "Element not present";
    } else {
        cout << "Element present at Idx: " << Idx;
    }

    return 0;
}   