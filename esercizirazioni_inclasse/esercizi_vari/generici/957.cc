#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        vector <int> popes;
        int y;
        cin>>y;
        int l;
        cin>>l;
        while(l--)
        {   
            int p;
            cin>>p;
            popes.push_back(p);
        }

        int c_max = 0;
        int first = 0;
        int last = 0;
        for (size_t i = 0; i < popes.size(); i++)
            {   
                int c = 0;
                int j  = 0;
                for (j = i; j<popes.size() && popes[j] < popes[i] + y; j++)
                    c++;

                if(c_max < c)
                {
                    c_max = c;
                    first = popes[i];
                    last = popes[j-1];
                }

                

                
            }
        cout<<c_max<<" "<<first<<" "<<last<<endl;
        

    }
    
    return 0;
}
