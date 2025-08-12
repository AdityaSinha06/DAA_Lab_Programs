#include<stdio.h>

void exchange(int *a , int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 0 1 2 3 4 5 6 7 8  : p2 = 5
// 1 2 3 4 5 6 7 8 9
// 5 1 2 3 4
// 5 1 2 3 4 6 7 8 9
void rotate_right(int arr[] , int p2) {
    if (p2 <= 1) return;

    int last = arr[p2 - 1];
    for (int i = p2 - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
    
    

}

int main() {
    int n; printf("Input the number of elements: ");
    scanf("%d" , &n);

    int arr[n]; printf("Input the elements into the array: \n");
    for(int i=0; i<n; i++) {
        printf("Input element-%d: " , i);
        scanf("%d" , &arr[i]);
    }

    int p2; printf("Input the number of elements to rotate: ");
    scanf("%d" , &p2);
    
    rotate_right(arr , p2);
    for(int i=0; i<n; i++) {
        printf("%d  " , arr[i]);
    }

    return 0;
}