#include<stdio.h>
#include<math.h>
int check(double X,double Y,int s);
double dis(double x1,double y1,double x2,double y2);

int main()
{
    int pointNum,side;
    while(scanf("%d%d",&pointNum,&side)!=EOF)
    {
        if(!pointNum && !side)
            break;
        int count=0;
        for(int num=0;num<pointNum;num++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            if(check(x,y,side))
                count++;
        }
        printf("%.5lf\n",(double)count*side*side/pointNum);
    }
    return 0;
}
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int check(double X,double Y,int s)
{
    if(dis(X,Y,0,0)<=s)
        if(dis(X,Y,0,s)<=s)
            if(dis(X,Y,s,s)<=s)
                if(dis(X,Y,s,0)<=s)
                    return 1;
    return 0;
}

