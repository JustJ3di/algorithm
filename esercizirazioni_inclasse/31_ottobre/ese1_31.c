#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int main()
{

    int node = 1;
    //dammi d 
    int d= 3;
    //dammi k
    int k = 2;
    int count = d;
    int i = 0;
    int max = pow(2,d);
    for ( i = 0; i < d; i++)
    {   
        printf("ndoe = %d\n", node);

        if(k % 2 == 1) //se è dispari va a sinistra
        {
            node = node*2 ;
            
        }
        else
        {
            node = node*2 +1;
        }
        if (k > 1)
            k =ceil((k+1)/2);
        
    }
    printf("%d\n",node);
    return 0;
}
