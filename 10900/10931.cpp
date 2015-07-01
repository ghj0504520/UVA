#include<iostream>
using namespace std;

void base_two(int num);
int timeOne;

int main()
{
    int number;
    while(cin>>number)
    {
        timeOne = 0;
        if(number == 0)
            break;
        cout<<"The parity of ";
        base_two(number);
        cout<<" is "<<timeOne<<" (mod 2).\n";;
    }
}

void base_two(int number)
{
    int r;
    if(number !=0)
    {
        r = number % 2;
        if(r == 1)
            timeOne++;
        base_two(number/2);
        cout<<r;
    }
}
