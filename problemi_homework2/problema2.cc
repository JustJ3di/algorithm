#include <bits/stdc++.h>

using namespace std;

void sub_set_fun(vector <int> set, vector <int>sub_set, int start, int *count)
{
   
    if(sub_set.size() ==1 || sub_set.size()==2)
    {
        *count += 1;
        for (auto i : sub_set)
        {
            cout<<i<<" ";
        }cout<<endl;
        
    }

    for (size_t i = start; i < set.size(); i++)
    {
        sub_set.push_back(set[i]);
        sub_set_fun(set, sub_set, i+1, count);
        sub_set.pop_back();
    }
      
}

int main()
{
    
    vector <int> a = {1,2,3,4,5};

    vector <int >b;
    int count{0};
    sub_set_fun(a,b,0,&count);
    cout<<count<<endl;


    return 0;
}
