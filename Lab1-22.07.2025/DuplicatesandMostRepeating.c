#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
//Count the duplicates and the most Repeating element in the array
//1. ways : counting the frequencies of each element :> that would require me using additional data structures : hashmaps
//:> but in c , I don't know how to use hash maps :> do this!!
//2. now if I use arrays and use indices as hashing :> the limit is I would be able to store the frequencies of negatives
//3. A user-defined data-type

typedef struct {
    int num;
    int freq;
}freqCount;

//function to use hash-maps using arrays using user-defined data-types" :> if a key is present , increment its frequency else add it to the array
int find_or_insert(freqCount *freqArr, int *size, int num) {
    //here , we are returning the index of the element after incrementing its frequency
    for (int i = 0; i < *size; i++) {
        if (freqArr[i].num == num) {
            freqArr[i].freq++;
            return i;
        }
    }

    // Not found, insert new
    freqArr[*size].num = num;
    freqArr[*size].freq = 1;
    (*size)++;
    return *size - 1;
}

int main() {
    int n; printf("Input the number of elements: ");
    scanf("%d" , &n);

    int arr[n];
    printf("Input the elements into the array: \n");
    for(int i=0; i<n; i++) {
        printf("Input element-%d: " , i);
        scanf("%d" , &arr[i]);
    }

    freqCount *freqArr = (freqCount *)malloc(n * sizeof(freqCount));
    int freqSize = 0;

    for (int i = 0; i < n; i++) {
        find_or_insert(freqArr, &freqSize, arr[i]);
    }

    int duplicateCount = 0;
    int mostRepeating = arr[0];
    int maxFreq = 1;

    for (int i = 0; i < freqSize; i++) {
        if (freqArr[i].freq > 1) //counts total duplicates
            duplicateCount++;

        if (freqArr[i].freq > maxFreq) { // counts the element with maxFreq
            maxFreq = freqArr[i].freq;
            mostRepeating = freqArr[i].num;
        }
    }

    printf("Total duplicate elements: %d\n", duplicateCount);
    printf("Most repeating element: %d (appears %d times)\n", mostRepeating, maxFreq);

    free(freqArr);
    return 0;
}

  

