#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int q;
    while(cin>>q)
    {
        int i=1,sum=0;
        
        while(sum+i<q)
        {
            sum+=i;
            i++;
        }
        int idx=i+1, up, down;
        
        up = (idx%2==1?1+q-sum-1:idx-q+sum);
        down = (idx%2==0?1+q-sum-1:idx-q+sum);
        
        cout<<"TERM "<<q<<" IS "<<up<<"/"<<down<<"\n";
    }    
    return 0;
}
