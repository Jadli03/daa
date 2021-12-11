#include<stdio.h>
#include<stdlib.h>

 int place(int k,int i,int x[10])
    {
        int j;
        for(j=0;j<=k-1;j++)
        {
            if(x[j]==i||abs(j-k)==(x[j]-i))
                return 0;
        }
        return 1;
    }

void nqueen(int k,int n)
{
    int i,j,il;
    static int icount,x[10];
    for(i=1;i<=n;i++)
    {
        if(place(k,i,x))
        {
            x[k]=i;
            if(k==n)
            {
                printf("\nfeasible Sol %d",++icount);
                printf("\n Sol are");
                for(j=1;j<=n;j++)
                    printf("%d",x[j]);
                for(j=1;j<=n;j++)
                {
                    printf("\n");
                    for(i=1;i<=n;i++)
                        {
                            if(i==x[j])
                                printf("Q");
                            else
                                printf("0");
                        }
                }

            }
            else
                nqueen(k+1,n);

        }
    }
}

void main()
{
    int n;
    printf("Enter the no of Queen  \n");
    scanf("%d",&n);
    nqueen(1,n);
}

