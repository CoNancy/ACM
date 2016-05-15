#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cstdlib>
#include <cmath>

using namespace std;
const int maxn=100;
long lcm,gcd,n;
long factor[maxn],fac[maxn];
long Max;
long aa,bb;
int cnt=0,len=0;
long multi(long a,long b,long mod){
    long ret=0;
    while(b){
        if(b&1){
            ret=(ret+a)%mod;
        }
        a=a<<1;
        a=a%mod;
        b=b>>1;
    }
    return ret;
}
long quickPow(long a,long b,long mod){
    long ret=1;
    while(b){
        if(b&1)
            ret=multi(ret,a,mod);
        a=multi(a,a,mod);
        b=b>>1;
    }
    return ret;
}
bool witness(long a,long n){
    long m=n-1;
    int j=0;
    while(!(m&1)){
        j++;
        m=m>>1;
    }
    long x=quickPow(a,m,n);
    if(x==1||x==n-1)
        return false;
    while(j--){
        x=multi(x,x,n);
        if(x==n-1)
            return false;
    }
    return true;
}
//�ж�n�Ƿ�Ϊ���������ǣ�����true
bool Miller_Rabin(long n){
    if(n==2)
        return true;
    if(n<2 || !(n&1))
        return false;
    for(int i=0;i<5;i++){
        long a=rand()%(n-1)+1;
        if(witness(a,n))
            return false;
    }
    return true;
}
long Gcd(long a,long b){
    return b==0?a:Gcd(b,a%b);
}

long pollard_rho(long n,int c){
    long x,y,d,i=1,k=2;
    x=rand()%(n-1)+1;
    y=x;
    while(1){
        i++;
        x=(multi(x,x,n)+c)%n;
        d=Gcd((y-x+n)%n,n);
        if(1<d && d<n)
            return d;
        if(y==x)
            return n;
        if(i==k){
            y=x;
            k=k<<1;
        }
    }
}
//��n�����������ֽ�
void factorFind(long n,int k){
    if(n==1)
        return;
    if(Miller_Rabin(n)){
        factor[cnt++]=n;
        return;
    }
    long p=n;
    while(p>=n)
        p=pollard_rho(p,k--);
    factorFind(p,k);
    factorFind(n/p,k);
}
//dfsö��a��b��ֵ
void dfs(long a,long b,int k){
    //���Ŀǰa+b��ֵ�Ѿ�����Max�ˣ���ô��ֱ��return
    if(a+b>=Max){
        return;
    }
    if(k==len+1){
        if(a+b<Max){
            Max=a+b;
            aa=a;
            bb=b;
        }
        return;
    }
    dfs(a*fac[k],b,k+1);
    dfs(a,b*fac[k],k+1);
}

int main()
{
    long a,b;
    while(scanf("%I64d%I64d",&gcd,&lcm)!=EOF){
        n=lcm/gcd;
        //��nΪ�����Ļ�����aa=1,bb=lcm/gcd��
        if(Miller_Rabin(n)){
            //һ��ʼWA��ԭ���ǣ���gcd=1��ʱ���������1,lcm
            //�����ŷ��֣�����1 40�����5 8
            aa=1;
            bb=n;
            printf("%I64d %I64d\n",aa*gcd,bb*gcd);
        }
        else if(lcm==gcd){
            printf("%I64d %I64d\n",gcd,gcd);
        }
        else{
            cnt=0;
            factorFind(n,120);
            sort(factor,factor+cnt);
            len=0;
            fac[0]=factor[0];
            //�������ڶ�n�ֽ�������ʱ��a/gcd �� b/gcd�϶��������ʣ������Ƚ���ͬ���������ȳ�����
            //��������dfsʱaa��bb�϶����������ʵ�
            for(int i=1;i<cnt;i++){
                if(factor[i]==factor[i-1]){
                    fac[len]=fac[len]*factor[i];
                }
                else{
                    len++;
                    fac[len]=factor[i];
                }
            }

            //һ��ʼRE��ԭ�����£�
            //��lcm=gcdʱ��n=lcm/gcd=1����ôa=fac[0]=0��n/a��ʱ��ᵼ��RE������
            a=fac[0];
            b=1;
            Max=n/a+a;
            aa=a;
            bb=n/a;
            dfs(a,b,1);
            if(aa>bb){
                long tmp=aa;
                aa=bb;
                bb=tmp;
            }
            printf("%I64d %I64d\n",aa*gcd,bb*gcd);
        }
    }
    return 0;
}