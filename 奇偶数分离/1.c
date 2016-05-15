#include<stdio.h>
void fenli(int n)
{
      int a[5000],b[5000],i=0,j=0,k=0;
      for(i=1;i<=n;i++)
      {
            if(i%2)
            {
                  a[j]=i;
                  j++;
            }
            else
            {
                  b[k]=i;
                  k++;
            }
      }
      i=0;
      while(a[i])
      {
            printf("%d ",a[i]);
            i++;
      }
      printf("\n");
      i=0;
      while(b[i])
      {
            printf("%d ",b[i]);
            i++;
      }
      printf("\n");
      printf("\n");
}
int main()
{
      int i,j,a[30],n;
      scanf("%d",&i);
      for(j=0;j<i;j++)
      {
            scanf("%d",&a[j]);
      }
      for(j=0;j<i;j++)
      {
            n=a[j];
            fenli(n);
      }
      return 0;
}
