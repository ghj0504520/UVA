#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    long long int n ,m ,c,t=0;
    while(cin>>n>>m>>c)
    {
        if(n==0 &&m==n &&c==n)
            break;
        //if(t!=0)
          //  cout<<endl;
        t++;
        cout<<"Sequence "<<t<<'\n';
        long long int electron[n+1],cmd[m];
        for(long long int i=1;i<=n;i++)
        {
            cin>>electron[i];
        }
        for(long long int i=0;i<m;i++)
        {
            cin>>cmd[i];
        }
        long long int sum=0,big=0;
        bool judge[n+1],burn=0;
        memset(judge,0,sizeof(judge));
        for(long long int i=0;i<m;i++)
        {
            judge[cmd[i]]==0? judge[cmd[i]]=1 :judge[cmd[i]]=0;
            if(judge[cmd[i]]==1)
            {
                sum+=electron[cmd[i]];
                if(sum>big)
                {
                    big=sum;
                }
                if(sum>c)       //do not use "="
                {
                    burn=1;
                    break;
                }
                
            }
            else if(judge[cmd[i]]==0)
            {
                sum-=electron[cmd[i]];
            }
        }
        burn==1? cout<<"Fuse was blown.\n\n":cout<<"Fuse was not blown.\nMaximal power consumption was "<<big<<" amperes.\n\n";
        
        
        
    }
}
