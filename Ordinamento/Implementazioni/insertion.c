#include<stdio.h>

int main()
{

    int vect[] = {22,3,1,433,2};

    for (size_t i = 1; i < 5; i++)
    {
        size_t j = i-1;
        int key = vect[i];
        while (key < vect[j] && j >= 0)
        {
            vect[j+1] = vect[j];
            j--;
        }
        vect[j+1] = key; 
    }
    

    for (size_t i = 0; i < 5; i++)
    {
        printf("%d\t", vect[i]);
    }
    
    return 0;
}
