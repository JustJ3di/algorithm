#include <bits/stdc++.h>
#include <vector>

using namespace std;

int find_max_index(vector <int> &arr, int size){

    int max = 0;
    for (size_t i = 1; i < size-1; i++)
    {
        if(arr[i] > arr[i-1])
            max = i;
    }
    
    return max;
}

int pancake_sort(vector <int> & arr)
{

    
    int count = 0;
    for (size_t i = arr.size()-1; i >1 ; i--)
    {
        int max_index = find_max_index(arr, i);
        if(max_index != i-1)
        {
            reverse(arr.begin(), arr.begin()+max_index);
            reverse(arr.begin(), arr.begin() +i);
            count += 2;
        }
        
    }
    
    return count;
}

int main(int argc, char const *argv[])
{

    vector <int> arr;
    int n = 0;
    while(1)
    {

        cin>>n;
        arr.push_back(n);
        if (n == 0)
        {
            arr.pop_back();
            break;
        }
    }
    cout<<endl;
    cout<<find_max_index(arr, arr.size())<<endl;

    int count = pancake_sort(arr);
    cout<<"reverse count = "<<count<<endl;

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}
