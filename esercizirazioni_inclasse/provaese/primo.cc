#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    
    int T = 0;
    cin>>T;

    while(T--)
    {
        int r = 0;
        cin>>r;
        int n = 0;
        int tot = 0;
        vector <int> parent_n;
        while(r--)
        {   
            int s;
            cin>>s;
            parent_n.push_back(s);

        }
        
        sort(parent_n.begin(),parent_n.end());

        int  med = parent_n[parent_n.size()/2];    
        
        int sommma_distanze = 0;
        
        for (size_t i = 0; i < parent_n.size(); i++)
        {
            sommma_distanze += abs(parent_n[i]-med);   
        }

        cout<<sommma_distanze<<endl;
        

    }


    return 0;
}
