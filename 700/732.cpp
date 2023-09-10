#include <iostream>
#include <stack>
using namespace std;

stack<char> S;
void DFS(string a,string b,int ia,int ib,string ans)
{
    if(ib == b.size())
    {
        cout <<ans<<"\n";
        return ;
    }

    if(ia < a.size())
    {
        S.push(a[ia]);
        DFS(a,b,ia+1,ib,ans+(ans.empty() ? "i" : " i"));
        S.pop();
    }
    if (!S.empty() && S.top() == b[ib])
	{
		char tmp = S.top();
		S.pop();
		DFS(a,b,ia, ib + 1, ans + " o");
        S.push(tmp);
    }	
}
int main()
{
    string s,d;
    while(cin>>s>>d)
    {
        S=stack<char>();
        cout<<"[\n";
        if(s.size()==d.size())
            DFS(s,d,0,0,"");
        cout<<"]\n";
    }
    return 0;
}