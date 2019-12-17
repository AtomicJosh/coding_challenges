// g++ hacker_rank_insertion_sort_2.cpp -o hacker_rank_insertion_sort_2.out && ./hacker_rank_insertion_sort_2.out
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void printVector(int N, int arr[]) {
  for(int j=0; j<N; j++) {
    printf("%d", arr[j]);
    printf(" ");
  }
  printf("\n");
}

void insertionSort(int N, int arr[]) {
    int i,j;
    int value;
    for(i=1;i<N;i++)
    {
        value=arr[i];
        printf("Value: %d \n", value);

        j=i-1;
        while(j>=0 && value<arr[j])
        {
            printf("arr[j]: %d \n", arr[j]);
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=value;
        printVector(N, arr);
    }
    printVector(N, arr);
}

int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}


