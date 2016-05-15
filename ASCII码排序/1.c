#include<stdio.h>
int main()
{
    int N,i,j,k,q;
    char a[100][3],temp;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        for(j=0;j<=3;j++)
        {
            scanf("%c",&a[i][j]);
        }
    }
    for(q=0;q<N;q++)
	{
        for(i=0;i<3;i++)
        {
            k=i;
            for(j=i+1;j<3;j++)
                if(a[q][j]<a[q][k])
                    k=j;
                if(k!=i)
                {
                    temp=a[q][i];
                    a[q][i]=a[q][k];
                    a[q][k]=temp;
                }
        }
	}
    for(i=0;i<N;i++)
    {
        for(j=0;j<=3;j++)
        {
            printf("%c ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
