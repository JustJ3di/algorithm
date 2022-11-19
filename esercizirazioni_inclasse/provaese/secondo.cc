#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string buf;
    int n;
    while(true){
        getline(cin,buf); //read ONE full line
        if(buf.empty()){
            break;
        }
        istringstream inp(buf); // input string stream to read the full line input

        inp>>n;

        vector<bool> diffNums(n,false);
        bool jollyJump = true;
        int prev,curr;
        inp>>prev;
        for(int i = 1;i < n;i++){

            int diff;

            inp>>curr;

            if(!curr>0){
                jollyJump = false; // number < 0
                break;
            }
            diff = prev > curr ? prev - curr : curr - prev; // find the difference (We can use abs function in cmath)

            if(diff<=0 || diff >= n || diffNums[diff-1]){
                    jollyJump = false; // difference is not valid.
                    break;
            }
            diffNums[diff-1] = true;
            prev = curr;
            }

        cout<< (jollyJump?"Jolly":"Not jolly") <<endl; //print result
    }
    return 0;
}
