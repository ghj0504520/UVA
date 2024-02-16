#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    double H,U,D,F;
    while(cin>>H>>U>>D>>F)
    {
        if (!H)break;
        
        double minus=(double)U*F/100;
        double path=0.0;
        int d=0;
        while(1)
        {
            d++;
            if(path<=0.0&&d>1)break;

            path+=U;//cout<<path<<"#";
            if(path>H)break;
            
            
            path-=D;
            
            U-=minus;
            if(U<=0.0)U=0.0; 
        }
        
        if(path>H)
            cout<<"success on day "<<d<<"\n";
        else if(path<0.0)
            cout<<"failure on day "<<d-1<<"\n";
        else if(path==0.0)
            cout<<"failure on day "<<d<<"\n";
    }
    return 0;
}
