#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
struct charactor
{
    char a;
    int n;
};
bool cmp(const charactor &i , const charactor &j)
{
    return i.n>j.n || (i.n==j.n && i.a<j.a);
}
int main()
{
    int num;
    while(cin>>num)
    {
        getchar();
        string read[num];
        for(int i=0;i<num;i++) //I&O
        {
            getline(cin,read[i],'\n');
        }
        charactor read_in[26];
        int len[num];
        for(int i=0;i<26;i++) //initalize
        {
            read_in[i].a=' ';
            read_in[i].n=0;
        }
        for(int i=0;i<num;i++) //count length
        {
            len[i]=read[i].length();
        }
        for(int i=0;i<num;i++) //small change big
        {
            for(int j=0;j<len[i];j++)
            {
                if(read[i][j]>=97 && read[i][j]<=122 )
                    read[i][j]=read[i][j]-32;
            }
        }
        for(int i=0;i<26;i++) //write in letter
        {
            read_in[i].a=65+i;
        }
        for(int i=0;i<num;i++) //count time
        {
            for(int j=0;j<len[i];j++)
            {
                if(read[i][j]>=65 && read[i][j]<=90)
                    read_in[(int)read[i][j]-65].n++;
            }
        }
        sort(read_in,read_in+26,cmp);
        
        for(int i=0;i<26;i++) //output
        {
            if(read_in[i].n!=0)
                cout<<read_in[i].a<<' '<<read_in[i].n<<'\n';
        }
        
    }
}
