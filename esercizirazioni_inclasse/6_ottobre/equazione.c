#include <stdlib.h>
#include <stdio.h>

void binary_search(int *vect, int dim, int number, int start_index){


    int mediano = (start_index + dim) / 2 +1;

    if (number < vect[mediano])
    {
        dim = mediano;
        binary_search(vect, dim, number, start_index);
    }else if (number > vect[mediano]){

        start_index = mediano;
        dim = dim - mediano;

        binary_search(vect, dim , number, dim);
    }else{
        printf("trovato il valore %d è in posizione %d!\n", vect[mediano], mediano );
    }
    

}

#include <math.h>
static int count = 0;
void bisex(int p, int q, int r ,int s, int t, int u, double es, double ed){

    double es_value= p*exp(-es) +q*sin(es) +r*cos(es) + s*tan(es)+ t*es*es + u;
    printf("valore estremo sinistra %f\n", es_value);
    double ed_value= p*exp(-ed) +q*sin(ed) +r*cos(ed) + s*tan(ed)+ t*ed*ed + u;
    printf("valore estrema destra %f\n", ed_value);
    count++;
    if(count == 20)return;
    if((es_value < (double)0 && ed_value > (double)0) || (es_value > (double)0 && ed_value < (double)0)  )
    {
        double med = (es + ed) / 2;
        double med_value = p*exp(-med) +q*sin(med) +r*cos(med) + s*tan(med)+ t*med*med + u;
        if(med_value > -1  && med_value <1 ){
            printf("x = %f \n", med);
            if(med_value < 0.0 && ed_value > (double)0){

                bisex(p, q, r , s, t, u, med, ed);

            }else if (med_value  > 0.0 && ed_value < 0.0)
            {
                
                bisex(p, q, r , s, t, u, ed, med);

            }else if (med_value < 0.0 && es_value >0){
                bisex(p, q, r , s, t, u, med, es);

            }else if (med_value > 0.0 && es_value < 0.0){
                bisex(p, q, r , s, t, u, es, med);
            }else{
                printf("fine soluzione");
            }
        }

        
    }
    printf("Non ci sono soluzioni\n");
    return;

}


int main(int argc, char const *argv[])
{

    int array[] = {1,2,3,4,5,6,7,8,9,10};
    
    binary_search(array,9, 4, 0);

    bisex(0,0,0,0,-2,1,1,0);
    


    return 0;
}