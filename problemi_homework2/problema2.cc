#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdint.h>

using namespace std;

/*-------------------------------------------------------------------------------------------------*
|                               Emanuele d'Ajello - Marco d'Elia                                   |
|                               Homework 2 - PROBLEMA 2                                            |
|                                                                                                  |
|    Una volta ricavata la ricorrenza dp(n) = (n-1)dp(n-2) + dp(n-1).                              |
|    è immediato ricavare i casi base , d(1) e d(2) i quali hanno rispettivamente valore 1 e 2.    |
|    Si utilizza una map per la memoization per tenere traccia del problemi già risolti            |
|    all indice n-esimo .                                                                          |
--------------------------------------------------------------------------------------------------*/

//La complessità asintotica al netto della ricorrenza è O(n)
int64_t dp(int n, unordered_map<int, size_t> &mp) 
{
    if (mp.find(n) != mp.end())
        return mp[n];

    if (n==2)return 2;
    else if(n==1) return 1;

    mp[n] = (n-1)*dp(n - 2, mp) + dp(n - 1, mp);
    return mp[n];
}

int main()
{
    
    /*
    Possibili test
    
    TEST 1:
    Input: 0
    Output atteso:
    Insieme nullo non contemplato.
    
    TEST 2:
    Input: 2
    Output atteso:
    2
    
    TEST 3:
    Input: 4
    Output atteso:
    10

    TEST 4
    Input: 15
    Output atteso:
    10349536

    TEST 5 
    Input :5
    Output atteso: 
    26
    
    */

    unordered_map <int,size_t>a;
    int T;
    cout<<"Numero di casi di test: ";
    cin>>T;
    while(T--)
    {   
        unsigned int n;
        cout<<"Inserire cardinalità insieme :";
        cin>>n;
        if (n==0)
            {   cout<<"Insieme nullo non contemplato.\n";
                continue;
            }
        int64_t res = dp(n,a);
        cout<<"risultato : "<<res<<endl;
    }



    return 0;
}
