#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const std::pair<string,int> &i,const std::pair<string,int> &j)
{
	return i.second>j.second ||(i.second==j.second &&i.first<j.first);
}

int main()
{
	ios::sync_with_stdio(0);
	string input;
	while(getline(cin,input))
	{
		if(input=="0")break;

		map<string,string>Name;
		map<string,int>cnt;
		string curProj;
		while(1)
		{
			if(input=="1")break;

			if(input[0]>='A'&&input[0]<='Z')
			{
				cnt.insert(std::pair<string,int>(input,0));
				curProj=input;
			}
			else if(input[0]>='a'&&input[0]<='z')
			{
				if(!Name.count(input))
				{
					cnt[curProj]++;
					Name.insert(std::pair<string,string>(input,curProj));
				}
				else
				{
					if(Name[input]!="fuck"&&Name[input]!=curProj)
					{
						cnt[ Name[input] ]--;
						Name[input]="fuck";
					}
				}
			}
			getline(cin,input);
		}
		map<string,int>::iterator it;
		vector<std::pair<string,int> >ANS;
		for(it=cnt.begin(); it!=cnt.end();it++)
		{
			ANS.push_back(*it);
		}
		sort(ANS.begin(),ANS.end(),cmp);
		for(int i=0 ; i<ANS.size();i++)
		{
			cout<<ANS[ i].first<<" "<<ANS[ i].second<<"\n";
		}
	}
	return 0;
}