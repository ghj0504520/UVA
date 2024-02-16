#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int t=0 ; t<n ; t++)
    {
        int N,K,P;
        cin>>N>>K>>P;
        int ans=(K+P)%N;
        ans = (!ans?N:ans);
        cout<<"Case "<<t+1<<": "<<ans<<"\n";
    }
    return 0;
}
