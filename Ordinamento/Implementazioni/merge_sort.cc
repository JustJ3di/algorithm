#include <bits/stdc++.h>

using namespace std;

/*questo merge sort conta anche il numero degli scambi tra elementi adiacenti effetuati*/

void merge(int *A, int start, int center,int end, int *num_op){
    

    int n1 = center-start+1;
    int n2 = end-center;
    int op_count = 0;
    int *L = new int[n1+1];
    int *R = new int[n2+1];
    //int *L = malloc(sizeof(int)*(n1+1));
    //int *R =malloc(sizeof(int)*(n2+1));

    for(int i = 0; i < n1; i++)
        L[i] = A[i + start];
    
    L[n1] = INT_MAX;
    
    for(int i = 0; i < n2; i++)
        R[i] = A[i + center+1];

    R[n2] = INT_MAX;

    int l_index = 0;
    int r_index = 0;
    for(int i=start;i <= end; i++){
        
        if(L[l_index] <= R[r_index]){
            A[i] = L[l_index];
            l_index++;
        }
        else{
            A[i] = R[r_index];
            r_index++;
            if(L[l_index] != INT_MAX)
                op_count += n1-l_index;
                
        }
        
    }
    

    if(num_op)
        *num_op += op_count;

    delete L;
    delete R;    
}

void merge_sort(int *A, int start, int end, int *num_op){
    
    if(start < end){
        
        int center = (start + end)/2;
        merge_sort(A,start,center, num_op);
        merge_sort(A, center+1,end, num_op);
        merge(A,start,center,end, num_op);
        
    }

}


int main(int argc, char const *argv[])
{
    
    int a[] = {1,3,2,11,0,-3};

    int count  = 0;
    merge_sort(a,0,5, &count);
    for (auto i : a)
    {
        cout<<i<<endl;
    }
    
    cout<<"numero operazioni "<<count<<endl;



    return 0;
}
