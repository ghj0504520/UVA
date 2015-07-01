#include<iostream>
#include<cstdio>
using namespace std;
int minus_same(int k)
{
    if(k==1)
        return 1 ;
    else
    {    
        if(k%2==0)
            return minus_same(k/2)+1 ;
        else
            return minus_same((k-1)/2)+1;
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        int p=minus_same(n);
        cout<<p<<'\n';
    }
    return 0;
}
