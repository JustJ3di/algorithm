#include <iostream>
#include <iomanip>

#define BASE 3

int main()
{

    float e;
    std::setprecision(6);
    while(scanf("%f", &e)==1)
    {
        if(e==1 or e== 0)printf("MEMBER\n");

        else
            {
                int count_res = 0;
                bool nonmemb = false;
                int i = 0;
                while(i < 10)
                {    
                    e = e*BASE;
                    
                    int new_val = (int)e;
                    printf("%d\n", new_val);
                        if(new_val == 1)
                        {
                                nonmemb = true;
                                break;
                        }
                        else if(new_val != 0) e -=2;
                    
                    i++;
                }
                if(nonmemb == true)printf("NON-MEMBER\n");
                else printf("MEMBER\n");
                
            }
         
        

    }

    return 0;
}