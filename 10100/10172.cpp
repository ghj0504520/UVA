#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int SET;
    cin>>SET;
    while(SET--)
    {
        int N,S,Q;
        cin>>N>>S>>Q;

        stack<int> C;
        vector< queue<int> > Stas;

        int Qi,q;
        for(int i=0 ; i<N ; i++)
        {
            queue<int> sta;
            cin>>Qi;
            for(int j=0 ; j<Qi ; j++)
            {
                cin>>q;
                sta.push(q-1);
            }
            Stas.push_back(sta);
        }

        int cur = 0 ;
        int t = 0;
        for(;;)
        {
            while(!C.empty()&& (C.top()==cur||Stas[cur].size()<Q) )
            {
                if(C.top()!=cur)Stas[cur].push(C.top());
                C.pop();
                t++;
            }
            while(!Stas[cur].empty() &&C.size()<S)
            {
                C.push(Stas[cur].front());
                Stas[cur].pop();
                t++;
            }

            bool f=1;
            for(int i=0 ; i<N ; i++)
            {
                if(!C.empty()||!Stas[i].empty())
                {
                    cur=(cur+1)%N;
                    t+=2;
                    f=0;
                    break;
                }
            }

            if(f)break;
        }
        cout<<t<<"\n";
    }
    return 0;
}