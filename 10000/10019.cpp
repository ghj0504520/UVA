#include<iostream>
#include<cstdio>

using namespace std;

int de_to_hex(int num);
int binary_count(int num);

int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int num_de;
            cin>>num_de;
            
            int b_1=binary_count(num_de);
            int b_2=binary_count(de_to_hex(num_de));
            cout<<b_1<<" "<<b_2<<'\n';
        }
    }
    return 0;
}

int de_to_hex(int num)
{
    int sum=0,power=1;
    while(num != 0)
    {
        sum += (num%10)*power;
        num /= 10;
        power *= 16;
    }
    return sum;
}

int binary_count(int num)
{
    int count=0;
    while(num != 0)
    {
        if(num % 2)
            count++;
        
        num/=2;
    }
    return count;
}
