#include <iostream>

using namespace std;

int Move[4][2]=
{
	{0,1},{1,0},{0,-1},{-1,0}
};
string Map[30];
int cnt;
int R,C;

void floodFill(int curX,int curY,char L)
{
	if(curX>=0 &&curX<R)
	{	
		curY=(curY+C)%C;
		if(Map[curX][curY]==L)
		{
			cnt++;
			Map[curX][curY]=L+1;
			for(int i=0 ; i <4 ; i++)
			{
				floodFill(curX+Move[i][0],curY+Move[i][1],L);
			}	
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	while(cin>>R>>C)
	{
		for(int i=0;i<R;i++)cin>>Map[i];

		int x,y;
		cin>>x>>y;
		char Land=Map[x][y];
		int ans=0;
		floodFill(x,y,Land);
		for (int i = 0; i < R; ++i)
		{

			for (int j = 0; j < C; ++j)
			{
				if(Map[i][j]==Land)
				{
					cnt=0;
					floodFill(i,j,Land);
					if(ans<cnt)ans=cnt;
				}			
			}
		}
		cout<<ans<<"\n";
		cin.ignore();
	}
	return 0;
}