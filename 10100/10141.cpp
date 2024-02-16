#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,p,T=0;
    
    while(cin>>n>>p)
    {
        if(!n&&!p)break;
        getchar();        
        string tmp;
        for(int i=0 ; i <n ; i++)
        {
            getline(cin,tmp);
        }
        
        string tmpn, ansn, obn;
        double tmpp, ansp;
        int tmpc, ansc=0;
        
        for(int i=0 ; i <p ; i++)
        {
            getline(cin,tmpn);
            cin>>tmpp>>tmpc;
            getchar();
            for(int j=0 ; j <tmpc ; j++)
            {
                getline(cin,obn);                
            }
            if(tmpc>ansc)
            {
                ansn=tmpn;
                ansp=tmpp;
                ansc=tmpc;
            }else if(tmpc==ansc&&tmpp<ansp)
            {
                ansn=tmpn;
                ansp=tmpp;
                ansc=tmpc;
            }
        }
        if(T)cout<<"\n";
        cout<<"RFP #"<<++T<<"\n"<<ansn<<"\n";
    }
    return 0;
}
