#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace  std;

void deal_string(string in,char out[]);
int  main(int argc, char const *argv[])
{
    int num;
    cin>>num;
    getchar();
    for(int i=0;i<num;i++)
    {
        string data1,data2;
        getline(cin,data1);
        getline(cin,data2);
        if(data1==data2)
        {
            cout<<"Case "<<i+1<<": Yes\n";
        }
        else 
        {
            char data1Deal[30],data2Deal[30];
            deal_string(data1,data1Deal);
            deal_string(data2,data2Deal);
            if(!strcmp(data1Deal,data2Deal))
            {
                cout<<"Case "<<i+1<<": Output Format Error\n";
            }
            else 
            {
                cout<<"Case "<<i+1<<": Wrong Answer\n";
            }
        }
    }
	return 0;
}

void deal_string(string in,char out[])
{
    int len=in.length(),flag=0;
    for(int i=0;i<len;i++)
    {
        if(isalpha(in[i]))
        {
            out[flag]=in[i];
            flag++;
        }
    }out[flag]='\0';
}
