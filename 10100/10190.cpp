#include<cstdio>
#include<cstring>
#include<vector>
long long k[200000000];
int main()
{
    long long a,b,now;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        
        if(b<=1 ||a<=1 ||b>a)  //bug is if a=0 b>1.......
        {
            printf("Boring!\n");
            continue;
        }
        
        now=1;
        bool judge=1;
        k[0]=a;
        do
        {
            if(a%b!=0)
            {
                judge=0;
                break;
            }
            k[now]=(a/=b);
            now++;
        }while(a>1);
        if(judge==0)
        {
            printf("Boring!\n");
        }
        else
        {
            printf("%lld",k[0]);
            for(int i=1;i<now;i++)
            {
                printf(" %lld",k[i]);
            }printf("\n");
        }
    }    
    return 0;
}
