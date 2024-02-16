#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int B[10000+10]={0};
    int L,H,R;
    int Lm=1,Rm=0;
    while(cin>>L>>H>>R)
    {
        for(int i=L;i<R;i++)
        {
            if(H>B[i])B[i]=H;
            if(R>Rm)Rm=R;
        }
    }
    int t=0;
    for(int i=Lm;i<=Rm;i++)
    {
        if(B[i]!=B[i-1])
        {
            if(t)cout<<" ";
            t=1;
            cout<<i<<" "<<B[i];
        }
    }cout<<"\n";
    return 0;
}
