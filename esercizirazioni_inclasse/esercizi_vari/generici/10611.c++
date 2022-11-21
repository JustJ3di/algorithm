#include <bits/stdc++.h>


using namespace std;


int bsc(vector <int> arr,int x, int low, int high)
{   
    
        while(low<=high)
        {
            int mid = (low + high)/2;

            if (x == arr[mid])
                return mid;

            else if (x > arr[mid]) // x is on the right side
                low = mid + 1;

            else                  // x is on the left side
                high = mid - 1;
        }
}

int main(int argc, char const *argv[])
{
    //input
    int N;
    cin>>N;
    vector <int> h,q;
    while(N--)
    {
        int n ;
        cin>>n;
        h.push_back(n);

    }
    int Q;
    cin>>Q;

    while(Q--)
    {
        int q;
        cin>>q;

        for (size_t i = 0; i < len(h); i++)
        {
            
        }
        


    }
    
    

    return 0;
}
