#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    getchar();
    while(T--)
    {
        string in;
        getline(cin,in);
        
        stringstream buf(in);
        
        int val[20+5]={0}, it=0, v, sum=0;
        while(buf>>v)
        {
            val[it]=v;
            sum+=v;
            it++;
        }
        
        if(sum%2)
        {
            cout<<"NO\n";
            continue;
        }   
        
        bool dp[200+10]={0};
        dp[0]=1;
        for(int i=0 ; i < it ; i++)
        {
            for(int j = sum ; j >= val[i] ; j-- )
            {
                dp[j] |= dp[j - val[i]];
            }
        }
        
        cout<<(dp[sum/2]?"YES":"NO")<<"\n";
    }
    return 0;
}
