#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
    char read_1[1010],read_2[1010];
    int run_time=0;
    while(cin.getline(read_1,1010,'\n'))   // Input
    {
        run_time++;
        cin.getline(read_2,1010,'\n');
        int l_1=strlen(read_1),l_2=strlen(read_2);
        string ans_1[1010],ans_2[1010];
        
        string a,b;
        int t_1=1;
        if(read_1[0]=='\0' || read_2[0]=='\0')
        { 
            printf("%2d",run_time);
            cout<<". Blank!\n";
            continue;
        }   
        for(int i=0;i<l_1;i++)
        {
            if((read_1[i]>='a' && read_1[i]<='z') || (read_1[i]>='A' && read_1[i]<='Z') ||(read_1[i]>='0' && read_1[i]<='9'))
            {
                a+=read_1[i];
            }
            
            else 
            {
                ans_1[t_1]=a;
                t_1++;
                a.clear();
            }
            
            if(i==(l_1)-1)
            {
                ans_1[t_1]=a;
                t_1++;
                a.clear();
            }
            
        }
        /*
        for(int i=0;i<=t_1;i++)  //debug
            cout<<ans_1[i]<<' ';
        */
        int t_2=1;
        for(int i=0;i<l_2;i++)
        {
            if((read_2[i]>='a' && read_2[i]<='z') || (read_2[i]>='A' && read_2[i]<='Z') ||(read_2[i]>='0' && read_2[i]<='9'))
            {
                b+=read_2[i];
            }
            
            else 
            {
                ans_2[t_2]=b;
                t_2++;
                b.clear();
            }
            
            if(i==(l_2)-1)
            {
                ans_2[t_2]=b;
                t_2++;
                b.clear();
            }
        }
        /*
        for(int i=0;i<=t_2;i++)  //debug
            cout<<ans_2[i]<<' ';
        */
        
        
        int dp[1010][1010];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=t_1;i++)
        {
            for(int j=1;j<=t_2;j++)
            {
                if(ans_1[i]==ans_2[j]&&ans_1[i]!="\0")
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
               // cout<<dp[i][j]<<' ';
                
            }//cout<<'\n';
        }
        printf("%2d",run_time);  //Output
        cout<<". Length of longest match: "<<dp[t_1-1][t_2-1]<<'\n';
        
    }
 
    
}
