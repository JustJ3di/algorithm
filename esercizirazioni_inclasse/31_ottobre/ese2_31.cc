#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{

    int N;
    int Q;
    
    vector <int> n;

    while(1)
    {
        
        cin>>N;
        n.resize(N + 1);
        for (size_t i = 0; i < N; i++)
        {
            int marble;
            cin>>marble;
            n[i] = marble;
        }

        if (Q== 0 && N==0)
        {
            return 0;
        }
        

        //counting sort
        vector <int> count;
        int max = *max_element(n.begin(),n.end());
        count.resize(max + 1);
        for (size_t i = 0; i < n.size(); i++)
        {
            count[n[i]] += 1;
        }
        for (size_t i = 1; i < max + 1; i++)
        {
            count[i] = count[i-1] + count[i];
        }
        vector <int> ordered;
        ordered.resize(n.size());
        int pos = -1;
        int i = n.size() ;
        while(i>=0)
        {
            ordered[count[n[i]]-1] = n[i];
            count[n[i]] -= 1;
            i--;
            if (n[i] == Q)
            {
                pos = count[n[i]-1];
            }
        }

        
        if (pos != -1)
        {
            cout<<Q<<" found at "<<pos<<endl;            
        }else
        {
            cout<<Q<<" not found"<<endl;
        }
       
        

        
        
               
    }
    


    return 0;
}
