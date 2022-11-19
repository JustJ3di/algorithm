#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    
    int temp = *a;
    *a = *b;
    *b = temp;
    
}

void swap_order_recursive(int *vect, unsigned int dim, int *count,int i, int j){

    if(vect[i] > vect[j+1])
    {
        swap(vect[i], vect[j+1]);
        *count++;
    }

    if (i==dim-2 || j == dim-i-1)
    {
        return;
    }else
        swap_order_recursive(vect, dim, *count,i++,j++);
    



}

void swap_order(int *vect, unsigned int dim, int *count)
{
    int i, j;
    for (i = 0; i < dim - 1; i++)
    {

        for (j = 0; j < dim - i - 1; j++)
        {
            if (vect[j] > vect[j + 1])
            {
                swap(&vect[j], &vect[j + 1]);
                *count+=1;
            }
        }
    }
}

int main(void) {
	
	int vect[] = {9,1,0,5,4};
    int *count = malloc(sizeof(int));
    *count = 0;
	swap_order(vect, 5, count);

    for (int i = 0; i < 5; i++)
    {
        printf("vect[%d] = %d\n",i,vect[i]);
    }

    printf("%d\n",*count);
    

    printf("ciao mondo\n");
	
	return 0;
}

