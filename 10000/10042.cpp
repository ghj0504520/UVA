#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool c[65536] = {0};

int digitSum(long long q)
{
    int sum=0;
    while(q)
    {
        int d =q%10;
        sum+=d;
        q/=10;
    }
    return sum;
}
int main()
{
    c[0] = 1;
    c[1] = 1;
    
    for(long long j= 4 ; j<65536 ; j+=2)
    {
        c[j]=1;
    }
    for(long long i=3 ; i<65536 ; i+=2)
    {
        if(!c[i])
        {
            for(long long j= (i+i) ; j<65536 ; j+=i)
            {
                c[j]=1;
            }
        }   
    }
    
    int T;
    cin>>T;
    while(T--)
    {
        long long q;
        cin>>q;
        
        int ans=q+1;
        while(1)
        {
            int left,right=0;

            int tmp=ans;
            for(int i=2 ; i<65536 ; i++)
            {
                if(!c[i]&&i!=ans)
                {
                    while(tmp%i==0)
                    {
                        right+=digitSum(i);
                        tmp/=i;
                    }
                }
                
                if(tmp==1)break;
            }
            
            if(tmp!=ans)
            {
                if(tmp!=1)
                {
                    right+=digitSum(tmp);
                }
                left=digitSum(ans);

                if(left==right)break;
            }
            ans++;
        }cout<<ans<<"\n";
        
    }
    
    return 0;
}
