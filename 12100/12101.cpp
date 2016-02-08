#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

struct data
{
	int digit;
	int cnt;
	data(int n,int c)
	{
		digit=n,cnt=c;
	}
};
bool prime[20000]={0};
int table[20000]={0};

void seize()
{
	prime[0]=prime[1]=1;
	for (int i = 2; i < 20000 ; ++i)
		if(!prime[i])
			for (int j = i+i ; j < 20000 ; j+=i)
				prime[j]=1;
}

int digitAdd(int cur,int idx,int pos)
{
	char itoa[5];
	sprintf(itoa,"%d",cur);

	itoa[pos]=idx+'0';
	itoa[4]='\0';

	sscanf(itoa,"%d",&cur);

	return cur;
}

bool check(int cur)
{
	return !table[cur]&&!prime[cur]&&cur>=1000&&cur<10000;
}

int BFS(int start,int dest)
{
	queue<data>bfs;
	bfs.push(data(start,0));
	table[start]=1;

	while(bfs.size())
	{
		data cur=bfs.front();
		bfs.pop();

		if(cur.digit==dest)
			return cur.cnt;

		int c;
		for(int i=0 ; i<4 ; i++)
		{
			for(int j=0 ; j<10 ; j++)
			{
				c=digitAdd(cur.digit,j,3-i);
				if(check(c))
				{
					table[c]=1;
					bfs.push(data(c,cur.cnt+1));
				}
			}
		}	
	}
	return -1;
}


int main()
{
	seize();
	int T;
	int start,dest;
	cin>>T;
	while(T--)
	{
		cin>>start>>dest;
		memset(table,0,sizeof(table));
		
		int n=BFS(start,dest);
		if(n==-1)cout<<"Impossible\n";
		else cout<<n<<"\n";
	}
	return 0;
}