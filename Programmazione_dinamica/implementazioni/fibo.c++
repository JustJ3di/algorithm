/*ESEMPIO DP con fibonacci*/

#include<bits/stdc++.h>

using namespace std;

long fib(int n, unordered_map<int, long> &mp) // correct
{
    if (mp.find(n) != mp.end())
        return mp[n];
    if (n <= 2)
        return 1;
    mp[n] = fib(n - 1, mp) + fib(n - 2, mp);
    return mp[n];
}

int main(int argc, char const *argv[])
{
    unordered_map <int,long>a;
    cout<<fib(8, a);

    return 0;
}
