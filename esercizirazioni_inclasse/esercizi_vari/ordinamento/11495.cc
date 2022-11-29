#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
void merge(int arr[], int p, int q, int r,int *count) {

    int n1 = q - p + 1; //vettore 1
    int n2 = r - q; //vettore 2

    int *L = (int *)malloc(sizeof(int)*n1);
    int *M = (int *)malloc(sizeof(int)*n2);

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
    
    while(1){
        int N;
        scanf("%d",&N);
        if (N==0)
        {
            break;
        }
        vector <int> my;
        
        while(N--)
        {   
            int n;
            cin>>n;
            my.push_back(n);
        
        }
        
        int max[N];
        for (size_t i = 0; i < N; i++)
        {
            max[i] = my[i];
        }
        
        
        
        //merge_sort(max,0,my.size()-1,&count);
        int i, j, temp;
        int swaps = 0;
        for(i = 0; i < my.size()-1; ++i){

            for(j=0; j<my.size()-1-i; ++j){

                if(my[j] > my[j+1]){

                    temp = my[j+1];
                    my[j+1] = my[j];
                    my[j] = temp;
                    swaps++;
                }
            }
        }
        if(swaps %2 == 0)cout<<"Carlos\n";
        else cout<<"Marcello\n";
        //free(max);
        
    }
    return 0;
}
