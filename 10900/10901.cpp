#include <iostream>
#include <queue>
using namespace std;

struct car
{
    int ID,time;
    car(int id,int t)
    {ID=id;time=t;}
};

int main()
{
    int r;
    cin>>r;
    while(r--)
    {
        int n,t,m;
        cin>>n>>t>>m;
        queue<car> L[2];

        int id=0;
        while(m--)
        {
            int time;
            string side;
            cin>> time>> side;
            if(side=="left")
                L[0].push(car(id,time));
            else L[1].push(car(id,time));
            id++;
        }

        int time =0,closeTime=0;
        int side =0;
        int ans[10000]={0};
        while(!L[0].empty()||!L[1].empty())
        {
            if (L[0].empty()) 
                closeTime = L[1].front().time;
			else if (L[1].empty())
                closeTime = L[0].front().time;
			else closeTime = min(L[1].front().time, L[0].front().time);

			time = max(time, closeTime);

            int cnt=0;
            while(!L[side].empty()&& cnt<n&& L[side].front().time<=time)
            {
                //cout<<time + t<<"\n";
                ans[ L[side].front().ID ] = time + t;
                L[side].pop();
                ++cnt;
            }
            time+=t;
            side^=1;
        }
        for(int i=0 ; i<id ; i++)cout<<ans[i]<<"\n";
        if(r)cout<<"\n";
    }
    return 0;
}