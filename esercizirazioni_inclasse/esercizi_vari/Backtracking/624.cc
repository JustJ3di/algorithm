#include <bits/stdc++.h>

#define sum(x) accumulate(x.begin(),x.end(),0)
#define len(x) x.size()

using namespace std;

void sub_set(vector <int> &track, vector <int> &sub_track, vector <int> &ending, int start, int tot)
{
    int sum_current = sum(sub_track);
    int end_count = sum(ending);
    if(sum_current <= tot && sum_current > end_count)
    {
        end_count = sum_current;
        ending = sub_track;
    }
    
    {

        for (size_t i = start; i < len(track); i++)
        {
            sub_track.push_back(track[i]);
            sub_set(track,sub_track,ending,i + 1, tot);
            sub_track.pop_back();
        }
        

    }

    return ;
}



int main()
{
    int tot;

    while (cin>>tot)
    {

        int t;
        cin>>t;
        vector <int> track;
        for (size_t i = 0; i < t; i++)
        {
            int m;
            cin>>m;
            track.push_back(m);
        }

        vector <int > ending,sub_track;

        sub_set(track,sub_track,ending,0,tot);
        for (size_t i = 0; i < len(ending); i++)
        {
            cout<<ending[i]<<" ";

        }cout<<"sum: "<<sum(ending);
        

    }
    

    return 0;

}