#include<iostream>
using namespace std;

void base_three(int number);

int main()
{
    int numChange;
    while(cin>>numChange)
    {
        if(numChange < 0)
            break;
        else if(numChange==0)
            cout<<0;
        else
            base_three(numChange);
        cout<<'\n';
    }
}

void base_three(int number)
{
    int r;
    if(number !=0)
    {
        r=number%3;
        base_three(number/3);
        cout<<r;
    }
    
}
