#include<iostream>
#include<cstdio>
using namespace std;

int t;
void print_number(long long num)
{
    if(num>=10000000)
    {
        print_number(num/10000000);
        cout<<" kuti";
        num%=10000000;
    }
    if(num>=100000)
    {
        print_number(num/100000);
        cout<<" lakh";
        num%=100000;
    }
    if(num>=1000)
    {
        print_number(num/1000);
        cout<<" hajar";
        num%=1000;
    }
    if(num>=100)
    {
        print_number(num/100);
        cout<<" shata";
        num%=100;
    }
    if(num)
    {
        if(t++)
        cout<<" ";
        cout<<num;
    }
}

int main()
{
    long long input;
    int run=0;
    while(cin>>input)
    {
        printf("%4d. ",++run);
        //cout<<++run<<". ";
        t=0;
        if(!input)
            cout<<"0";
        else
            print_number(input);
        cout<<'\n';
    }
    return 0;
}
