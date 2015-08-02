#include <iostream>
#include <cstring>
#include <queue>
#include <iomanip>

using namespace std;

struct  Coordinate
{
	int X,Y,Step;
};
int Map[10][10];
int MOVE[8][2]=
{
	{ 1, 2},
	{ 2, 1},
	{-1, 2},
	{-2, 1},
	{ 1,-2},
	{ 2,-1},
	{-1,-2},
	{-2,-1}
};
bool checkBound(int x,int y)
{
	return x>0&&x<=8&&y>0&&y<=8? 1:0;
}
void printMap()
{
	for(int i=1 ; i<=8 ; i++)
	{
		for(int j=1; j<=8;j++)
			cout<<setw(3)<<Map[i][j];
		cout<<"\n";
	}
}
int BFS(Coordinate S,Coordinate D)
{
	queue<Coordinate> bfs;
	bfs.push(S);
	Map[S.Y][S.X]=1;
	while(!bfs.empty())
	{
		Coordinate cur=bfs.front();
		bfs.pop();
		if(cur.X==D.X&&cur.Y==D.Y)return cur.Step;
		for(int i=0 ; i<8 ; i++)
		{
			Coordinate now;
			now.Step=cur.Step+1;
			now.X=cur.X+MOVE[i][0],now.Y=cur.Y+MOVE[i][1];
			if(checkBound(now.X,now.Y) && !Map[now.Y][now.X])
			{
				bfs.push(now);
				Map[now.Y][now.X]=1;
			}
		}
	}
}

int main()
{
	Coordinate Start,Dest;
	string s,d;
	while(cin>>s>>d)
	{
		Start.X=s[0]-'a'+1;
		Start.Y=s[1]-'0';
		Start.Step=0;
		Dest.X=d[0]-'a'+1;
		Dest.Y=d[1]-'0';

		memset(Map,0,sizeof(Map));
		int step=BFS(Start,Dest);
		cout<<"To get from "<<s<<" to "<<d<<" takes "<<step<<" knight moves.\n";
	}
	return 0;
}