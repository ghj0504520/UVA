#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T,t=0;
    cin>>T;
    int DB[10000+10][2]={0};
    while(T--)
    {
        if(t++)cout<<"\n";
        int F,Q;
        cin>>F;
        string fn;
        map<string,int>name;
        map<int,string>rname;
        for(int i=0 ; i<F ; i++)
        {
            cin>>fn;
            name[fn]=i;
            rname[i]=fn;
            int L,H;
            cin>>L>>H;
            DB[name[fn]][0]=L;
            DB[name[fn]][1]=H;
        }
        
        cin>>Q;
        int q;
        for(int i=0 ; i<Q ; i++)
        {
            cin>>q;
            int cnt=0,ans;
            for(int j=0 ; j<F ; j++)
            {
                if(DB[j][0]<=q&&DB[j][1]>=q)
                {
                    cnt++;
                    ans=j;
                    
                }
                
                if(cnt>1)
                    break;
            }
            
            if(cnt==1)cout<<rname[ans]<<"\n";
            else cout<<"UNDETERMINED\n";
        }
    }
    return 0;
}
