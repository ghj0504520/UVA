#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,t=0;
    while(cin>>n)
    {
        if(t++)cout<<"\n";
        map<string,int> P;
        map<int, string>O;
        for(int i=0 ; i<n; i++)
        {
            string tmp;
            cin>>tmp;
            P[tmp]=0;
            O[i]=tmp;
        }
        
        string name,lend2n;
        int lend;
        int num;
        for(int i=0 ; i<n; i++)
        {
            cin>>name>>lend>>num;
            
            if(!num)continue;
            int avg=(int)lend/num;
            int r=lend-num*avg;
            
            P[name]=P[name]+r-lend;
            
            for(int j=0 ; j<num; j++)
            {
                cin>>lend2n;
                P[lend2n]+=avg;
            }
        }
        
        for(auto i=0 ; i<n; i++)
        {
            cout<<O[i]<<" "<<P[O[i]]<<"\n";
        }
    }
    
    return 0;
}
