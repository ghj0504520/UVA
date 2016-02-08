#include <iostream>
#include <cctype>

using namespace std;

int c,r;
string m[100];

bool check(int x,int y)
{
	return x>=0&&y>=0&&x<c&&y<r;
}

bool match(string &q,int x,int y,int mx,int my)
{
	int len=q.size();
	for(int i=0 ; i<len ; i++)
	{
		if(!check(x,y)||(tolower(m[y][x])!=tolower(q[i])))return 0;

		y+=my;
		x+=mx;
	}return 1;
}

int dir[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
bool find(string q)
{
	int len=c;
	for(int i=0 ; i<r ; i++)
	{
		for(int j=0 ; j<c ; j++)
		{
			if(tolower(m[i][j])==tolower(q[0]))
			{
				for(int d=0 ; d<8 ; d++)
				{
					if(match(q,j,i,dir[d][1],dir[d][0]))
					{
						cout<<i+1<<" "<<j+1<<"\n";
						return 1;
					}
				}
			}
		}
	}return 0;
}

int main()
{
	int T,t=0;
	cin>>T;
	while(T--)
	{
		if(t++)cout<<"\n";
		cin>>r>>c;
		for(int i=0 ; i<r ; i++)
			cin>>m[i];

		int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			string query;
			cin>>query;
			find(query);
		}
	}
	return 0;
}