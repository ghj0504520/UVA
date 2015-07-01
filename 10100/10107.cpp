#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int read;
    int num[100000];
    int now=1;
    while(cin>>read)
    {
        num[now]=read;
        sort(num+1,num+now+1);
        if(now%2!=0)
            cout<<num[(now+1)/2];
        else if(now%2==0)
        {
            
            cout<<(num[now/2]+num[(now/2)+1])/2;
        }
        //for(int i=1;i<=now;i++)cout<<num[i];
        //cout<<now;
        cout<<'\n';
        now++;
    }
}
