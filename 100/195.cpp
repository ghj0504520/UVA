#include<iostream>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;

bool cmp(const char &i,const char &j)
{
    return (tolower(i) < tolower(j) )||( tolower(i)==tolower(j) &&i<j);
}

int main()
{
   int n;
   cin>>n;
   
        while(n--)
        {
           char in[1000];
           cin>>in;
           int len=strlen(in);
           sort(in,in+len,cmp);
           cout<<in<<'\n';
           while(next_permutation(in,in+len,cmp))
           {
               cout<<in<<'\n';
           }
       }
   
}
