#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    string test;
    int t;
    
    while(cin>>test)
    {
        cout<<"Case "<<++t<<":\n";
        
        int len=test.size();
        int dp[1000000+10]={0},cnt=0;
        for(int i=1 ; i<len ; i++)
        {
            if(test[i]!=test[i-1])
                cnt++;
            dp[i]=cnt;
        }
        
        int n;
        cin>>n;
        int a,b;
        for(int i=0 ; i<n ; i++)
        {
            cin>>a>>b;
            if(dp[a]==dp[b])cout<<"Yes";
            else cout<<"No";
            cout<<"\n";
        }
    }
    return 0;
}
