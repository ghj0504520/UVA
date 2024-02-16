#include <cmath>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int t=0 ; t<T; t++)
    {
        stack<string> pile, hand;
        string c;
        for(int i=0 ; i< 52 ; i++)
        {
            cin>>c;
            pile.push(c);
        }
        for(int i=0 ; i< 25 ; i++)
        {
            string hc=pile.top();
            hand.push(hc);
            pile.pop();
        }
        int X,Y=0;
        for(int i=0 ; i< 3 ; i++)
        {
            string hc=pile.top();
            X = ((hc[0]>='2'&&hc[0]<='9')?hc[0]-'0':10);
            Y+=X;
            
            pile.pop();
            for(int j=0 ; j< 10-X ; j++)
                pile.pop();
        }
        
        for(int i=0 ; i< 25 ; i++)
        {
            string hc=hand.top();
            pile.push(hc);
            hand.pop();
        }
        
        int len=pile.size();
        for(int i=0 ; i< len-Y ; i++)
        {
            pile.pop();
        }
        cout<<"Case "<<t+1<<": "<<pile.top()<<"\n";
    
    }
    return 0;
}
