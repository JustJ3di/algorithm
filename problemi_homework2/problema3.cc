#include<bits/stdc++.h>

using namespace std;


int max_area_1d(vector <int> arr)
{

    stack<int> result;

    int current_value;
    int max_area = 0; 
    int area = 0; 

    int i = 0;
    while (i < arr.size()) {
        
        if (result.empty() || arr[result.top()] <= arr[i])
            result.push(i++);

        else {

            current_value = arr[result.top()];
            result.pop();
            area = current_value * i;

            if (!result.empty())
                area = current_value * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }


    while (!result.empty()) {
        current_value = arr[result.top()];
        result.pop();
        area = current_value * i;
        if (!result.empty())
            area = current_value * (i - result.top() - 1);

        max_area = max(area, max_area);
    }
    
    return max_area;
}

int maxRectangle(vector <vector <int> > &A)
{
    int C = A[0].size();
    int R = A.size();

    vector <int> arr;
    for (size_t i = 0; i < C; i++)
    {
        arr.push_back(A[0][i]);
    }
    
    
    int result = max_area_1d(arr);

    cout<<"result = "<<result<<endl;

    for (int i = 1; i < R; i++) {

        for (int j = 0; j < C; j++)
            if (A[i][j])
                A[i][j] += A[i - 1][j];

        result = max(result, max_area_1d(A[i]));
    }

    return result;
}


int main(int argc, char const *argv[])
{
    vector <vector<int> >b = {  {0,0,1,0},
                                {0,0,0,0},
                                {0,0,0,0},
                                {1,0,1,1}};


    for (size_t i = 0; i < b.size(); i++)
    {
        for (size_t j = 0; j < b[0].size(); j++)
        {
            if(b[i][j]==1)b[i][j]=0;
            else b[i][j]=1;
        }
        
    }
    
    for (size_t i = 0; i < b.size(); i++)
    {
        for (auto i : b[i])
        {
            cout<<i<<" ";
        }cout<<endl;
        
    }
    

    int max = maxRectangle(b);
    
    cout<<max<<endl;

    return 0;
}



