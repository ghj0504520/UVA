#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t=0;
    int x,y;
    while(cin>>x>>y)
    {
        if(x==0 && y==0)
            break;
        if(t!=0)
            printf("\n");
        t++;
        printf("Field #%d:\n",t);
        char data[x][y];
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                cin>>data[i][j];
            }
        }
        int mine[x][y];
        memset(mine,0,sizeof(mine));
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(i-1>=0)
                {
                    if(data[i-1][j]=='*')
                        mine[i][j]++;
                }
                if(j-1>=0)
                {
                    if(data[i][j-1]=='*')
                        mine[i][j]++;
                }
                if(i+1<x)
                {
                    if(data[i+1][j]=='*')
                        mine[i][j]++;
                }
                if(j+1<y)
                {
                    if(data[i][j+1]=='*')
                        mine[i][j]++;
                }
                if(i-1>=0 && j-1>=0)
                {
                    if(data[i-1][j-1]=='*')
                        mine[i][j]++;
                }
                if(i-1>=0 && j+1<y)
                {
                    if(data[i-1][j+1]=='*')
                        mine[i][j]++;
                }
                if(i+1<x && j-1>=0)
                {
                    if(data[i+1][j-1]=='*')
                        mine[i][j]++;
                }
                if(i+1<x && j+1<y)
                {
                    if(data[i+1][j+1]=='*')
                        mine[i][j]++;
                }
                
            }
        }
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(data[i][j]=='*')
                    cout<<'*';
                else
                    cout<<mine[i][j];
            }cout<<'\n';
        }
    }
}
