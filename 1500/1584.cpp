#include <iostream>

using namespace std;

bool  str_sort(string in,int ans,int cur)
{
	int len=in.length();
	for(int i=0;i<len;i++)
	{
		if(in[(i+ans)%len]!=in[(i+cur)%len])
			return in[(i+ans)%len]>in[(i+cur)%len];
	}
	return 0;
}
int main()
{
	int num;
	string data;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cin>>data;
		int len=data.size(),ans=0;
		
		for(int i=0;i<len;i++)
		{
			if(str_sort(data,ans,i))
				ans=i;
		}
		for(int i=0;i<len;i++)
		{
			cout<<data[(i+ans)%len];
		}cout<<'\n';
		
	}
	return 0;
}
