#include <iostream>
#define MAXTIME 1000000
#define MAX 15
using namespace std;

struct students
{
	int w,s,c;//w wake ,s sleep ,c current
}stu[MAX];

int count;
bool all_awake(int num)
{
	count=0;
	for(int i=0 ; i<num ; i++)
	{
		if(stu[i].c <= stu[i].w)
			count++;
	}
	
	return count==num? 1 : 0;
}

void simulate(int num)
{
	for(int i=0 ; i<num ; i++)
	{
		stu[i].c%=stu[i].s+stu[i].w;
		if(stu[i].c==stu[i].w && !(count < num-count))stu[i].c=0;
		stu[i].c++;
	}
}
int main()
{
	int n,r=0;
	while(cin>>n,n)
	{
		cout<<"Case "<<++r<<": ";
		for(int i=0;i<n;i++)
			cin>>stu[i].w>>stu[i].s>>stu[i].c;
		
		int t;
		for(t=0;t<MAXTIME;t++)
		{
			if(all_awake(n))break;
			
			else simulate(n);
			
		}
		
		t<MAXTIME? cout<<t+1 : cout<<-1;
		
		cout<<'\n';
	}
	return 0;
}
