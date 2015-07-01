#include<stdio.h>
#include<math.h>

double area(double s1,double s2,double s3);
int main()
{
    
    double side[3];
    while(scanf("%lf%lf%lf",&side[0],&side[1],&side[2])!=EOF)
    {
        if(!side[0]&&!side[1]&&!side[2])
            printf("The radius of the round table is: 0.000\n");
        else
            printf("The radius of the round table is: %.3lf\n",2*area(side[0],side[1],side[2])/(side[0]+side[1]+side[2]));
    }
    return 0;
}

double area(double s1,double s2,double s3)
{
    double s=(s1+s2+s3)/2;
    return sqrt(s*(s-s1)*(s-s2)*(s-s3));
}
