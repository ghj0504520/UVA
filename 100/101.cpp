#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;
vector<int> block[30];
int num;

void print_block()
{
	for(int i=0;i<num;i++)
	{
		int len=block[i].size();
		cout<<i<<":";
		if(len)cout<<' ';
		for(int j=0;j<len;j++)
		{
			if(j)cout<<' ';
			cout<<block[i][j];
		}
		cout<<'\n';
	}
}
int find(int f)
{
	for(int i=0;i<num;i++)
	{
		int len=block[i].size();
		for(int j=0;j<len;j++)
			if(block[i][j]==f)return i;
	}
	return -1;
}
void clean(int p,int f )
{
	int len=block[p].size();
	for(int i=len-1;i>=0;i--)
	{
		if(block[p][i]==f)return;
		block[block[p][i]].push_back(block[p][i]);
		block[p].pop_back();
	}
}
vector<int> tmp;
void ptmp(int p,int f)
{
	tmp.resize(0);
	int len=block[p].size();
	for(int i=len-1;i>=0;i--)
	{
		tmp.push_back(block[p][i]);
		if(block[p][i]==f)
		{
			block[p].pop_back();
			return;
		}
		block[p].pop_back();
	}
}

void mn(int a,int b)
{
	int p1=find(a),p2=find(b);
	if(p1==p2)return ;
	p1=find(a);
	clean(p1,a);
	p2=find(b);
	clean(p2,b);
	p1=find(a),p2=find(b);
	block[p2].push_back(a);
	block[p1].pop_back();
}
void mv(int a,int b)
{
	int p1=find(a),p2=find(b);
	if(p1==p2)return ;
	clean(p1,a);
	p2=find(b);
	block[p2].push_back(a);
	block[p1].pop_back();
}

void pn(int a,int b)
{
	int p1=find(a),p2=find(b);
	if(p1==p2)return ;
	ptmp(p1,a);
	clean(p2,b);
	int len=tmp.size();
	for(int i=len-1;i>=0;i--)
		block[p2].push_back(tmp[i]);
}

void pv(int a,int b)
{
	int p1=find(a),p2=find(b);
	if(p1==p2)return ;
	ptmp(p1,a);
	int len=tmp.size();
	for(int i=len-1;i>=0;i--)
		block[p2].push_back(tmp[i]);
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	while(cin>>num)
	{
		getchar();
		string cmd;
		for(int i=0;i<num;i++)
		{
			block[i].resize(0);
			block[i].push_back(i);
		}
		while(getline(cin,cmd))
		{
			if(cmd=="quit")break;
			
			else
			{
				string cmd1,cmd2;
				int a,b;
				stringstream buf(cmd);
				buf>>cmd1>>a>>cmd2>>b;
				if(cmd1=="move")
				{
					if(cmd2=="onto")mn(a,b);
					
					else if(cmd2=="over")mv(a,b);
				}
				else if(cmd1=="pile")
				{
					if(cmd2=="onto")pn(a,b);
				
					else if(cmd2=="over")pv(a,b);
				}
			}
		}print_block();
	}
	return 0;
}
