#include<iostream>

using namespace std;

int main()
{
    int fib[45];
    fib[0]=1;
    fib[1]=2;
    for(int i=2;i<45;i++)                 //DP
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int num;
            cin>>num;
            int printFlag=0;
            cout<<num<<" = ";
            for(int i=40;i>=0;i--)
            {
                if(num/fib[i]==1)
                {
                    cout<<'1';
                    num-=fib[i];
                    printFlag=1;
                }
                else 
                {
                    if(printFlag)
                        cout<<'0';
                }
                
            }cout<<" (fib)\n";
        }
    }
}
