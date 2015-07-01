#include<iostream>
using namespace std;
int main()
{
    int inputNum,t_ime=0;
    while(cin>>inputNum)
    {
        if(inputNum <= -1)             //bug when -2 -3 ......
            break;
        t_ime++;
        long long int exp_2 = 1,t=0;
        while(exp_2 < inputNum)
        {
            t++;
            exp_2 *= 2;
        }
        cout<<"Case "<<t_ime<<": "<<t<<'\n';
    }
    return 0;
}
