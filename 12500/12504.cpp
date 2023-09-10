#include <iostream>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	while(num--)
	{
		map<string,string> O,N;
		string in;
		cin>>in;

		int l = in.length();
		for (int i = 0; i < l; ++i)
		{
			if(in[i]=='{'||in[i]=='}'||in[i]==',')
				in[i] = ' ';
		}

		string tmp,k,v;
		stringstream buf(in);
		while(buf>>tmp)
		{
			l = tmp.length();
			for (int i = 0; i < l; ++i)
			{
				if(tmp[i]==':')
					tmp[i] = ' ';
			}

			stringstream buf2(tmp);
			buf2>>k>>v;
			O[k]=v;
		}

		cin>>in;

		l = in.length();
		for (int i = 0; i < l; ++i)
		{
			if(in[i]=='{'||in[i]=='}'||in[i]==',')
				in[i] = ' ';
		}

		stringstream buf3(in);
		while(buf3>>tmp)
		{
			l = tmp.length();
			for (int i = 0; i < l; ++i)
			{
				if(tmp[i]==':')
					tmp[i] = ' ';
			}

			stringstream buf4(tmp);
			buf4>>k>>v;
			N[k]=v;
		}

		map<string,string>::iterator it;
		set<string> M;
		for (it=N.begin(); it!=N.end(); ++it)
		{
			if(O.find(it->first)!=O.end())
			{
				string diffKey = it->first;
				if(O[it->first]!=it->second)
				{
					M.insert(diffKey);
				}
				O.erase(diffKey);
				//N.erase(diffKey);
				N[diffKey]="";
			}
		}
		
		bool out=0,no=1;
		for (it=N.begin(); it!=N.end(); ++it)
		{
			if(it->second!="")
			{
				no=0;
				if(!out){cout<<"+";out=1;}
				else cout<<",";
				cout<<it->first;
			}
		}
		if(out)cout<<"\n";
		out=0;
		for (it=O.begin(); it!=O.end(); ++it)
		{
			no=0;
			if(!out){cout<<"-";out=1;}
			else cout<<",";
			cout<<it->first;
		}
		if(out)cout<<"\n";
		out=0;
		for (set<string>::iterator sit=M.begin(); sit!=M.end(); ++sit)
		{
			no=0;
			if(!out){cout<<"*";out=1;}
			else cout<<",";
			cout<<*sit;
		}
		if(out)cout<<"\n";

		if(no)
		{
			cout<<"No changes\n";
		}

		cout<<'\n';
	}

	return 0;
}