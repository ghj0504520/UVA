#include <cmath>
#include <iostream>
#include <map>
using namespace std;
bool is4(string y)
{
    int l=y.size();
    
    int s = (y[l-2]-'0')*10+(y[l-1]-'0');
    return s%4==0;
}

bool is100(string y)
{
    int l=y.size();

    return !(y[l-2]-'0')&&!(y[l-1]-'0');
}

bool is400(string y)
{
    int l=y.size();
    
    int s = (y[l-4]-'0')*10+(y[l-3]-'0');
    return !(y[l-2]-'0')&&!(y[l-1]-'0')&&s%4==0;
}

bool is3(string y)
{
    int l=y.size();
    
    int s = 0;
    for(int i=0 ; i<l ; i++)
        s+=y[i]-'0';
    return s%3==0;
}

bool is5(string y)
{
    int l=y.size();

    return (y[l-1]-'0')%5==0;
}
bool is11(string y)
{
    int l=y.size();
    
    int os = 0, es =0;
    
    
    for(int i=1 ; i<l ; i+=2)
        es+=y[i]-'0';
    for(int i=0 ; i<l ; i+=2)
        os+=y[i]-'0';
    
    return (os>es?((os-es)%11==0):((es-os)%11==0));
}

int main()
{
    int t=0;
    string y;
    while(cin>>y)
    {
        if(t++)cout<<"\n";
        bool l=0,h=0,b=0;
        
        if(( is400(y) )||( is4(y)&&!is100(y) ))l=1;
        
        if( is3(y)&&is5(y) )h=1;
        
        if( is11(y)&&is5(y) &&l)b=1;
        
        
        
        if(!l&&!h&&!b)
            cout<<"This is an ordinary year.\n";
        
        else
        {
            if(l)
                cout<<"This is leap year.\n";
            if(h)
                cout<<"This is huluculu festival year.\n";
            if(b)
                cout<<"This is bulukulu festival year.\n";
        }
    }
    return 0;
}
