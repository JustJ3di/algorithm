#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void merge(int arr[], int p, int q, int r,int *count) {

    int n1 = q - p + 1; //vettore 1
    int n2 = r - q; //vettore 2

    int *L = malloc(sizeof(int)*n1);
    int *M = malloc(sizeof(int)*n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i]; //faccio i vettori (primo)
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j]; //(secondo vettore)

    int i, j, k;
    i = 0;
    j = 0;
    k = p; //k è lo start da dove deve partire il vettore originale

    while (i < n1 && j < n2) //inizio a scorrere i due vettori
    {

        if (L[i] <= M[j]) // se il primo degli elementi in coda (che so essere sempre il più piccolo quando partono da 1 ecc ecc.. è se quello di sinistra è maggiore di quello di destra lo passo al bvettore origiale)
        {
            arr[k] = L[i]; //assegnazione al vettore originale
            i++;     //incremento solo il primo vettore 
        } 
        else 
        {
            arr[k] = M[j]; //altrimenti procedo con il secondo 
            j++;
            *count += q-k+j;
            /*printf("i = %d  \n",i );
            /*printf("j = %d  \n", j);
            /*printf("mid = %d  \n", q);
            */
        }

        k++;
    }
    
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
    free(L);
    free(M);
}



void merge_sort(int *vect, int s, int d,int *count)
{
    if(s<d)
    {
        int m = s + ((d - s)/2);
        merge_sort(vect,s,m,count);
        merge_sort(vect,m+1,d,count);
        assert(count != NULL);
        merge(vect, s, m, d, count);
    }
    

}

int main(int argc, char const *argv[])
{
    int vect[] = {9,1,0,5,4};
    int *count = malloc(4);
    *count = 0;
    merge_sort(vect , 0, sizeof(vect)/sizeof(vect[0]) - 1,count);


    for (size_t i = 0; i < 5; i++)
    {
        printf("%d\n",vect[i]);
    }

    printf("\n\n%d\n",*count);

    free(count);
    
    
    return 0;
}
