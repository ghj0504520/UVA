#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int change(string in,int l);

int gcd(int s_1,int s_2);

int main()
{
    string input_1,input_2;
    int t;
    while(cin>>t)
    {
        for(int i=0;i<t;i++)
        {
            cin>>input_1>>input_2;
            int len_1=input_1.length(),len_2=input_2.length();
            reverse(input_1.begin(),input_1.end());
            reverse(input_2.begin(),input_2.end());
            int sum_1=change(input_1,len_1),sum_2=change(input_2,len_2);
            int GCD=gcd(sum_1,sum_2);
            cout<<"Pair #"<<i+1<<": ";
            GCD!=1? cout<<"All you need is love!" : cout<<"Love is not all you need!";
            cout<<'\n';
        }
    }
}

int change(string in,int l)
{
    int sum=0;
    for(int i=0;i<l;i++)
    {
        int num=in[i]-'0';
        sum+=num*pow(2,i);
    }
    return sum;
}

int gcd(int s_1,int s_2)
{
    if(s_1<=s_2)
    {
        int swap=s_1;
        s_1=s_2;
        s_2=swap;
    }
    int mod=s_1%s_2;
    while(mod!=0)
    {
        s_1=s_2;
        s_2=mod;
        mod=s_1%s_2;
        
    }
    return s_2;
}
