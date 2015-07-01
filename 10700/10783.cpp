#include<cstdio>
using namespace std;
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        for(int j=1;j<=t;j++)
        {
            printf("Case %d: ",j);
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b)
            {
                int swap=a;
                a=b;
                b=swap;
            }
            int sum=0;
            for(int i=a;i<=b;i++)
            {
                if(i%2!=0)
                {
                    sum+=i;
                }
            }
            printf("%d\n",sum);
        }
    }
    
}
