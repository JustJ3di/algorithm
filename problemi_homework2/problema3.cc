#include<bits/stdc++.h>

using namespace std;

/*
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

*/


//Sfrutto l'idea dell algoritmo di kadan per contare gli zeri contigui in un vettore

int max_zero_array(vector <int> &array){

    int number_of_zero = 0;
    int number_of_zero_partial = 0;

    for(auto e : array)
    {
        if(e==0)number_of_zero_partial += 1;
        number_of_zero = (number_of_zero > number_of_zero_partial ? number_of_zero : number_of_zero_partial);
        if(e != 0)number_of_zero_partial = 0;
    }

    return number_of_zero;

}



int main(int argc, char const *argv[])
{
    int b[4][4] = { {0,1,0,0},
                    {1,0,0,0},
                    {0,1,0,0},
                    {1,0,0,1}};

    int max = 0;

    for (size_t i = 0; i < 4; i++)
    {
        vector <int> my(4);
        for (size_t j = i; j < 4; j++)
        {
            for (size_t c = 0; c < 4; c++)
            {
                my[c] += b[j][c];
            }
            int sum_current = max_zero_array(my);
            max = (max > sum_current?max: sum_current);   

        }
        
    }
    


    cout<<max<<endl;

    return 0;
}



