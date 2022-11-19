#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

/*
    int lds[n];
    int i, j, max = 0;
 
    // Initialize LDS with 1 for all index
    // The minimum LDS starting with any
    // element is always 1
    for (i = 0; i < n; i++)
        lds[i] = 1;
 
    // Compute LDS from every index
    // in bottom up manner
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
 
    // Select the maximum
    // of all the LDS values
    for (i = 0; i < n; i++)
        if (max < lds[i])
            max = lds[i];

*/

int main()
{
    //intelligenze e  pesi
    int i,p;
    vector <pair <pair<int,int>,int> > elephants;
    int j = 1;
    while(cin>>p>>i)
    {
        elephants.push_back(make_pair(make_pair(p,i),j));
        j++;
    }   
            
    sort(elephants.begin(),elephants.end());

    for (size_t i = 0; i < elephants.size(); i++)
    {
        cout<<elephants[i].first.first<<" "<<elephants[i].first.second<<"\n";
    }
    

    vector <int>lds(elephants.size(), 1);
    vector <int> result;
    int max;
    max = 0;

    for (size_t i = 1; i < elephants.size(); i++)
    {
        for (size_t j = 0 ; j < i; j++)
        {
            if (elephants[i].first.second < elephants[j].first.second && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
                
        }
        
    }
    
    for (i = 0; i < elephants.size(); i++)
        if (max < lds[i])
            max = lds[i];

    cout<<max<<endl;
    

    return 0;
}


/*
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900


6008 1300 1
6000 2100 2
500 2000 3 
1000 4000 4
1100 3000 5
6000 2000 6
8000 1400 7
6000 1200 8 
2000 1900 9


3  500 2000
4 1000 4000 
1 100 3000 
5 1100 3000
9
8
6
2
1
7
*/