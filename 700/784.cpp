#include <iostream>

using namespace std;

int Move[4][2]=
{
	{0,1},{1,0},{0,-1},{-1,0}
};
string Map[50];

void floodFill(int x,int y)
{
	if(Map[y][x]=='*'||Map[y][x]==' ')
	{
		Map[y][x]='#';
		for(int i=0 ; i <4 ; i++)
		{
			floodFill(x+Move[i][0],y+Move[i][1]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int num,t=0;
	cin>>num;
	cin.ignore();
	for(int t=0 ; t<num ; t++)
	{
		int cnt=0;
		while(getline(cin,Map[cnt++]))
		{
			if(Map[cnt-1][0]=='_')break;
		}

		for (int i = 0; i < cnt; ++i)
		{
			int len=Map[i].size();
			for (int j = 0; j < len; ++j)
			{
				if(Map[i][j]=='*')
				{
					floodFill(j,i);
				}			
			}
		}
		for(int i=0 ; i<cnt; i++)
		{
			cout<<Map[i]<<"\n";
		}
	}
	return 0;
}