#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool c[20000000] = {0};

int main()
{
    
    vector<int> twin;
    c[0] = 1;
    c[1] = 1;
    
    for(long long j= 4 ; j<20000000 ; j+=2)
    {
        c[j]=1;
    }
    for(long long i=3 ; i<20000000 ; i+=2)
    {
        if(!c[i])
        {
            for(long long j= (i+i) ; j<20000000 ; j+=i)
            {
                c[j]=1;
            }
            if(!c[i]&&!c[i-2])
                twin.push_back(i-2);
        }   
    }
    
    int q;
    while(cin>>q)
    {
        cout<<"("<<twin[q-1]<<", "<<twin[q-1]+2<<")\n";
    }
    
    return 0;
}
