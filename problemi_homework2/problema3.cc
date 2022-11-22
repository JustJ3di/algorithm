#include<bits/stdc++.h>

using namespace std;


int zero_matrix(vector<vector<int> > a) {
    int n = a.size();
    int m = a[0].size();

    int ans = 0;
    vector<int> d(m, -1), d1(m), d2(m);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1)
                d[j] = i;
        }

        for (int j = 0; j < m; ++j) {
            while (!st.empty() && d[st.top()] <= d[j])
                st.pop();
            d1[j] = st.empty() ? -1 : st.top();
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = m - 1; j >= 0; --j) {
            while (!st.empty() && d[st.top()] <= d[j])
                st.pop();
            d2[j] = st.empty() ? m : st.top();
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = 0; j < m; ++j)
            ans = max(ans, (i - d[j]) * (d2[j] - d1[j] - 1));
    }
    return ans;
}


int sub_zero_matrix(vector <vector<int>> &m)
{

    int c = m[0].size(),r = m.size();

    vector <vector <int> > dp;
    dp.resize(r, vector<int>(c));

    int result = 0;

    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            if(m[i][j] == 0)
            {
                if(i==0 && j==0)
                    dp[i][j] == 1;
                else if(i)
                    dp[i][j] = 1+dp[i-1][j];
                else if(j)
                    dp[i][j] = 1+dp[i][j-1];
                else 
                    dp[i][j] = 1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                
            }
            result = max(result, dp[i][j]);
        }
        
    }

    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            cout<<dp[i][j]<<" ";
        }cout<<endl;
        
    }
    
    
    return result;
}

int main(int argc, char const *argv[])
{
    vector <vector<int> >b = {  {0,1,0,0},
                                {1,0,0,0},
                                {0,1,0,0},
                                {1,0,0,1}};

    int max = zero_matrix(b);
    


    cout<<max<<endl;
    cout<<sub_zero_matrix(b);

    return 0;
}



