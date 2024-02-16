#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int R,N,t=0;

    while(cin>>R>>N)
    {
        if(!R&&!N)break;
        int ans=((int)ceil((double)R/N))-1;
        
        cout<<"Case "<<t+1<<": ";
        
        if(ans<27)
            cout<<ans<<"\n";
        else cout<<"impossible\n";
        t++;
    }
    return 0;
}
