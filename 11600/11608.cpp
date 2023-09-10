#include <iostream>

using namespace std;

int main()
{
    int n,t=0;
    while(cin>>n)
    {
        if(n<0)break;

        int cur = n;
        int c[13],n[13];
        for(int i=0 ; i<12; i++)
            cin>>c[i];
        for(int i=0 ; i<12; i++)
            cin>>n[i];


        cout<<"Case "<<++t<<":\n";
        for(int i=0 ; i<12 ; i++)
        {
            cout<<"No problem";
            
            if(cur>=n[i])
            {
                cout<<"! :D";
                cur-=n[i];
            }else
            {
                cout<<". :(";
            }
            cur+=c[i];
            cout<<"\n";
        }
    }
    return 0;
}