#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, s=0;
    cin>>n;
    while(n--)
    {
        double l,w,d,k;
        cin>>l>>w>>d>>k;
        int tmp=0;
        if(((l<=56.00&&w<=45.00&&d<=25.00)||
        (l+w+d)<=125.00)&&k<=7.00)
            tmp=1;
        cout<<tmp<<"\n";
        s+=tmp;
    }cout<<s<<"\n";
    return 0;
}
