#include<stdio.h>
#include<limits.h>

int max(int a , int b) {
    if(a >= b) return a;
    return b;
}

int min(int a , int b) {
    if(a <= b) return a;
    return b;
}

int main() {
    int n; printf("Input the number of elements: ");
    scanf("%d" , &n);

    int arr[n];
    printf("Input the elements into the array: ");
    for(int i=0; i<n; i++) {
        scanf("%d" , &arr[i]);
    }

    int max1 = INT_MIN , min1 = INT_MAX , max2 = INT_MIN , min2 = INT_MAX;
    for(int i=0; i<n; i++) {
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if(arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
        
        if(arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if(arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    printf("Second Largest: %d\n" , max2);
    printf("Second Smallest: %d\n" , min2);

    return 0;
}