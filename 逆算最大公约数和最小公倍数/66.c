#include <stdio.h>
#include <math.h>
long hz(long x,long y)
{
    return (x%y)?hz(y,x%y):y;    
}
int main()
{   
    long a,b,c,i,t;
    while(scanf("%lld%lld",&a,&b)==2)
    {     
          c=b/a;
          for(i=(long)sqrt(c+0.5);i>=1;i--)
          {
              if(c%i==0&&hz(i,c/i)==1)             
              {
                 printf("%lld %lld\n",a*i,c/i*a);
                 break;
              }
          }                              
    }
    return 0;    
}
