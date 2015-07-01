#include <iostream>
#include <cstdio>
using namespace std;

int r,c,n;

struct COMMAND
{
	string cmd;
	int r1,c1,r2,c2;
	int a,c[20]; 
};
COMMAND cmd[10000]; 

int simulate(int *qr,int *qc)
{
	for(int i=0;i<n;i++)
	{
		if(cmd[i].cmd=="EX")
		{
			if(cmd[i].r1==*qr && cmd[i].c1==*qc)
				*qr=cmd[i].r2,*qc=cmd[i].c2;
			else if(cmd[i].r2==*qr && cmd[i].c2==*qc)
				*qr=cmd[i].r1,*qc=cmd[i].c1;
		}
		else
		{
			int mr=0,mc=0,curx;
			for(int j=0 ; j<cmd[i].a ; j++)
			{
				//cout<<*qr<<' '<<*qc<<'\n';
				curx=cmd[i].c[j];
				if(cmd[i].cmd=="IR")
				{
					if(curx<=*qr)mr++;
				}
				else if(cmd[i].cmd=="IC")
				{	
					if(curx<=*qc)mc++;
				}
				else if(cmd[i].cmd=="DR")
				{
					if(curx<*qr)mr--;
					else if(curx==*qr)return 0;
				}
				else if(cmd[i].cmd=="DC")
				{
					if(curx<*qc)mc--;
					else if(curx==*qc)return 0;
				}
			}*qr=*qr+mr,*qc=*qc+mc;
		}
	}
	return 1;
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int t=0;
	while(cin>>r>>c)
	{
		if(!r&&!c)break;
		cin>>n;
		if(t)cout<<'\n';
		cout<<"Spreadsheet #"<<++t<<'\n';
		for(int i=0;i<n;i++)
		{
			cin>>cmd[i].cmd;
			if(cmd[i].cmd=="EX")
				scanf("%d %d %d %d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
			else
			{
				scanf("%d",&cmd[i].a);
				for(int j=0 ; j<cmd[i].a ; j++)
					scanf("%d",&cmd[i].c[j]);
			}
		}
		int qnum;
		cin>>qnum;
		int qr,qc;
		for(int i=0 ; i<qnum ; i++)
		{
			scanf("%d %d",&qr,&qc);
			printf("Cell data in (%d,%d) ",qr,qc);
			if(!simulate(&qr,&qc))printf("GONE\n");
			else printf("moved to (%d,%d)\n",qr,qc);
		}
	}
	return 0;
}
