#include <iostream>

using namespace std;

string m[210+1];
int dir[6][2] = {{-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1}};

bool checkBound(int x,int y,int limit)
{
	return x<limit&&x>=0&&y<limit&&y>=0;
}

bool dfsGame(int x, int y, char c, int limit)
{
	if(c == 'b' && x == limit-1)
		return 1;
	else if (c == 'w' && y == limit-1)
		return 1;

	m[x][y] ='.';

	for(int i=0 ; i<6 ; i++)
	{
		if(checkBound(x+dir[i][0],y+dir[i][1],limit)&&m[x+dir[i][0]][y+dir[i][1]] == c)
			if(dfsGame(x+dir[i][0],y+dir[i][1],c,limit))
				return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int n,t =0;

	while(cin>>n)
	{
		if (!n)break;

		for(int i=0 ; i<n ; i++)
			cin>>m[i];

		int w=0,b=0;
		for (int i=0; i<n; ++i)
			if (m[i][0] == 'w')
				if( (w=dfsGame(i, 0, 'w', n)))
					break;
		for (int j=0; j<n; ++j)
			if (m[0][j] == 'b')
				if( (b=dfsGame(0, j, 'b', n)))
					break;
		cout<<++t;
		if (w)
			cout<<" W\n";
		else if(!w&&b)
			cout<<" B\n";
	}
	return 0;
}