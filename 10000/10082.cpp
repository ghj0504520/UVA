#include<iostream>
using namespace std;
int main()
{
    string data="1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    string input;
    
    while(getline(cin,input,'\n'))
    {
        int len_1=input.length(),len_2=data.length();
        for(int i=0;i<len_1;i++)
        {
            if(input[i]==' ')
            {
                cout<<input[i];
            }
            else
            {
                for(int j=0;j<len_2;j++)
                {
                    if(data[j]==input[i])
                    {
                        cout<<data[j-1];
                    }            
                }
            }
        }
        cout<<'\n';
    }
}
