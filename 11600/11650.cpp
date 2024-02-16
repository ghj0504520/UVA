#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string t;
        cin>>t;
        int h,m;
        sscanf(t.c_str(),"%d:%d", &h, &m);
        
        h=12-h;
        if(m)
            {m=60-m;h--;}
        if(h<=0)h+=12;
        
        printf("%02d:%02d\n",h,m);
    }
    return 0;
}
