#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;



void backtrack( vector <int> & all,
                vector <int> & current_sub_set, 
                int start_sub,  
                int *end_sol)
{
    int sum = accumulate(current_sub_set.begin(), current_sub_set.end(), 0); 
    if(sum > *max_element(all.begin(),all.end()) &&  sum < *end_sol)
        {
            *end_sol = sum;
            //cout<<sum<<endl;

            
        }
        for (size_t i = start_sub; i < all.size(); i++)
        {
            current_sub_set.push_back(all[i]);
            backtrack(all, current_sub_set, i + 1, end_sol);
            current_sub_set.pop_back();
        }
        

}

int main(int argc, char const *argv[])
{

    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;
        vector <int> max_unit;
        for (size_t i = 0; i < n; i++)
        {
            int unit = 0;
            cin>>unit;
            max_unit.push_back(unit); 
        }

        vector <int> current_sub_set;
        int count = 10000;
        backtrack(max_unit, current_sub_set, 0, &count);
        cout<<count<<endl;

        
        
    }
    

    return 0;
}
