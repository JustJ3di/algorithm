#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main()
{
    
    int n;
    while(cin>>n)
    {
        vector <int> v;
        for (size_t i = 0; i < n; i++)
        {
            int p;
            cin>>p;
            v.push_back(p);
        }
        int s;
        cin>>s;
        sort(v.begin(), v.end());
        

        int i = v.front();
        
        int j = v.back();
        
        for (size_t b = 0; b < v.size(); b += 1)
        {
            int b1 = v[b];
            int b2 = s - b1;
            if (b1 > b2)
                break;
            
            if (binary_search(v.begin() + b + 1, v.end(), b2))
            {
                if (b2 - b1 < j - i)
                {
                    i = b1;
                    j = b2;
                }
            }
        }
        

        cout << "Peter should buy books whose prices are "
             << i
             << " and "
             << j
             << "."
             << endl 
             << endl;
    }
    return 0;
}
