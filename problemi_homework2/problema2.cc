//#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


long dp(int n, unordered_map<int, long> &mp) 
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
