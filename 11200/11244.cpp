#include <iostream>

using namespace std;

string m[110];

int dir[8][2] = {
{-1,-1},{-1,0},{-1,1},{0,1},
{1,1},{1,0},{1,-1},{0,-1}};

bool check(int r, int c, int R, int C)
{
	return r>=0&&r<R&&c>=0&&c<C&&m[r][c]=='*';
}

int dfs(int r, int c, int R, int C)
{
	m[r][c] = '.';
	bool single=1;
	for(int i=0 ; i<8 ; i++)
	{
		if(check(r+dir[i][0],c+dir[i][1],R,C))
		{
			single=0;
			dfs(r+dir[i][0],c+dir[i][1],R,C);
		}
	}
	return single;
}

int main(int argc, char const *argv[])
{
	int r,c;
	while(cin>>r>>c)
	{
		if (!r&&!c)break;

		for (int i=0 ; i<r ; i++)
			cin>>m[i];

		int sum=0;
		for (int i=0 ; i<r ; i++)
			for (int j=0 ; j<c ; j++)
				if(m[i][j]=='*' && dfs(i, j, r, c))
					sum++;
		cout<<sum<<'\n';
	}

	return 0;
}