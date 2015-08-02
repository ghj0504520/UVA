#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const std::pair<char,int> & i,const std::pair<char,int> & j)
{
	return i.second>j.second;
}

int Move[4][2]=
{
	{0,1},{1,0},{0,-1},{-1,0}
};
string Map[100];
int r,c,ans;
bool checkBound(int x,int y)
{
	return x>=0&&x<c&&y>=0&&y<r? 1:0;
}
void floodFill(int x,int y,char cur)
{
	if(checkBound(x,y) && Map[y][x]==cur)
	{
		ans++;
		Map[y][x]='.';
		for(int i=0 ; i <4 ; i++)
		{
			floodFill(x+Move[i][0],y+Move[i][1],cur);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int t=0;
	while(cin>>r>>c)
	{
		cin.ignore();
		if(!r&&!c)break;
		for (int i = 0; i < r; ++i)
		{
			getline(cin,Map[i]);
		}
		multimap<char,int>table;
		char cur;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cur=Map[i][j];
				if(cur!='.')
				{
					ans=0;
					floodFill(j,i,cur);
					table.insert(std::pair<char,int>(cur,ans));
				}			
			}
		}
		multimap<char,int>::iterator it;
		vector<std::pair<char,int> >answer;
		for(it=table.begin() ; it!=table.end() ; it++)
		{
			//cout<<it->first<<" "<<it->second<<"\n";
			answer.push_back(*it);
		}
		stable_sort(answer.begin(),answer.end(),cmp);
		int len=answer.size();
		cout<<"Problem "<<++t<<":\n";
		for(int i=0 ; i<len ; i++)
		{
			cout<<answer[i].first<<" "<<answer[i].second<<"\n";
		}
	}
	return 0;
}