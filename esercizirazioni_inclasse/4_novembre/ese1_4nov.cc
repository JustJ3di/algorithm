#include <bits/stdc++.h>
#include <vector>
#include <unistd.h>

using namespace std;

void print(vector<int> input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << " ";
    }
    cout<<endl;
}

void backtracking(vector <vector <int> >  & matrix, vector<int>  & current_sol ,int m, int n,int r , int c)
{
    
    if (  r == m -1  && c == n-1)
    {
        print(current_sol);
        return;     
    }
   
    if(r == 0 && c == 0)
    {
        current_sol.clear();
        current_sol.push_back(matrix[r][c]);

    }

    if (r < m-1)
    {
        r += 1;
        current_sol.push_back(matrix[r][c]);
        backtracking(matrix, current_sol, m, n, r, c);
        r -= 1;
        current_sol.pop_back();
        
    }

    if(c < n - 1)
    {
        c += 1;
        current_sol.push_back(matrix[r][c]);
        backtracking(matrix, current_sol, m, n, r, c);
        c -= 1;
        current_sol.pop_back();    
    }
    
}


int main()
{
    //m = righe
    //n = colonne
    int m,n;
    
    
    
    cin>>m;
    cin>>n;
    vector<vector<int> > matrix;
    matrix.resize(m,vector<int>(n));
    int count = 1;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {   
            matrix[i][j] = count;
            count+= 1;
        }
           
    }
    
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout<<matrix[i][j] <<" ";
        }
        cout<<endl; 
    
    }

    
    vector <int >sol;
    int r = 0, c = 0;
    backtracking(matrix, sol, m, n, r, c);
    
    
    return 0;
}