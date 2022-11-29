#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int bsc(vector <int> array, int ele){

    int start = 0;
    int end = array.size()-1;
    while(start <= end)
    {
        int mid = (start + end) /2;
        if(array[mid] > ele)
        {
            start = mid+1;
        }
        else if(array[mid] < ele)
        {
            end = mid - 1;
        }
        else
            return mid;
    }
    
    return -1;

}

int main(int argc, char const *argv[])
{
   
    vector <int> a;
    for (size_t i = 0; i < 10; i++)
    {
        a.push_back(i+1);
    }

    cout<<bsc(a, 2);    

    return 0;
}
