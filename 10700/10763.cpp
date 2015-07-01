#include<iostream>
#include<algorithm>
using namespace std;
struct data
{
    int s,f;
};
bool cmp(const data &i,const data &j)
{
    return i.s<j.s || (i.s==j.s && i.f<j.f);
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        data p[n];
        for(int i=0;i<n;i++)
        {
            cin>>p[i].s>>p[i].f;
        }
        for(int i=0;i<n;i++)
        {
            if(p[i].s>p[i].f)
            {
                int swap=p[i].s;
                p[i].s=p[i].f;
                p[i].f=swap;
            }
        }
        sort(p,p+n,cmp);
        bool judge=1;
        for(int i=0;i<n;i+=2)  //figure
        {
            
            if(p[i].s!=p[i+1].s)
            {
                judge=0;
                break;
            }
            if(p[i].f!=p[i+1].f)
            {
                judge=0;
                break;
            }
        }
        
        judge==1? cout<<"YES\n":cout<<"NO\n";
    }
    
}
