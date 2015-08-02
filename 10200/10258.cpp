#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;
struct team
{
	int ID;
	int cntProb;
	int pTime;
	bool submit;
	int cntTime[15];
	int firstTime[15];

	team()
	{
		cntProb=0;
		pTime=0;
		submit=0;
		memset(cntTime,0,sizeof(cntTime));
		memset(firstTime,0,sizeof(firstTime));
	}
	bool operator<(const team &pre)const
	{
		if((pre.cntProb==cntProb)&&(pre.pTime==pTime))
			return pre.ID > ID;
		else if(pre.cntProb==cntProb)
			return pre.pTime > pTime;
		else	return pre.cntProb < cntProb;
	}
};
int main()
{
	int num;
	cin>>num;
	getchar();
	getchar();
	string line;
	for(int t=0 ; t<num ; t++)
	{
		team data[110];
		for(int i=0 ; i<110 ;i++)data[i].ID=i;
		while(getline(cin,line))
		{
			if(line=="")break;
			stringstream buf(line);
			int curID,curP,curT;
			char curR;
			buf>>curID>>curP>>curT>>curR;
			data[curID].submit=1;
			if(curR=='I')
			{
				data[curID].cntTime[curP]++;
			}
			else if(curR=='C'&&!data[curID].firstTime[curP])
			{
				data[curID].firstTime[curP]=curT;
				data[curID].cntProb++;
				data[curID].pTime=data[curID].pTime+curT+data[curID].cntTime[curP]*20;
			}
		}
		sort(data,data+101);
		if(t)cout<<"\n";
		for(int i =0 ; i<=100 ; i++)
		{
			if(data[i].submit)
			{
				cout<<data[i].ID<<" "<<data[i].cntProb<<" "<<data[i].pTime<<"\n";
			}
		}
	}
	return 0;
}