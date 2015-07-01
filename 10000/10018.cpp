#include<iostream>
using namespace std;

long long int reverse(long long int p);

int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            long long int n;                 //careful long long
            cin>>n;
            long long int t=0;
            long long int rever=reverse(n);
            do                               //need to plus first
            {
                t++;
                n+=rever;
                rever=reverse(n);
            }while(n!=rever);
            cout<<t<<" "<<n<<'\n';
            
        }
    }
}

long long int reverse(long long int p)
{
    long long int s;
    long long int r=0;
    while(p!=0)
    {
        r*=10;
        s=p%10;
        r+=s;
        p=(long long int)p/10;
    }
    return r;
}
