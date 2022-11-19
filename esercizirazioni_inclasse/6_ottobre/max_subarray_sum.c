#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(int argc, char const *argv[])
{
    
    int vect[] = {-1,2,-4,2,4,5,-1,-1,3,-6,5};

    int dim = sizeof(vect)/sizeof(vect[0]);
    int sum = 0;
    int sum_partial = 0;

    //complessità lineare

    for (size_t i = 0; i < dim; i++)
    {
        sum_partial += vect[i]; //sommo elementi in array e li metto in somma parziale
        sum =  (sum>sum_partial ? sum : sum_partial); //se la somma che stava in sum è più piccola della somma partiale sum = sum_partial, altrimenti resta invariata
        sum_partial = (sum_partial < 0 ? 0 : sum_partial); //se sum_partial è negativa mi fermo perchè non incide sulla domma totale    
    }

    
    printf("sum = %d\n", sum);


    //quadratica
    int somma_quadra = 0;
    int somma = 0;

    int somme[1000];
    for (size_t i = 0; i < 1000; i++)
    {
        somme[i] = 0;
    }
    

    int i_somma = 0;

    for (size_t i = 0; i < dim; i++)
    {
        

        int j = i;
        somma_quadra = 0;
        while (j < dim)
        {
            somma_quadra += vect[j];
            if(somma_quadra > 0){
                somme[i_somma] = somma_quadra;
                i_somma++;
            }
            j++;
            
        }

    }

    
    for (size_t i = 0; i < 1000; i++)
    {
        printf("somme = %d\n",somme[i]);
        if (somme[i] > somma)
        {
            somma = somme[i];
        }
        
    }
    


    printf("\ncomplessità n^2 sum %d\n", somma);


    return 0;
}
