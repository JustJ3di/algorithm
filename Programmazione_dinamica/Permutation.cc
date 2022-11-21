#include<iostream>
#include<vector>


using namespace std;

void backtrack(vector <int> &a,int l,int r)
{
    if(l == r)
    {
        for (size_t i = 0; i < a.size(); i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    else
    {
        for (int i = l; i <= r; i++) {

            swap(a[l], a[i]);

            backtrack(a, l + 1, r);

            swap(a[l], a[i]);
        }
    }

}





int main(int argc, char const *argv[])
{
    vector <int > a = {1,2,3,4};


    cout<<"all permutation:"<<endl;
    backtrack(a,0,a.size()-1);
    
        
    return 0;
}
