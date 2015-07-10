#include <iostream>
#include <queue>
#include <cstdio>
#include <map>
using namespace std;

int read_digit()
{
	int ans=0;
	for(int i=0 ; i<4 ; i++)
	{
		int c;
		cin>>c;
		ans=10*ans+c;
	}
	return ans;
}

int move(int num,int digit,int direct)
{
	int a,b,c,d;
	d=num%10;
	num/=10;
	c=num%10;
	num/=10;
	b=num%10;
	num/=10;
	a=num;
	int cnt;
	switch (digit)
	{
		case 0:
			cnt=a;
			break;
		case 1:
			cnt=b;
			break;
		case 2:
			cnt=c;
			break;
		case 3:
			cnt=d;
			break;
	}
	direct? cnt++:cnt--;
	if(cnt>9)cnt=0;
	if(cnt<0)cnt=9;
	switch (digit)
	{
		case 0:
			a=cnt;
			break;
		case 1:
			b=cnt;
			break;
		case 2:
			c=cnt;
			break;
		case 3:
			d=cnt;
			break;
	}
	int ans=a*1000+b*100+c*10+d;
	return ans;
}

int main()
{
	int count;
	cin>>count;
	for(int T=0 ; T<count ; T++)
	{
		map<int,int>table;
		int s,d;
		s=read_digit();
		d=read_digit();
		int limitNum;
		cin>>limitNum;
		for (int i = 0; i < limitNum; ++i)
			table.insert(std::pair<int,int>(read_digit(),-1));
		queue<int> bfs;
		bfs.push(s);
		int step=0;
		bool success=0;
		table.insert(std::pair<int,int>(s,step));
		while(!bfs.empty())
		{
			int cur=bfs.front();
			bfs.pop();
			step=table[cur];
			if(cur==d)
			{
				success=1;
				break;
			}
			for(int i=0  ; i<4  ; i++)
			{
				for(int j=0 ; j<2 ; j++)
				{
					int now=move(cur,i,j);
					if(table.find(now)==table.end())
					{
						bfs.push(now);
						table.insert(std::pair<int,int>(now,step+1));
					}
				}
			}
		}
		if(success)
			cout<<step<<"\n";
		else
			cout<<"-1\n";
		getchar();
	}
	return 0;
}