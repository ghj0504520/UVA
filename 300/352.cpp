#include <iostream>

using namespace std;

int Move[8][2]=
{
	{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}
};
bool Map[30][30];
bool checkBound(int x,int y,int num)
{
	return x>=0&&x<num&&y>=0&&y<num? 1:0;
}
void floodFill(int x,int y,int num)
{
	if(checkBound(x,y,num) && Map[y][x])
	{
		Map[y][x]=0;
		for(int i=0 ; i <8 ; i++)
		{
			floodFill(x+Move[i][0],y+Move[i][1],num);
		}
	}
}
int main()
{
	int num,t=0;
	while(cin>>num)
	{
		char a;
		for (int i = 0; i < num; ++i)
		{
			for (int j = 0; j < num; ++j)
			{
				cin>>a;
				Map[i][j]=a-'0';
			}
		}
		int ans=0;
		for (int i = 0; i < num; ++i)
		{
			for (int j = 0; j < num; ++j)
			{
				if(Map[i][j])
				{
					ans++;
					floodFill(j,i,num);
				}			
			}
		}
		cout<<"Image number "<<++t<<" contains "<<ans<<" war eagles.\n";
	}
	return 0;
}