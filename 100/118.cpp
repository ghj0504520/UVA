#include <iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	bool map[100][100]={0};
	char D[4]={'E','S','W','N'};
	int X,Y;
	int x,y,dir;
	char ch;
	cin>>X>>Y;
	while(cin>>x)
	{
		cin>>y>>ch;
		if(ch=='E')dir=0;
		else if(ch=='S')dir=1;
		else if(ch=='W')dir=2;
		else if(ch=='N')dir=3;
		string cmd;
		cin>>cmd;
		int len=cmd.size();
		bool success=1;
		for(int i=0 ; i<len ;i++)
		{
			if(cmd[i]=='L')
				dir=(dir-1+4)%4;
			else if(cmd[i]=='R')
				dir=(dir+1+4)%4;
			else if(cmd[i]=='F')
			{
				int curx=x,cury=y;
				if(dir==0)curx++;
				else if(dir==1)cury--;
				else if(dir==2)curx--;
				else if(dir==3)cury++;
				if(curx>X ||cury>Y ||curx<0 ||cury<0)
				{
					if(!map[x][y])
					{
						map[x][y]=1;
						success=0;
						break;
					}
				}
				else
				{
					x=curx;
					y=cury;
				}
			}
		}
		if(!success)
			cout<<x<<" "<<y<<" "<<D[dir]<<" LOST\n";
		else
			cout<<x<<" "<<y<<" "<<D[dir]<<endl;
	}
	return 0;
}