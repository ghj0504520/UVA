#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int by,bm,bd,cy,cm,cd;

bool check_b()
{	                        
	if((cy<by) || (by==cy && cm<bm) || (by==cy && bm==cm && cd<bd))
		return 0;
	return 1;
}

int main()
{
	int n;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		cout<<"Case #"<<i+1<<": ";
		char pre[20],cur[20];
		cin>>cur>>pre;
		sscanf(cur,"%d/%d/%d",&cd,&cm,&cy);
		sscanf(pre,"%d/%d/%d",&bd,&bm,&by);
		
		if(!check_b())
			cout<<"Invalid birth date";
		else
		{
			int age=cy-by;
			if(!((cm>bm) ||(cm==bm&&cd>=bd)))age--;
				
			if(age>130)cout<<"Check birth date";
			else cout<<age;
		}
		cout<<'\n';
	}
	return 0;
}
