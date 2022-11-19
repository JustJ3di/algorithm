#include <iostream>
#include <vector>
#include<cmath>
#include<unistd.h>
using namespace std;

vector <int> find_digit(int num)
{
    vector <int> num_digit;
    while(num>0)
    {   
       
        num_digit.push_back(num%10);
        num = num/10;

    }
    return num_digit;
}

int main(int argc, char const *argv[])
{

    
    
    int T;
    cin>>T;
    int i = 1;
    while(T--)
        {
            int N;
            cin>>N;
            cout<<"\n";
            int n = N;
            vector <int> support;
            while (1)
            {
                
                
                vector <int> digit = find_digit(n);
                int sum = 0;
                for (size_t i = 0; i < digit.size() ; i++)
                {
                    sum+=pow(digit[i],2);
                }
                //sleep(1);
                
                n = sum;
                support.push_back(n);
                
                
                if(find_digit(n).size()==1)
                {   
                    
                    if(digit[1] == 1)
                    {
                        cout<<"Case #"<<i<<": "<<N<<" is a Happy\n";
                        goto label;
                    }
                    bool FLAG = 0;
                    for(auto e : support)
                    {
                        if(e==sum)
                        {
                            cout<<"Case #"<<i<<": "<<N<<" is a UnHappy\n";
                            FLAG = 1;
                        }
                    }
                    
                    if(FLAG ==1)break;
                
                }
                
            }
            label:
            i++;
            

        }

    
    return 0;
}
