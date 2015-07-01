#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int LCS(string data_1,string data_2,int len_1,int len_2);

int main()
{
    string data1,data2;
    int t=0;
    while(getline(cin,data1))              //careful input
    {
        t++;
        if(data1=="#")
            break;
        getline(cin,data2);
        int len1=data1.length(),len2=data2.length();
        cout<<"Case #"<<t<<": you can visit at most "<<LCS(data1,data2,len1,len2)<<" cities.\n";
    }
    return 0;
}

int LCS(string data_1,string data_2,int len_1,int len_2)
{
    int dp[len_1+1][len_2+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=len_1;i++)
    {
        for(int j=1;j<=len_2;j++)              
        {                                     
            if(data_1[i-1]==data_2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[len_1][len_2];
}
