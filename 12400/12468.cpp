#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[2];
    while(cin>>a[0]>>a[1])
    {
        if(a[0]==-1&&a[0]==a[1])
        {
            break;
        }
        sort(a,a+2);
        int first,second;
        first=a[1]-a[0];
        second=99-a[1]+a[0]-0+1;
        first=min(first,second);
        cout<<first<<'\n';
    }
}
