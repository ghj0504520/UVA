#include <iostream>
#include <algorithm>
#define M 110

using namespace std;

int main()
{
	int n;
	string name[M];
	while(cin>>n)
	{
		for(int i=0 ; i<n ; i++)
			cin>>name[i];
		
		int m=0;
		for(int i=0 ; i<n ; i++)
			m=max(m,(int)name[i].length());
			
		int col=(60-m)/(m+2)+1,row=(n-1)/col+1;
		sort(name,name+n);
		
		for(int i=0 ; i<60 ; i++)
			cout<<'-';
		cout<<'\n';
		
		int id=0;
		for(int r=0 ; r<row ; r++)
		{
			for(int c=0 ; c<col ; c++)
			{
				id=c*row+r;
				if(id<n)
				{
					if(c==col-2)
					{
						cout<<name[id];
						int l=name[id].size();
						for(int p=0 ; p<m-l ; p++)
							cout<<' ';
					}
					else
					{	
						cout<<name[id];
						int l=name[id].size();
						for(int p=0 ; p<m+2-l ; p++)
							cout<<' ';
					}
				}
			}cout<<"\n";
		}
	}
	return 0;
}
