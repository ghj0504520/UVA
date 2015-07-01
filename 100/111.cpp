#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

int LCS(int data[],int check[],int len);

int main()
{
    int num;
    cin>>num;
    int input[num];
    int correct[num+1];
    for(int i=0;i<num;i++)
    {
        cin>>input[i];
    }
    for(int i=0;i<num;i++)
    {
        correct[input[i]]=i+1;
    }
    correct[0]=0;
    int test[num],test_correct[num+1];
    
    while(cin>>test[0])
    {
        for(int i=1;i<num;i++)
            cin>>test[i];
        for(int i=0;i<num;i++)
        {
            test_correct[test[i]]=i+1;
        }
        test_correct[0]=0;
        cout<<LCS(correct,test_correct,num)<<'\n';
    }
    return 0;
}

int LCS(int data[],int check[],int len)
{
    int dp[len+1][len+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=len;j++)
        {
            if(data[i]==check[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
	return dp[len][len];
}
