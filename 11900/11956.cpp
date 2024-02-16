#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t=0 ; t<T; t++)
    {
        unsigned char LED[100+10]={0};
        
        string cmd;
        cin>>cmd;
        int cur=0;
        int len=cmd.size();
        for(int i=0 ; i<len ; i++)
        {
            if(cmd[i]=='>')
                cur++;
            else if(cmd[i]=='<')
                cur--;
            else if(cmd[i]=='+')
                LED[cur]++;
            else if(cmd[i]=='-')
                LED[cur]--;
            
            cur=(cur+100)%100;
        }
        
        cout<<"Case "<<t+1<<":";
        for(int i=0 ; i<100 ; i++)
            printf(" %02X", LED[i]);
        cout<<"\n";
    }
    return 0;
}
