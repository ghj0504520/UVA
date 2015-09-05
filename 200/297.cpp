#include <iostream>
#include <cstring>
#define Len 32

using namespace std;
string data;
bool buf[Len][Len];
int blackCcount;

void mergeIMG(string s,int &idx,int R,int C,int W)
{
	int cur=data[idx++];
	if(cur=='p')
	{
		mergeIMG(s,idx,R,C+W/2,W/2);
		mergeIMG(s,idx,R,C,W/2);
		mergeIMG(s,idx,R+W/2,C,W/2);
		mergeIMG(s,idx,R+W/2,C+W/2,W/2);
	}
	else if(cur=='f')
	{
		for(int i=R ; i<R+W ; i++)
			for(int j=C ; j<C+W ; j++)
				if(!buf[i][j])
				{
					buf[i][j]=1;
					blackCcount++;
				}
	}
}

int main()
{
	int num;
	cin>>num;
	for(int i=0 ; i<num ; i++)
	{
		memset(buf,0,sizeof(buf));
		blackCcount=0;
		for(int t=0 ; t<2 ; t++)
		{
			cin>>data;
			int idx=0;
			mergeIMG(data,idx,0,0,Len);
		}
		cout<<"There are "<<blackCcount<<" black pixels.\n";
	}
	return 0;
}