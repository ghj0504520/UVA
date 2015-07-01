#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;

map <string , vector<string> >mta_table;

void cut(const string addr,string &user,string &mta)
{
	string tmp=addr;
	int len= tmp.length();
	for(int i=0 ; i<len ; i++)
		if(tmp[i]=='@')tmp[i]=' ';
		
	stringstream buf(tmp);
	buf>>user;
	buf>>mta;
}

bool found(vector<string> mta, string user_name)
{
	int len=mta.size();
	for(int i=0 ; i<len ; i++)
		if(mta[i]==user_name)return 1;
		
	return 0;
}

void SMTP(string m1,string m2,string u1,vector <string> s_que,string txt)
{
	cout<<"Connection between "<<m1<<" and "<<m2<<'\n';
	cout<<"     HELO "<<m1<<'\n';
	cout<<"     250\n";
	cout<<"     MAIL FROM:<"<<u1<<"@"<<m1<<">\n";
	cout<<"     250\n";
	
	bool check=0;
	int quelen=s_que.size();
	for(int j=0 ; j<quelen ; j++)
	{
		cout<<"     RCPT TO:<"<<s_que[j]<<"@"<<m2<<">\n";
		if(found(mta_table[m2],s_que[j]))
		{
			check=1;
			cout<<"     250\n";
		}
		else
			cout<<"     550\n";
	}
	if(check)
	{
		cout<<"     DATA\n";
		cout<<"     354\n";
		cout<<txt;
		cout<<"     .\n";
		cout<<"     250\n";
	}
	cout<<"     QUIT\n";
	cout<<"     221\n";
}
int main()
{
	//ios::sync_with_stdio(0);
	int num;
	string mta,name;
	vector <string> buf;
	while(cin>>mta && mta!="*")
	{
		cin>>mta>>num;
		while(num--)
		{
			cin>>name;
			buf.push_back(name);
		}
		mta_table.insert(pair<string ,vector<string> >(mta,buf));
	}
	
	
	string saddr,raddr,suser,ruser,mta1,mta2;
	while(cin>>saddr &&saddr!="*")
	{
		cut(saddr,suser,mta1);
		
		vector <string> smta;                              //send queue of mta
		set <string> vis;                                  //check repeat address
		map <string , vector<string> > dest;               //send user_name of mta que 
		
		while(cin>>raddr &&raddr!="*")
		{
			cut(raddr,ruser,mta2);
			set <string> ::iterator it=vis.find(raddr);
			if(it!=vis.end())continue;
			vis.insert(raddr);
			
			map <string , vector<string> > ::iterator ptr=dest.find(mta2);
			if(ptr==dest.end())
			{
				smta.push_back(mta2);
				dest[mta2].push_back(ruser);
			}
			else
				dest[mta2].push_back(ruser);
		}
		getchar();
		
		
		string line,txt="";
		while(getline(cin,line))
		{
			if(line[0]=='*')break;
			txt+="     "+line+"\n";
		}
		
		
		int smtalen=smta.size();
		for(int i=0 ; i<smtalen ; i++)
		{
			mta2=smta[i];
			vector <string> s_que=dest[mta2];
			SMTP(mta1,mta2,suser,s_que,txt);
		}
	}
	return 0;
} 
