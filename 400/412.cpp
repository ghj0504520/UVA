#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool gcd(int num1,int num2);

int main()
{
    int num;
    while(cin>>num)
    {
        if(num ==0)
            break;
        int data[num];
        for(int i=0;i<num;i++)
        {
            cin>>data[i];
        }
        long long int count=0;
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                if(i!=j && gcd(data[i],data[j])==1)
                {
                    count++;
                }
            }
        }
        if(!count)
            cout<<"No estimate for this data set.\n";
        else 
        {
            count/=2;
            double ans=(double)count/((num*(num-1))/2);
            ans=sqrt(6/ans);
            printf("%.6lf\n",ans);
        }
    }
    return 0;
}

bool gcd(int num1,int num2)
{
    if(num1>num2)
    {
        num1 ^=num2 ^=num1 ^=num2;
    }
    int r=num2%num1;
    while(r!=0)
    {
        num2=num1;
        num1=r;
        r=num2%num1;
    }
    return num1==1? 1:0;
}
