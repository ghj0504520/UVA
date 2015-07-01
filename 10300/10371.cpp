#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
    map<string ,double>zone;                        //build time zone
    zone["UTC"]=0,zone["GMT"]=0,zone["BST"]=1;
    zone["IST"]=1,zone["WET"]=0,zone["WEST"]=1;
    zone["CET"]=1,zone["CEST"]=2,zone["EET"]=2;
    zone["EEST"]=3,zone["MSK"]=3,zone["MSD"]=4;
    zone["AST"]=-4,zone["ADT"]=-3,zone["NST"]=-3.5;
    zone["NDT"]=-2.5,zone["EST"]=-5,zone["EDT"]=-4;
    zone["CST"]=-6,zone["CDT"]=-5,zone["MST"]=-7;
    zone["MDT"]=-6,zone["PST"]=-8,zone["PDT"]=-7;
    zone["HST"]=-10,zone["AKST"]=-9,zone["AKDT"]=-8;
    zone["AEST"]=10,zone["AEDT"]=11,zone["ACST"]=9.5;
    zone["ACDT"]=10.5,zone["AWST"]=8;

    int  ask_t;
    while(cin>>ask_t)
    {
        while(ask_t--)
        {
            char data[100];
            cin>>data;
            int h=0,m=0;
            if(data[0]=='n')                           //change noon
            {
                h=12;
                m=0;
            }
            else if(data[0]=='m')                     //change midnight
            {
                h=0;
                m=0;
            }
            else
            {
                sscanf(data,"%d:%d",&h,&m);           //be careful the way of sscanf() 
                cin>>data;
                if(data[0]=='p'&&h!=12)               //change p.m.
                {
                    h+=12;
                }
                else if(data[0]=='a'&&h==12)          //change a.m.
                {
                    h=0;
                }
            }
            string s ,f;
            cin>>s>>f;

            m=h*60+m;                                //change hour to minute
            m=m-zone[s]*60+zone[f]*60+24*60;         //change time zone
            h=m/60%24;                               //change minute to hour
            m=m%60;       
            if(h==0&&m==0)                           //judge midnight
                cout<<"midnight\n";
            else if(h==12&&m==0)                     //judge noon
                cout<<"noon\n";
            else 
            {
                if(h>=0&&h<12)                       //judge a.m.
                {
                    if(h==0)
                        cout<<12;
                    else 
                        cout<<h;
                    printf(":%.2d",m);
                    cout<<" a.m.\n";
                }
                if(h>=12&&h<=23)                     //judge p.m.
                {
                    if(h>12)
                        cout<<h%12;
                    else cout<<h;
                    printf(":%.2d",m);
                    cout<<" p.m.\n";
                }
            }
        }
    }

}
