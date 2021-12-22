/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int Place(int k,int i,int x[10])
{
    int J;
    for (J=1;J<=k-1;J++)
    {
        if((x[J]==i)|| (abs(J-k))==(abs(x[J]-i)))
        return 0;
    }
    return 1;
}
void nQueens(int k,int N)
{
    int i,J,il;
    static int iCount , x[10];
    for (i=1;i<=N;i++)
    {
        if(Place(k,i,x))
        {
            x[k]=i;
            if(k==N)
            {
                printf("\n feasible solution=%d",++iCount);
                printf("\n solution are=");
                for (J=1;J<=N;J++)
                {
                    printf("\n");
                    for(i=1;i<=N;i++)
                    {
                        if(i==x[J])
                        printf(" Q ");
                        else
                        printf(" 0 ");
                    }
                }
            }
            else
            nQueens(k+1,N);


        }

    }
}
void main()
{
    int N;
    printf("ënter the number of queens:");
    scanf("%d",&N);
    nQueens(1,N);
    getch();
}

