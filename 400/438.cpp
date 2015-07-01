#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

double side(double p1_x,double p1_y,double p2_x,double p2_y);
double area_cross(double v1_x,double v1_y,double v2_x,double v2_y);

int main()
{
    double x_1,y_1,x_2,y_2,x_3,y_3;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x_1,&y_1,&x_2,&y_2,&x_3,&y_3)!=EOF)
    {
        double len_1,len_2,len_3;
        len_1=side(x_1,y_1,x_2,y_2);
        len_2=side(x_2,y_2,x_3,y_3);
        len_3=side(x_1,y_1,x_3,y_3);
         
        double area=area_cross(x_2-x_1,y_2-y_1,x_3-x_1,y_3-y_1);
        double r=len_1*len_2*len_3/(4*area);
        
        
        r=2*r*PI;
        printf("%.2lf\n",r);
        
    }
    return 0;
}

double side(double p1_x,double p1_y,double p2_x,double p2_y)
{
    p1_x=fabs(p1_x-p2_x);
    p1_y=fabs(p1_y-p2_y);

    double side_len=sqrt(p1_x=p1_x*p1_x+p1_y*p1_y);

    return side_len;
}


double area_cross(double v1_x,double v1_y,double v2_x,double v2_y)
{
    
    double area=fabs(v1_x*v2_y-v2_x*v1_y)/2;
    
    return area;
}
