#include<iostream>
using namespace std;

int sum_digit(long long input);

int main()
{
    long long inputNum;
    while(cin>>inputNum)
    {
        if(inputNum == 0)
            break;
        cout<<sum_digit(inputNum)<<'\n';
    }
    return 0;
}

int sum_digit(long long input)
{
    int sum = 0;
    do
    {
        sum += input % 10;
        input /= 10;
    }while(input > 0);
    if(sum >= 10)
        return sum_digit(sum);
    return sum;    
    
}
