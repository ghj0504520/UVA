#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char num_1[1000],num_2[1000];
    while(cin>>num_1)
    {
        cin>>num_2;
        
        int count_1[1000],count_2[1000];
        int len_1=strlen(num_1),len_2=strlen(num_2);
    
        for(int i=0;i<len_1;i++) //char letter change int number
        {
            count_1[i]=num_1[len_1-i-1]-48;
        }
        for(int i=0;i<len_2;i++)
        {
            count_2[i]=num_2[len_2-i-1]-48;
        }
            
        int count_f[1000];
        for(int i=0;i<1000;i++)  //initialize 
            count_f[i]=0;
        
        for(int i=0;i<len_1;i++)  //big num count
        {
            for(int j=0;j<len_2;j++)
            {
                count_f[i+j]+=count_1[i]*count_2[j];
            }
        }
        int len=len_1+len_2;
        
        for(int i=0;i<len;i++)  // decimal
        {
            if(count_f[i]>=10)
            {
                while(count_f[i]>=10)
                {
                    count_f[i+1]+=count_f[i]/10;
                    count_f[i]%=10;
                }
            }
        }
        int l=1000-1;
        while(count_f[l]==0) //find not zero
        {
            if(l==0)
                break;
            l--;
        }
        for(int i=0;i<=l;i++) //output
        {
            cout<<count_f[l-i];
        }cout<<'\n';
        
    }
}
