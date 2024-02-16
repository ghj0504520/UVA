#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int r,c;
    while(cin>>r>>c)
    {
        int MAP[10+10][100+10]={0};
        int DP[10+10][100+10]={0};
        int path[10+10][100+10]={0};
        
        for(int i=0 ; i<r ; i++)
            for(int j=0 ; j<c ; j++)
                cin>>MAP[i][j];
        int u,m,d,Min;
        for(int j=c-1 ; j>=0 ; j--)
        {
            for(int i=0 ; i<r ; i++)
            {
                u=DP[(i-1+r)%r][j+1];
                m=DP[i][j+1];
                d=DP[(i+1)%r][j+1];
                Min =min(u,min(m,d));
                
                DP[i][j]=Min+MAP[i][j];
                path[i][j]=1e9;
                
                if(Min==u)
                {
                    path[i][j]=(i-1+r)%r;
                }
                if(Min==m)
                {
                    path[i][j]=min(path[i][j],i);
                }
                if(Min==d)
                {
                    path[i][j]=min(path[i][j],(i+1)%r);
                }
            }
        }
        
        int ans=1e9, routeRow;
        for(int i=0 ; i<r ; i++)
        {
            if(ans>DP[i][0])
                ans=DP[i][0],routeRow=i;
        }
        
        for(int j=0 ; j<c ; j++)
        {
            if(j)cout<<" ";
            cout<<routeRow+1;
            routeRow=path[routeRow][j];
        }
        cout<<"\n"<<ans<<"\n";
    }
    return 0;
}
