#include <iostream>

using namespace std;

const int N = 100005;  
int le[N], ri[N];

void link_simulate(int lF,int rF)
{
	le[rF]=lF;
	ri[lF]=rF;
}

void print(int l[],int r[],int len)             //for debug
{
	for(int i=0 ; i<=len ; i++)
	{
		cout<<l[i]<<" "<<i<<" "<<r[i]<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int n ,m,t=0;
	while(cin>>n>>m)
	{
		cout<<"Case "<<++t<<": ";
		for(int i=1 ; i<=n ; i++)
		{
			le[i]=i-1,ri[i]=i+1;
		}
		le[0]=n,ri[0]=1,ri[n]=0;
		int op;
		bool inverse=0;
		while(m--)
		{
			cin>>op;
			if(op==4)
				inverse= !inverse;
			else
			{
				int x,y;
				cin>>x>>y;
				if(inverse && op!=3) 				//figure out
					op=3-op;
				
				if((op==1 && le[y]==x) || (op==2 && ri[y]==x))
					continue;

				if(op==2)
				{
					link_simulate(le[x],ri[x]);
					link_simulate(x,ri[y]);
					link_simulate(y,x);
				}
				else if(op==1)
				{
					link_simulate(le[x],ri[x]);
					link_simulate(le[y],x);
					link_simulate(x,y);
				}
				else if(op==3)
				{
					int tmpl=le[y],tmpr=ri[y];
					if(ri[x]==y)
					{
						link_simulate(le[x],y);
						link_simulate(x,ri[y]);
						link_simulate(y,x);
					}
					else if(le[x]==y)
					{
						link_simulate(le[y],x);
						link_simulate(y,ri[x]);
						link_simulate(x,y);
					}
					else
					{
						link_simulate(le[x],y);
						link_simulate(y,ri[x]);
						link_simulate(tmpl,x);
						link_simulate(x,tmpr);
					}
				}
			}
		}
		
		//print(le,ri,n);
		long long ans=0,tmp=0;
		for(int i=1 ; i<=n ; i++)
		{
			tmp=ri[tmp];                   //figure out
			if(i%2)ans+=tmp;
		}
		
		if(n%2==0 && inverse)
			ans=(long long)n/2*(n+1)-ans;
			
		cout<<ans<<"\n";
	}
	return 0;
}
