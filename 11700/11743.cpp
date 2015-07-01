#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            string card[4];
            for(int i=0;i<4;i++)
            {
                cin>>card[i];
            }
            int first=0,second=0;
            for(int i=0;i<4;i++)
            {
                for(int j=1;j<4;j+=2)
                {
                    second+=card[i][j]-'0';
                }
            }
            int count ;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j+=2)
                {
                    count=card[i][j]-'0';
                    count*=2;
                    if(count>=10)
                    {
                        int div;
                        div=(int)count/10;
                        count%=10;
                        count+=div;
                    }
                    
                    first+=count;
                }
            }
            (first+second)%10==0? cout<<"Valid\n":cout<<"Invalid\n";
            
            
        }
    }
}
