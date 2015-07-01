#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        for(int i=1;i<=t;i++)
        {
            cout<<"Case "<<i<<": "; 
            char data[2000];
            cin>>data;
            int len=strlen(data);
            for(int j=0;j<len;j++)
            {
                if(data[j]>='A' &&data[j]<='Z')
                {
                    int t=j+1,sum=0;
                    while(data[t]>='0' &&data[t]<='9')
                    {
                        
                        sum=sum*10+(int)(data[t]-'0');
                        t++;
                        
                    }
                    for(int k=0;k<sum;k++)
                        printf("%c",data[j]);
                }
            }cout<<endl;
        }
    }
}
