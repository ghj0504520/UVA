#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void LCS(int dp[200][200],int direct[200][200],int l_1,int l_2,string data_1[],string data_2[]);
void backtrack(int direct[200][200],int l_1,int l_2,string data_1[],string ans[],int ans_it);

int main()
{
    string read1;
    int dp[200][200],direct[200][200];
    while(cin>>read1)
    {
        memset(dp,0,sizeof(dp));
        memset(direct,0,sizeof(direct));
        if(read1=="#")
            break;
        string data1[200];
        int len1=2;
        data1[0]="0";
        data1[1]=read1;
        while(cin>>read1)
        {
            if(read1=="#")
                break;
            data1[len1]=read1;
            len1++;
        }
        
        string read2,data2[200];
        int len2=1;
        data2[0]="0";
        while(cin>>read2)
        {
            if(read2=="#")
                break;
            data2[len2]=read2;
            len2++;
        }
        len1--;
        len2--;
        string ans[200];
        LCS(dp,direct,len1,len2,data1,data2);
        backtrack(direct,len1,len2,data1,ans,0);
        for(int i=dp[len1][len2]-1;i>=0;i--)
        {
            cout<<ans[i];
            if(i>0)
                cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}

void LCS(int dp[200][200],int direct[200][200],int l_1,int l_2,string data_1[],string data_2[])
{
    for(int i=1;i<=l_1;i++)
    {
        for(int j=1;j<=l_2;j++)
        {
            if(data_1[i]==data_2[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                direct[i][j]=3;
            }
            else 
            {
                if(dp[i-1][j]>=dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    direct[i][j]=1;
                }
                else if(dp[i-1][j]<dp[i][j-1])
                {
                    dp[i][j]=dp[i][j-1];
                    direct[i][j]=2;
                }
            }
        }
    }
}

void backtrack(int direct[200][200],int l_1,int l_2,string data_1[],string ans[],int ans_it)
{
    if(l_1==l_2&&l_1==0)
        return ;
    else
    {
        if(direct[l_1][l_2]==3)
        {
            ans[ans_it]=data_1[l_1];
            ans_it++;
            backtrack(direct,l_1-1,l_2-1,data_1,ans,ans_it);
        }
        else 
        {
            if(direct[l_1][l_2]==1)
            {
                backtrack(direct,l_1-1,l_2,data_1,ans,ans_it);
            }
            else if(direct[l_1][l_2]==2)
            {
                backtrack(direct,l_1,l_2-1,data_1,ans,ans_it);
            }
        }
    }
}
