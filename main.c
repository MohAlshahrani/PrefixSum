#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int * PrefixSum(int In[], int size);

int main() {

    double elt = omp_get_wtime();
    int arr[1000];
    int size = sizeof(arr)/sizeof(arr[0]);
    for( int i=0 ; i<size; i++){
        arr[i] = rand()%100;
    }

    int *ResultPtr;
    int *Result;

    Result = PrefixSum(arr, size);

    for (int i = 0; i < size; i++) {
        printf("result[%d] : %d\n", i, Result[i]);
    }
    elt = omp_get_wtime() - elt;
    return 0;

}
int * PrefixSum(int In[], int size) {
#pragma omp parallel while private(i) reduction(+:In,sum,out)
    int i = 0;
    int sum ;
    sum = *In;
    int Out[1000];
    Out[0] = sum;
    while (i<size){
        i++;
        sum = In[i]+sum;
        Out[i] = sum;
    }
    return  Out;
}
