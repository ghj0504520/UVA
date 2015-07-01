#include <iostream>
#include<algorithm>
using namespace std;
struct man
{
	int	hand_out ,	job_time;
};
bool compare(const man& i , const man& j )
{
	return i.job_time	>	j.job_time;
}
int main (int argc, char *argv[])
{
		int n,t=0;
		while(cin>>n)
		{
			t++;
			if(n==0)
				break;
			man data[n];
			for(int i=0;i<n;i++)
				cin>>data[i].hand_out>>data[i].job_time;
			sort(data,data+n,compare);
			/*for(int i=0;i<n;i++)
				cout<<data[i].hand_out<<data[i].job_time;
			*/ //debug
			int start_time=0,finish_time=0;
			for(int i=0;i<n;i++)
			{
				start_time+=data[i].hand_out;
				finish_time=max(finish_time,start_time+data[i].job_time);
			}cout<<"Case "<<t<<": "<<finish_time<<'\n';
		}
	
	return 0;
}

