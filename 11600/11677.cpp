#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int h1,m1,h2,m2;
    while(cin>>h1>>m1>>h2>>m2)
    {
        if(!h1&&!m1&&!h2&&!m2)break;
        
        m1+=h1*60;
        m2+=h2*60;
        
        m2=m2-m1;
        if(m2<0)
            m2+=1440;
        cout<<m2<<"\n";
    }   
    return 0;
}
