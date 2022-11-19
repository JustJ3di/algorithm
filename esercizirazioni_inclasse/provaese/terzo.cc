
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string diff(string str1, string str2)
{
    int i = 0, j = 0;
    string prefix = "";
    while (i < str1.length() && j < str2.length())
    {
        if (str1[i] != str2[j]) {
            break;
        }
        prefix += str1[i];
        i++, j++;
    }

    return prefix;
}



string find_tot_diff(vector<string> const &words)
{
    string prefix = words[0];
    for (size_t i = 1; i < words.size(); i++)
    {
        prefix = diff(prefix,words[i]);
    }
    

    return prefix;
}

int main()
{
    vector<string> words { "apple", "ape", "april", "applied" };

    cout << "Output: " << find_tot_diff(words)<<endl;
    
    return 0;
}