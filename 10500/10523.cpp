#include<iostream>
#include<cstring>
using namespace std;

void big_Plus(int *bigNumber,int *bigSwap);          //big number plus
void big_Time(int *bigPower,int num);                //big number time(or power)

void big_CarryP(int *bigPower);                      //big number carry for time(or power) ,modify length of big number time(or power)
void big_CarryA(int *bigNumber);                     //big number carry for plus  ,modify length of big number plus

int lenP,lenA;

int main()
{
    int n,a;
    while(cin>>n>>a)
    {
        if(a==0)
        {
            cout<<0<<'\n';
            continue;
        }
        lenA=0;
        lenP=0;
        int bigNumber[1000];
        int bigPower[1000];
        memset(bigNumber,0,sizeof(bigNumber));
        bigNumber[0]=0;
        memset(bigPower,0,sizeof(bigPower));
        bigPower[0]=a;
        for(int i = 1;i <= n;i ++)
        {
            int bigSwap[1000];
            memset(bigSwap,0,sizeof(bigSwap));
        
            big_Time(bigPower,a);
            for(int k=0;k<lenP;k++)
            {
                bigSwap[k]=bigPower[k];
            }      
            
            big_Time(bigSwap,i);
            
            big_Plus(bigNumber,bigSwap);
        }

        for(int m=lenA-1;m>=0;m--)
        {
            cout<<bigNumber[m];
        }cout<<'\n';
    }
}

void big_Time(int *bigPower,int num)
{
    for(int i=0;i<lenP;i++)
    {
        bigPower[i] *=num;
    }
    big_CarryP(bigPower);
}
void big_CarryP(int *bigPower)
{
    for(int i=0;i<lenP+10;i++)
    {
        if(bigPower[i]>=10)
        {
            bigPower[i+1]+=bigPower[i]/10;
            bigPower[i]%=10;
        }
    }
    int nowL=0;
    for(int k=1000-1;k>=0;k--)
    {
        if(bigPower[k]!=0)
        {
            nowL=k+1;
            break;
        }
    }
    lenP=nowL;
}
void big_Plus(int *bigNumber,int *bigSwap)
{
    for(int i=0;i<lenP;i++)
    {
        bigNumber[i]+=bigSwap[i];
    }
    big_CarryA(bigNumber);
}
void big_CarryA(int *bigNumber)
{
    for(int p=0;p<lenA+10;p++)
    {
        if(bigNumber[p]>=10)
        {
            bigNumber[p+1]+=bigNumber[p]/10;
            bigNumber[p]%=10;
            
        }
    }
    int nowL=0;
    for(int k=1000-1;k>=0;k--)
    {
        if(bigNumber[k]!=0)
        {
            nowL=k+1;
            break;
        }
    }
    lenA=nowL;
}
