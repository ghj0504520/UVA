#include<iostream>
using namespace std;

int main()
{
    int t=0;
    string in;
    while(cin>>in)
    {
        if(in=="end")break;
        cout<<"Case "<<++t<<": ";

        int LIS[1200]={0};
        int len = in.size();
        for(int i=0 ; i<len ; i++)
            LIS[i]=1;
        int ans=-1;
        for(int i=0 ; i<len ; i++)
        {
            for(int j=i+1 ; j<len ; j++)
            {
                if(in[i]<in[j])
                    LIS[j] = max(LIS[i]+1,LIS[j]);
                
            }
            if(ans<LIS[i])
                ans=LIS[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}