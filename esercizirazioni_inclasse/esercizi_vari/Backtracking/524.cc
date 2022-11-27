#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//prendi gli input
//cosruisci una funzione che mi dice se un numero è primo
//costruisi nuove combinazione del vettore ed ogni volta verifica array[i] + array[i+1] sia primo nota: l'ultimo elemento si somma al primo array[array.size()-1] + array[0]


bool sum_is_prime(int x, int y)
{

    int sum = x+y;


    for (int i = sum - 1; i > 1; i--)
    {
        int r = sum%i;
        if(r == 0)return false;
    }
    
    return true;

}



void backtrack(vector <int> &a,int l,int r)
{
    if(l == r)
    {
        bool flag = 1;
        for (size_t i = 0; i <= r-1; i++)
        {
            if (not(sum_is_prime(a[i],a[i+1])))
            {
                flag = 0;
            }
            
        }
        if(not(sum_is_prime(a[r],a[0])))flag = 0;
        
        if (flag == 1)
        {
            for (size_t i = 0; i < a.size(); i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        
        

    }
    else
    {
        for (int i = l; i <= r; i++) {

            swap(a[l], a[i]);

            backtrack(a, l + 1, r);

            swap(a[l], a[i]);
        }
    }

}


int main(int argc, char const *argv[])
{

    int n;
    int count_case = 0;
    while (scanf("%d",&n))
    {
        if(n<0 || n > 16)return;
        vector <int> set;
        int i = 1;
        while(i <= n)
        {

            set.push_back(i);
            i++;
        }


        cout<<"Case "<<count_case++<<": \n";

        backtrack(set, 1, set.size() - 1);


    }
    

    cout<<sum_is_prime(2,6)<<endl;

    return 0;
}

