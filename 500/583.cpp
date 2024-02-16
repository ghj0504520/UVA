#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    bool c[65536] = {0};
    c[0] = 1;
    c[1] = 1;
    
    for(int j= 4 ; j<65536 ; j+=2)
    {
        c[j]=1;
    }
    for(int i=3 ; i<65536 ; i+=2)
    {
        if(!c[i])
            for(int j= (i+i) ; j<65536 ; j+=i)
            {
                c[j]=1;
            }
    }
    
    int q;
    while(cin>>q)
    {
        if(!q)break;
        cout<<q<<" = ";
        bool t=0;
        if(q<0)
        {
            cout<<"-1";
            t=1;
            q*=-1;
        }
        
        for(int i=2 ; i<65536 ; i++)
        {
            if(!c[i])
            {
                while(q%i==0)
                {
                    if(t)cout<<" x ";
                    cout<<i;
                    t=1;
                    q/=i;
                }
            }
            
            if(q==1)break;
        }
        
        if(q!=1)
        {
            if(t)cout<<" x ";
            cout<<q;
        }
        
        cout<<"\n";
        
    }
    return 0;
}
