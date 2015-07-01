#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int t[3];
            for(int i=0;i<3;i++)
            {
                cin>>t[i];
            }
            sort(t,t+3);
            t[0]+t[1]<=t[2]?cout<<"Wrong!!":cout<<"OK";
            cout<<'\n';
        }
    }
}
