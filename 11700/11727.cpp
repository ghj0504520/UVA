#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t_ime,t=0;
    while(cin>>t_ime)
    {
        while(t_ime--)
        {
            t++;
            int employee[3];
            cin>>employee[0]>>employee[1]>>employee[2];
            sort(employee,employee+3);
            cout<<"Case "<<t<<": "<<employee[1]<<'\n';
        }
    }
    return 0;
}
