#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define r_min 6
#define r_hour 0.5
int main()
{
    char time_in[10];
    while(scanf("%s", time_in)!=EOF)
    {
        int hour,min;
        sscanf(time_in, "%d:%d", &hour, &min);
        if(hour==0 && min==0)
            break;
        double h,m;
        h=hour*30+min*r_hour;
        m=min*r_min;
        double arc_1,arc_2;
        arc_1=fabs(h-m);
        arc_2=360-arc_1;
        printf("%.3lf\n" ,arc_1>arc_2? arc_2:arc_1);
        
    }
}
