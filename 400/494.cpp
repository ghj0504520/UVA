#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string a;
    while(getline(cin,a))
    {
        int len=a.length();
        int word=0;
        for(int i=0;i<len;i++)  //careful
        {
            if((a[i]>='A' &&a[i]<='Z') ||(a[i]>='a' &&a[i]<='z'))
            {
               if(a[i+1]<'A')
               {
                   word++;
               }
               else if(a[i+1]>'Z'&&a[i+1]<'a')
               {
                   word++;
               }
               else if(a[i+1]>'z')
               {
                   word++;
               }
                
            }
        }cout<<word<<'\n';
        
    }
}
