int memo[101][101];
int dp(vector<vector<int>>& matrix,int i, int j,int size)
{
    if(i >=size)return 0;
    if(j >=size || j<0) return 100000;
    if(memo[i][j])return memo[i][j];
    memo[i][j] = min({dp(matrix,i+1,j-1,size) ,dp(matrix,i+1,j,size),dp(matrix,i+1,j+1,size)}) + matrix[i][j];
    return memo[i][j];
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    memset(memo,0,sizeof(int)*101*101);
    int min_path = 10000;
    int size = matrix.size();
    for(int i = 0;i<size;i++)
        {
            min_path = min(dp(matrix,0,i,size),min_path);
        }
    return min_path;
}