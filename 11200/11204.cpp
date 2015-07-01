#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int t=0 ; t<n ; t++)
	{
		int m,stu;
		cin>>m>>stu;
		
		int order[stu][m];
		for(int i=0 ; i<stu ; i++)
			for(int j=0 ; j<m ; j++)
				cin>>order[i][j];
		
		int list[m];
		memset(list,0,sizeof(list));
		for(int i=0 ; i<stu ; i++)
		{
			for(int j=0 ; j<m ; j++)
			{
				if(order[i][j]==1)
				{
					list[j]++;	
				}
			}
		}
		int sum=1;
		for(int j=0 ; j<m ; j++)
		{
			if(list[j])
				sum*=list[j];
		}
		cout<<sum<<'\n';
	}
	return 0;
}
