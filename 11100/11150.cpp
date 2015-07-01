#include<stdio.h>

int main()
{
    int num;
    while(scanf("%d",&num)!=EOF)
    {
        int sum=num;
        while(num>=3)
        {
            int remain = num/3;
            sum+=remain;
            num%=3;
            num+=remain;
        }
        num==2? sum++:sum;              /*figure*/
        printf("%d\n",sum);
    }
    return 0;
}
