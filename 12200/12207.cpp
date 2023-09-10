#include<iostream>
#include<deque>
using namespace std;

int main()
{
    int P,C,t=0;
    while(cin>>P>>C)
    {
        if(!P&&!C)break;
        cout<<"Case "<<++t<<":\n";

        deque<int> L;
        for(int i=1;i<=min(P,C);i++)
            L.push_back(i);
        char cmd;
        int n;
        while(C--)
        {
            cin>>cmd;
            
            if(cmd=='N')
            {
                int tmp;
                cout<<(tmp=L.front() )<<'\n';
                L.pop_front();
                L.push_back(tmp);
            }

            else if(cmd=='E'){
                cin>>n;
                deque<int>::iterator it;
                for(it=L.begin() ; it!=L.end() ; it++)
                {
                    if(*it == n)
                    {
                        L.erase(it);
                        break;
                    }
                }
                L.push_front(n);
            }
        }
    }
    return 0;
}