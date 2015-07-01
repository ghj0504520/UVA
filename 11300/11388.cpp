#include<iostream>
using namespace std;
int main()
{
    int testNum;
    while(cin>>testNum)
    {
        while(testNum--)
        {
            int a,b;
            cin>>a>>b;
            if(b % a)
                cout<<-1<<'\n';
            else 
                cout<<a<<' '<<b<<'\n';
        }
    }
}
