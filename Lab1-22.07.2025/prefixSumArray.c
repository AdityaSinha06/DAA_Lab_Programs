#include<stdio.h>

int main() {
    int n; printf("Input the number of elements: ");
    scanf("%d" , &n);

    int arr[n];
    printf("Input the elements into the array: \n");
    for(int i=0; i<n; i++) {
        printf("Input element-%d: " , i);
        scanf("%d" , &arr[i]);
    }

    int prefixSumArray[n];
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        prefixSumArray[i] = sum;
    }
    
    for(int i=0; i<n; i++) {
        printf("%d " , prefixSumArray[i]);
    }

    return 0;
}