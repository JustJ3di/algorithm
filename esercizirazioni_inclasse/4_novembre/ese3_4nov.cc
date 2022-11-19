#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

//move

bool check(vector < vector < int > > &area, int r_next, int c_next, int r, int c){

    return (r_next >= 0 && c_next >= 0 && r_next < area.size() && c_next < area[0].size() && area[r_next][c_next] >= 0 && area[r_next][c_next] < area[r][c]);
        
}

bool is_solution(vector < vector < int > > &area, int r, int c){

    if(check(area,r+1,c,r,c))return false;
    if(check(area,r,c+1,r,c))return false;
    if(check(area,r,c-1,r,c))return false;
    if(check(area,r-1,c,r,c))return false;

    return true;
}

void backtrack(vector < vector <int> > &area, int current_count, int *count,int r,int c)
{
    if(is_solution(area,r,c))
        if(current_count > *count) *count = current_count; 
    else
    {
        
        if(check(area,r,c+1,r,c))backtrack(area,current_count+1,count,r,c+1); 
        if(check(area,r+1,c,r,c))backtrack(area,current_count+1,count,r+1,c);
        if(check(area,r,c-1,r,c))backtrack(area,current_count+1,count,r,c-1);
        if(check(area,r-1,c,r,c))backtrack(area,current_count+1,count,r-1,c);

    }

}

int main()
{

    int R,C;

    string name_area;

    vector < vector < int > > A;

    int N;

    cin>>N;
    while (N--)
        {   cin>>name_area;
            cin>>R>>C;
            A.resize(R, vector <int> (C));
            for (size_t r = 0; r < R; r++)
                {
                    for (size_t c = 0; c < C; c++)
                    {
                        int input;
                        cin>>input;
                        A[r][c] = input;
                    }
                    
                }

            int end_count = 0;
            int fcount = 0;
            for (size_t i = 0; i < R; i++)
                {
                    for (size_t j = 0; j < C; j++)
                        {   
                            int count= 1;
                           
                            backtrack(A, count, &fcount, i, j);
                            if(fcount > end_count);
                                end_count = fcount;
                                        
                        }
                }
            cout<<"\n";
            cout<<name_area<<" "<<end_count<<"\n";
            cout<<endl;
            
        }

/*

2
Feldberg 10 5
56 14 51 58 88
26 94 24 39 41
24 16 8 51 51
76 72 77 43 10
38 50 59 84 81
5 23 37 71 77
96 10 93 53 82
94 15 96 69 9
74 0 62 38 96
37 54 55 82 38


Spiral 5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

*/

        /*
    cout<<name_area<<endl;
    for (size_t r = 0; r < R; r++)
    {
        for (size_t c = 0; c < C; c++)
        {
        
            cout<<A[r][c]<<" ";
        }
        cout<<"\n";
        
    }
    */
    return 0;
}
