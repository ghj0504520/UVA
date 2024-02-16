#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int R,C;
    while(cin>>R)
    {
        if(!R)break;
        
        map<string,int> TC;
        cin>>C;
        
        string cn;
        for(int i=0 ; i<R ; i++)
        {
            cin>>cn;
            TC[cn]=1;
        }
        
        int CC, CCN, CCNT=0;
        for(int i=0 ; i<C ; i++)
        {
            cin>>CC>>CCN;
            int CCCNT=0;
            for(int j=0 ; j<CC ; j++)
            {
                cin>>cn;
                
                if(TC[cn]==1)
                    CCCNT++;
            }
            if(CCCNT>=CCN)
                CCNT++;
        }
        
        if(CCNT==C)
            cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
