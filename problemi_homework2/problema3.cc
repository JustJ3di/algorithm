#include <iostream>
#include <vector>
#include <stack>

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



int main(int argc, char const *argv[])
{
    int b[4][4] = { {0,1,0,0},
                    {1,0,0,0},
                    {0,1,0,0},
                    {1,0,0,1}};

    vector <vector <int> > a;

    a.resize(4,vector <int>(4));

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {

            a[i][j] = b[i][j];

        }
        
    }
    


    int m = 4;
    int n = 4;


    vector <int> d(m, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1) {
                d[j] = i;
            }
        }
    }


    int c = zero_matrix(a);

    cout<<c<<endl;

    return 0;
}



