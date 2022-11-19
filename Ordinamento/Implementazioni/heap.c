#include <stdio.h>

#define DIM 10

int get_parent(int *heap, int index){

    if (index >= 0 || index < DIM)
        return heap[(int)index/2];
    return -1;


}

int get_left_child(int *heap, int index){

    if (index >= 0 || index < DIM || index*2 +1 < DIM)
        return index*2 +1;
    return -1;
    

}

int get_right_child(int *heap, int index){

    if (index >= 0 || index < DIM || index*2 +1 < DIM)
        return index*2 + 2;
    return -1;
    

}


void max_heapfy(int *heap, int index){

    int l = 2*index+1;
    int r = 2*index+2;
    
    int max = index;
    printf("onde %d %d\n",max,l);
    if (l < DIM && heap[l] > heap[max])
        max = l;
    if (r < DIM && heap[r] > heap[max])
        max = r;
    if (max != index)
    {
        int tmp = heap[index];
        heap[index] = heap[max];
        heap[max] = tmp;
        max_heapfy(heap, max);

    }



}

void build_max(int *heap){

    for (size_t i = DIM/2 ; i > 0; i--)
    {
        max_heapfy(heap,i);
    }
    

}

int main()
{
    int heap[10] = {2,3,2,1,33,2,13,44,5,4};


   // max_heapfy(heap,5);

   build_max(heap);
    

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d\n",heap[i]);
    }
    

    return 0;
}
