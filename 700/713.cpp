#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string a,b;
        cin>>a>>b;
        int A[250]={0},B[250]={0};
        int la=a.size(),lb=b.size();
        
        for(int i=0 ; i<la ; i++)
        {
            A[i]=a[i]-'0';
        }
        for(int i=0 ; i<lb ; i++)
        {
            B[i]=b[i]-'0';
        }
        
        int len= la>lb?la:lb;
        int C[250]={0};
        for(int i=0 ; i<len ; i++)
        {
            C[i]=A[i]+B[i];
        }
        
        int over=0;
        for(int i=0 ; i<len ; i++)
        {
            if(C[i]>9)
            {
                if(i==len-1)over=1;
                C[i+1]++;
                C[i]%=10;
            }
        }
        if(over)len++;
        
        int preZ=1;
        for(int i=0 ; i<len ; i++)
        {
            if(!C[i]&&!preZ)cout<<C[i];
            
            else if(C[i]){
                preZ=0;
                cout<<C[i];
            }
        }cout<<"\n";
    }
    return 0;
}
