#include <cmath>
#include <iostream>
using namespace std;
bool self[1000000+10]={0};

int dsum(int n)
{
    int sum =0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main()
{
    for(int i=1 ; i<=1000000 ; i++)
    {
        int next = i+dsum(i);
        if(next<=1000000)
            self[next]=1;
        
        if(!self[i])
            cout<<i<<"\n";
    }
    return 0;
}
