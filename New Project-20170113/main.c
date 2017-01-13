#include <stdlib.h>
#include <math.h>
#include <stdio.h>
int *dectobin(int n, int b);
void matrixmul(int A[2][2],int B[][2],int C[][2]);
int fibb4(int n);

int main()
{
    int n=0,res=0;
    printf("Enter the value of n");
    scanf("%d",&n);
    res = fibb4(n);
    printf("The %d Fibonacci Number is %d",n,res);
}

int *dectobin(int n, int b)
{
    int *binary = (int*) malloc(sizeof(int)*b);
    int i;
    for (i =0; i<b; i++)
    {
            *(binary+b-i-1) = n%2;
            n = n/2;
    }
    return binary;
}

int fibb4(int n)
{
  int i=0;
    int b = ceil(log(n)/log(2));
    //printf("%d",b);
    int* bin;
    int Q[2][2] =
    {
    {1,1},
    {1,0}
    };
    int P[2][2] =
    {
    {1,1},
    {1,0}
    };
    bin = dectobin(n,b);
    int T[2][2] =
    {
    {1,0},
    {0,1}
    };
    int I[2][2] =
    {
    {1,0},
    {0,1}
    };
    printf("%d %d %d %d %d\n",T[0][0],b,*(bin),*(bin+1),*(bin+2));
      printf("%d %d %d %d\n",T[0][0],T[0][1],T[1][0],T[1][1]);
    //printf("%d %d %d %d %d %d",*(bin),*(bin+1),*(bin+2),*(bin+3),*(bin+4));
    for (i = 0; i< b; i++)
    {        
            if (bin[b-i-1]==1)
            {
                matrixmul(T,T,P);
            }
            else
            {
                matrixmul(T,T,I);
            }
            matrixmul(P,P,Q);
            printf("%d %d %d %d\n",P[0][0],P[0][1],P[1][0],P[1][1]);
            printf("%d %d %d %d\n",T[0][0],T[0][1],T[1][0],T[1][1]);
    }
    return T[0][0];
}

void matrixmul(int A[2][2],int B[2][2],int C[2][2])
{
   int i,j,k,sum=0;
   for(i = 0; i< 2; i++)
   {
        for(j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                  sum = sum + B[i][k]*C[k][j];
                }
                  A[i][j] = sum;
                  //printf("%d\n",sum);
                  sum =0;
       }
   }
}