#include <iostream>
#include <map>

using namespace std;

map<char,int>kb;
void create()
{
	kb['a']=1;kb['b']=2;
	kb['c']=3;kb['d']=1;
	kb['e']=2;kb['f']=3;
	kb['g']=1;kb['h']=2;
	kb['i']=3;kb['j']=1;
	kb['k']=2;kb['l']=3;
	kb['m']=1;kb['n']=2;
	kb['o']=3;kb['p']=1;
	kb['q']=2;kb['r']=3;
	kb['s']=4;kb['t']=1;
	kb['u']=2;kb['v']=3;
	kb['w']=1;kb['x']=2;
	kb['y']=3;kb['z']=4;
	kb[' ']=1;
}

int main()
{
	ios::sync_with_stdio(0);
	create();
	int T;
	cin>>T;
	cin.ignore();
	for (int t = 0; t < T; ++t)
	{
		string msg;
		getline(cin,msg);
		int len=msg.size();
		
		int ans=0;
		for(int i=0 ; i<len ; i++)
		{
			ans+=kb[msg[i]];
		}
		cout<<"Case #"<<t+1<<": "<<ans<<"\n";
	}
	return 0;
}