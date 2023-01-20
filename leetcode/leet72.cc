int memo[501][501];
#define min(x,y) (x<y?x:y)
int dp(int i,int j, char * s1,char * s2)
{
    if (i==0)return j;
    if (j == 0)return i;
    if(memo[i][j]!=-1)return memo[i][j];

    if (s1[i-1] == s2[j-1]) { //non fare nulla
        memo[i][j] = dp(i - 1, j - 1,s1, s2);
        return memo[i][j];
    }else 
    {
        memo[i][j] = 1 + min(dp(i - 1, j - 1,s1, s2),min(dp(i - 1, j ,s1, s2),dp(i, j - 1,s1, s2)));
        return memo[i][j];
    }

}
int minDistance(char * word1, char * word2){
        memset(memo,-1,sizeof(int)*501*501);
        return dp(strlen(word1),strlen(word2),word1,word2);
}