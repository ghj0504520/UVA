#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	cin>>N;
	for(int t=0 ; t<N ; t++)
	{
		if(t)cout<<"\n";
		int num;
		cin>>num;
		while(getchar()!='\n');						//fuck you UVA
		map< string,string >team;
		map< string,int >count;
		for(int i=0 ; i<num ; i++)
		{
			string a,b;
			getline(cin,a);
			getline(cin,b);
			team.insert(std::pair<string,string>(a,b));
		}
		int ticketNum;
		cin>>ticketNum;
		while(getchar()!='\n');						//fuck you UVA
		for(int i=0 ; i<ticketNum ; i++)
		{
			string a;
			getline(cin,a);
			if(team.count(a))
				count[ a ]++;
		}

		map< string,int >::iterator it;
		int M=-1;
		for(it=count.begin();it!=count.end();it++)
			if(it->second > M)M=it->second;
		string ANS="";
		bool success=0;
		for(it=count.begin();it!=count.end();it++)
		{
			if(ANS==""&&M==it->second)
			{
				success=1;
				ANS=it->first;
			}
			else if((ANS!=""&&M==it->second))
			{
				success=0;
				break;
			}
		}
		if(!success)
		{
			cout<<"tie\n";
		}
		else
		{
			cout<<team[ANS]<<"\n";
		}
	}
	return 0;
}