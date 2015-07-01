#include <iostream>
#include <cstdio>
using namespace std;

int joseph(int all,int cur,int m[],int walk,int direct)
{
	
	while(walk--)
	{
		do
		{	
			cur=(cur+direct+all-1)%all+1;           //figure out
		}while(!m[cur]);
		
	}
	return cur;
}

int main()
{
	int n,anti,cw;
	while(cin>>n>>anti>>cw)
	{
		if(!n && !anti && !cw)break;
		
		int man[n+1];
		for(int i=0 ; i<=n ; i++)man[i]=i;
			
		int pos_anti=n,pos_cw=1,num=n;  //figure out
		
		while(num)
		{
			pos_anti=joseph(n,pos_anti,man,anti,1);
			
			pos_cw=joseph(n,pos_cw,man,cw,-1);
		
			//cout<<pos_anti<<' ';
			printf("%3d",pos_anti);
			num--;
			if(pos_anti!=pos_cw)
			{	
				//cout<<pos_cw<<' ';
				printf("%3d",pos_cw);
				num--;
			}
			man[pos_anti]=0,man[pos_cw]=0;
			if(num)cout<<',';
		}
		cout<<"\n";
	}
	return 0;
}
