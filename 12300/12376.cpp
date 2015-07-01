#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    int t_ime;
    while(scanf("%d",&t_ime)!=EOF)
    {
        for(int t=1;t<=t_ime;t++)
        {
            vector<int>relation[1000];
            cout<<"Case "<<t<<": ";
            int numPoint , numSide;
            scanf("%d%d",&numPoint,&numSide);
            
            int numWeight[numPoint];
            for(int i=0;i<numPoint ;i++)
                scanf("%d",&numWeight[i]);
                                
            int start,finally;
            for(int i=0;i<numSide;i++)
            {
                scanf("%d%d",&start,&finally);
                relation[start].push_back(finally);
            }
            int nowPoint=0,maxWeight=0;                                 //outside final answer
            while(!relation[nowPoint].empty())
            {
                int mswap=0,location;                                   //inside change the best answer
                int relationLen=relation[nowPoint].size();              //afraid of TLE
                for(int i=0;i<relationLen;i++)
                {
                    if(mswap < numWeight[relation[nowPoint][i]])
                    {
                        mswap=numWeight[relation[nowPoint][i]];
                        location=relation[nowPoint][i];
                    }
                }
                maxWeight+=mswap;
                nowPoint=location;
            }
            printf("%d %d\n",maxWeight,nowPoint);
        }
    }
    return 0;
}
