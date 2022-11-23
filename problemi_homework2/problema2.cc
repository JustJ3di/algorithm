//#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Una volta sviluppata la ricorrenza dp(n) = (n-1)dp(n-2) + dp(n-1).
è immediato ricavare i casi base , d(1) e d(2) i quali hanno rispettivamente valore 1 e 2.
Si utilizza una map per la memoization per tenere traccia del problema precedente ogni volte che esso 
*/


int64_t dp(int n, unordered_map<int, int64_t> &mp) 
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
    
    unordered_map <int,long>a;
    
    cout<<dp(4,a)<<endl;

    return 0;
}
