#include <stdio.h>

typedef struct myvect{
    int ele;
    int previous_pos;
}Vect;

void swap(Vect *a, Vect *b)
{
    Vect tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(Vect arr[], int first, int last)
{
    
    int i = first-1;

    int pivot = arr[last].ele;

    for(int j = first ; j < last ; j++)
    {
        if(pivot > arr[j].ele){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[last]);
    
    return i + 1;

}
//nlog(n)
void quickSort(Vect arr[], int first, int last)
{

    if(first < last)
    {
        int p = partition(arr, first, last);
        quickSort(arr, first, p - 1);
        quickSort(arr, p + 1, last);
    }
    
}
//n
void array_cp(int arr1[], Vect b[] , int dim)
{
    for (size_t i = 0; i < dim; i++)
    {

        b[i].ele = arr1[i];
        b[i].previous_pos = i;

    }
    
}

//nlogn
void build_count(int a[], Vect b[] ,int c[] ,int dim)
{
    int count_equal = 0;
    int all_equal = 0; 
    int i = dim-1;

    
    while(i>=0)
    {

        int index_in_order_array = b[i].previous_pos;
        
        printf("indice %d = elementi minori %d\n",i,index_in_order_array);

        if(i<dim-2 && b[i].ele == b[i+1].ele)
        {
            count_equal++;

        }else{
            count_equal = 0;
        }
        c[b[i].previous_pos] = i+1 +count_equal ;
 
        i--;
    }
    

}

int main(int argc, char const *argv[])
{

    int dim = 9;
    int a[] = {1,2,2,3,0,3,4,3,3};
    Vect b[dim];

    
    int count[9];
    for (size_t i = 0; i < 9; i++)
    {
        count[i] = 0;
    }
    

    array_cp(a ,b, dim); //n

    quickSort(b, 0, dim - 1); //nlogn

    build_count(a , b, count, dim); //nlogn
    
    
    for (size_t i = 0; i < 9; i++)
    {
        printf("%d\n",count[i]);
    }
    
    
    return 0;
}
