#include <stdio.h>

#define N 100

int main(int argc, char const *argv[])
{
    int a = 5;
    int i,j,M[N][N];

	M[0][0]=1;
	for(j=1;j<3;j++)
	   M[0][j]=0;
			
	//calcolo le altre righe		
	for(i=1;i<a;i++) {
	  M[i][0]=1;
	  for(j=1;j<a;j++)
	      M[i][j]=M[i-1][j-1]+M[i-1][j];
	}

    i = a-1;
    for (size_t j = 0; j < a; j++)
    {
        printf("%d \t", M[i][j]);
    }
    printf("\n");
    

    

    return 0;
}

