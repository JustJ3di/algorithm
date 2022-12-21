int memo[100][100];
int backtrack(vector<vector<int>>& Grid,int m,int n ,int i ,int j)
    {
        if(i>=m || j >= n || Grid[i][j])return 0;
        if(memo[i][j])return memo[i][j];
        return memo[i][j] = backtrack(Grid,m,n,i+1,j) + backtrack(Grid,m,n,i,j+1);
    }
int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
    int m = Grid.size() , n = Grid[0].size();
    memset(memo, 0, sizeof memo);
    if(Grid[0][0] || Grid[m-1][n-1])return 0;
    memo[m-1][n-1] = 1;
    return backtrack(Grid,m,n,0,0);
}