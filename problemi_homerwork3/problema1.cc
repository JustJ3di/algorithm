#include<iostream>
#include <string>

#define len(str) str.size()
using namespace std;

//memo
int dp[1001][1001];
int lsps(string s,int i, int j)
{
    if(i == j)return 1;
    if(i>j) return 0;
    if(dp[i][j]!= -1)
        return dp[i][j];
    
    if(s[i]==s[j])
        dp[i][j] = 2 +  lsps(s, i+1, j-1);
    else
        dp[i][j] = max(lsps(s, i+1, j),lsps(s,i,j-1));
        
    return dp[i][j];
    
}

int main()
{

    string s = "anspsana";
    memset(dp, -1, sizeof(dp[0][0]) *1001 * 1001);
    cout<<lsps(s,0,len(s)-1)<<endl;
    return 0;
}
