#include <iostream>
#include <vector>

using namespace std;



int max_area_1d(vector <int> arr)
{

    vector <int> result;

    int current_value;
    int max_area = 0; 
    int area = 0; 

    int i = 0;
    while (i < arr.size()) {
        
        if (result.empty() || arr[result.back()] <= arr[i])
        {
            result.push_back(i);
            i += 1;
        }
        else {

            current_value = arr[result.back()];
            result.pop_back();
            area = current_value * i;

            if (!result.empty())
                area = current_value * (i - result.back() - 1);
            max_area = max(area, max_area);
        }
    }


    while (!result.empty()) {
        current_value = arr[result.back()];
        result.pop_back();
        area = current_value * i;
        if (!result.empty())
            area = current_value * (i - result.back() - 1);

        max_area = max(area, max_area);
    }
    
    return max_area;
}

int max_zero_area(vector <vector <int> > &matrix)
{

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[i][j]==1)matrix[i][j]=0;
            else matrix[i][j] = 1;
        }
        
    }
    int C = matrix[0].size();
    int R = matrix.size();

    int result = max_area_1d(matrix[0]);

    for (int i = 1; i < R; i++) {

        for (int j = 0; j < C; j++)
            if(matrix[i][j])
                matrix[i][j] += matrix[i - 1][j];

        result = max(result, max_area_1d(matrix[i]));
    }

    return result;
}


int main()
{

    vector <vector<int> >b;
    int m,n;
    cin>>n;
    cin>>m;
    b.resize(n,vector <int> (m));

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {   
            int p;
            cin>>p;
            b[i][j] = p;
        }
        
    }
    
    

    int max = max_zero_area(b);
    
    cout<<max<<endl;

    return 0;
}


