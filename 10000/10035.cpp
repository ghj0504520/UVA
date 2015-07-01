#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char a[50],b[50];
    
    while(cin>>a>>b)
    {
        if((a[0]=='0' && a[1]=='\0')&&(b[0]=='0' && b[1]=='\0'))
            break;
        int  a_len=strlen(a),b_len=strlen(b);
        int save_a[50],save_b[50];
        memset(save_a,0,sizeof(save_a));
        memset(save_b,0,sizeof(save_b));
        int c=0,d=0;
        for(int i=a_len-1;i>=0;i--)
        {
            save_a[c]=a[i]-'0';
            c++;
        }
        for(int i=b_len-1;i>=0;i--)
        {
            save_b[d]=b[i]-'0';
            d++;
        }
        int len=max(a_len,b_len);
        for(int i=0;i<=len;i++)
        {
            save_a[i]+=save_b[i];
        }
        int t=0;
        for(int i=0;i<=len;i++)
        {
            while(save_a[i]>=10)
            {
                t++;
                int dir=save_a[i]/10;
                save_a[i]%=10;
                save_a[i+1]+=dir;
            }
        }
        if(t==0)
            cout<<"No carry operation.";
        else
        {
            if(t!=1)
                cout<<t<<" carry operations.";
            else if(t==1)
                cout<<t<<" carry operation.";
        }
        cout<<endl;
    }
}
