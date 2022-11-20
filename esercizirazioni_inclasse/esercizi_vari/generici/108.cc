#include <bits/stdc++.h>

#define max(x,y) x > y ? x : y

using namespace std;


int main()
{
    int n;
    cin>>n;
    vector < vector < int > >m;
    m.resize(n, vector < int > (n));
    bool flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            int e;
            cin>>e;
            if(e>0)flag = 1;
            m[i][j] = e;

        }
        
    }
    if(flag == 0)return 0;
    
    int max_sum = 0;

    for (size_t i = 0; i < n; i++)
    {
        vector <int> support(n);
        for (int j = i; j < n; j++)
        {
            for (size_t d = 0; d < n; d++) //APPIATTIMENTO magico
            {
                support[d] += m[j][d];
            }
            int sum = 0;
            int sum_partial = 0;
            for (size_t p = 0; p < n; p++)
            {
                sum_partial += support[p]; //sommo elementi in array e li metto in somma parziale
                sum =  max(sum, sum_partial); //se la somma che stava in sum è più piccola della somma partiale sum = sum_partial, altrimenti resta invariata
                sum_partial = (sum_partial < 0 ? 0 : sum_partial); //se sum_partial è negativa mi fermo perchè non incide sulla domma totale    
            }
            
            max_sum =  max(sum,max_sum); 
            
        }
        
    }
    cout<<max_sum<<endl;
    

    return 0;
}
