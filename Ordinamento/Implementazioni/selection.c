#include<stdio.h>

void swap(int *vect, unsigned int current, unsigned int min_index){

    int temp = vect[current];
    vect[current] = vect[min_index];
    vect[min_index] = temp;

}

/*
invariante il sub array formato dal primo ciclo poichè all inizio è un elemento ed è sicuramente ordinato.
alla prima iterazione il secondo ciclo ordina gli elementi ancora quindi risulta essere di nuovo ordinato.
Così proseguendo anche alla terza operazione ed alla quarta ecc.


perchè non farlo partire da i +1, semplice perchè il primo confronto con se stesso è alquanto inutile :)  !!!

La complessità è n^2 IN OGNI CASO PEGGIORE MEDIO E MIGLIORE poichè sempre si cerca il confronto tra l'elemento di start index ed il sub vector che fa partire ad ogni iterazione di cliclo anche se il vettore è ordinato

*/

int main()
{
    int dim = 6;  //c1
    int vect[] = {2,3,2,1,22,5}; //c2


    for (size_t i = 0; i < dim; i++)//cn
    {
        int min = i;
        for (size_t j = i+1; j < dim; j++)
        {
            if(vect[j]<vect[i]){
                swap(vect,i,j);
                min = j;
            }
        }
        
    }
    
    for (size_t i = 0; i < dim; i++)
    {
        printf("%d\t",vect[i]);
    }
    
    return 0;
}
