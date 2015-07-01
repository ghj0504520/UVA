#include<iostream>
#include<cstring>

using namespace std;

int count(int num);

int main()
{
    string data;
    while(cin>>data)
    {
        if(data=="END")
            break;
        int t=1;
        int len=data.length();
        while(len!=count(len) )
        {
            t++;
            len=count(len);
        }
        if(data[0]=='1'&&data[1]=='\0')
            cout<<t<<'\n';
        else
            cout<<t+1<<'\n';
        
    }
    return 0;
}

int count(int num)
{
    int sum=0;
    while(num)
    {
        num/=10;
        sum++;
    }
    return sum;
}
