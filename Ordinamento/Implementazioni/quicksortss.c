#include <stdio.h>

void swap(int *a, int *b){

    int tmp = *a;
    *a = *b;
    *b = tmp;

}


int partition(int *A, int p, int q){

    int pivot = A[q];
    
    int i = p-1;

    for (size_t j = p; j <= q-1; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            swap(&A[j], &A[i]);
        }
        
    }
    swap(&A[i+1], &A[q]);

    return i+1;
}


void quicksort(int *A,int p, int q){

    if(p<q){
        int div = partition(A, p, q);
        quicksort(A, p, div-1);
        quicksort(A , div+ 1, q );

    }

}
int main(int argc, char const *argv[])
{
    int A[] = {2,3,4,1,5,6,2,0};
    quicksort(A,0,7);

    for (size_t i = 0; i < 8; i++)
    {
       printf("%d \t",A[i]);
    }
    printf("\n");

    return 0;
}
