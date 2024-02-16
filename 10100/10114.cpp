#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int m,r;
    double p,l;
    while(cin>>m>>p>>l>>r)
    {
        if(m<0)break;
        
        double mr[110]={0};
        for(int i=0 ; i<r ; i++)
        {
            int tmp;
            double tmpf;
            scanf("%d%lf", &tmp, &tmpf);
            mr[tmp]=tmpf;
        }
        
        double total = l+p;
        double avg = l/m;
        double mrate=0;
        int M;
        for(M=0 ; M<m ; M++)
        {
            mrate = (mr[M]?mr[M]:mrate);
            total *= (1.0-mrate);
            if(l<total)break;
            l-=avg;
            
            //cout<<l<< " "<<total<<"\n";
        }
        
        if(M==1)cout<<"1 month\n";
        else cout<<M<<" months\n";
    }
    return 0;
}
