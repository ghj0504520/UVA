#include<stdio.h>
#include<math.h>
int main()
{
    double side;
    while(scanf("%lf",&side)!=EOF)
        printf("%.10lf\n",side*(sin(acos(-1)*3/5)/sin(acos(-1)*7/20)));
    return 0;
}
