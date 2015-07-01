#include<iostream>
#include<cstring>
using namespace std;

int square(int k);

int main()
{
    int t;
    while(cin>>t)
    {
        for(int i=1;i<=t;i++)
        {
            bool judge[2000];
            memset(judge,0,sizeof(judge));
            int ask,save;
            cin>>ask;
            save=ask;
            bool j=1;
            do
            {
                ask=square(ask);
                if(judge[ask]==1)
                {
                    j=0;
                    break;
                }
                else 
                {
                    judge[ask]=1;
                }
            }while(ask!=1);
            cout<<"Case #"<<i<<": "<<save<<" is "; 
            j==1? cout<<"a Happy" : cout<<"an Unhappy";
            cout<<" number.\n";
        }
    }
}

int square(int k)
{
    int s,q=0;
    while(k!=0)
    {
        s=k%10;
        q+=s*s;
        k=(int)k/10;
    }
    return q;
}
