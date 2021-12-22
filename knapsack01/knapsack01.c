#include<stdio.h>

int main()
{
	int wgt,n,i,j,w,a,b,max=0;
	int m[10][2],km[10][10];

	printf("\nEnter the number of Items \n" );
	scanf("%d",&n);
	printf("\nEnter values of Input matrix \n");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d%d",&m[i][0],&m[i][1]);
	}
	printf("\nEnter the Knapsack capacity ");
	scanf("%d",&wgt);

	printf("\nthe input matrix");
	printf("\n\titem\tweight\tvalue\n");
	for(i=0;i<=n-1;i++)
	{
		printf("\n\t%d\t%d\t%d",i+1,m[i][0],m[i][1]);
	}

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=wgt;j++)
		{
			if(i==0 || j==0)
				km[i][j]=0;

			else if((j-m[i-1][0])<0)
				km[i][j]=km[i-1][j];

			else if((j-m[i-1][0])>=0)
			{
				a=km[i-1][j];
				b=m[i-1][1]+km[i-1][(j-m[i-1][0])];
				if(a>b)
			  		km[i][j]=a;
				else
					km[i][j]=b;
			}
		 }
	}
	printf("\n\nKnapsack matrix\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=wgt;j++)
		{
			printf("\t%d",km[i][j]);
		}
		printf("\n");
	}

	i=n;   j=wgt;   w=0;    max=0;
	printf("\noptimum solution\n");
	printf("\n\n\tinput\tweight\tvalue");
	while(wgt-w>0)
	{
		if(km[i][j]!=km[i-1][j])
		{
			printf("\n\t%d\t%d\t%d",i,m[i-1][0],m[i-1][1]);
			max=max+m[i-1][1];
			w=w+m[i-1][0];
			j=wgt-w;
		}
		i--;
          if (i<1) break;
	}
	printf("\n\n\tMaximum value in the knapsack : %d",max);

	return 0;
}
