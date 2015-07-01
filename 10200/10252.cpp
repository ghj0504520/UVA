#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void back(int m,int n);                   //print function

int record[1010][1010];                   //record direction
string c,d;

int main()
{
    string a,b;
    while(getline(cin,a))                 //be careful input
    {
        getline(cin,b);
        c="\0";
        d="\0";
        c+="0";
        d+="0";
        c+=a;
        d+=b;
        int dp[1010][1010];
        memset(dp,0,sizeof(dp));
        memset(record,0,sizeof(record));
        int l_c=c.length(),l_d=d.length();
        sort(c.begin()+1,c.end());
        sort(d.begin()+1,d.end());
        for(int i=1;i<l_c;i++)             //similar to LCS
        {
            for(int j=1;j<l_d;j++)
            {
                if(c[i]==d[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    record[i][j]=3;
                }
                else 
                {
                    if(dp[i-1][j]>=dp[i][j-1])
                    {
                        dp[i][j]=dp[i-1][j];
                        record[i][j]=2;
                    }
                    else if(dp[i-1][j]<dp[i][j-1])
                    {
                        dp[i][j]=dp[i][j-1];
                        record[i][j]=1;
                    }
                }
                
               
            }
        }
        back(l_c-1,l_d-1);
        cout<<'\n';
    }
}

void back(int m,int n)                    //print function by backtrack
{
    if(record[m][n]==0)
        return;
    else 
    {
        if(record[m][n]==3)
        {
            back(m-1,n-1);
            cout<<c[m];
        }
        else if(record[m][n]==1)
        {
            back(m,n-1);
        }
        else if(record[m][n]==2)
        {
            back(m-1,n);
        }
        
    }
}
