#include<iostream>
using namespace std;

long long int f_91(long long int input);

int main()
{
    long long int inputNum;
    while(cin>>inputNum)
    {
        if(inputNum == 0)
            break;
        cout<<"f91("<<inputNum<<") = ";
        cout<<f_91(inputNum);
        cout<<'\n';
    }
    return 0;
}

long long int f_91(long long int input)
{
    if(input>100)
        return input - 10;
    else
        return f_91(f_91(input+11));
}
