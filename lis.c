#include <stdio.h>
#define max(x , y) x>y ? x:y

int main(int argc, char const *argv[])
{
    int n = 6;

    int dp[6] = {1,1,1,1,1,1};
    int arr[6] = {1,2,10,7,4,3};

    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j <i;j++)
        {
            if(arr[j]<arr[i] && dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                }
        }
    }

    int max_t = 0;
    for(int i  = 0;i<n;i++)
    {
        max_t = max(dp[i],max_t);
    }

    printf("%d\n",max_t);


    return 0;
}
