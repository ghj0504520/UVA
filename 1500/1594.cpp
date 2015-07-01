#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

void duc_simulate(vector <int> &tmp,vector <int> duc)
{
	int len=duc.size();
	for(int i=0 ; i<len-1 ; i++)
		tmp.push_back(abs(duc[i]-duc[i+1]));
	tmp.push_back(abs(duc[len-1]-duc[0]));
}
bool check(vector <int> duc)
{
	int len=duc.size();
	for(int i=0 ; i<len ; i++)
	{
		if(duc[i]!=0)return 0;
	}
	return 1;
}

void print(vector <int> duc)
{
	int len=duc.size();
	for(int i=0 ; i<len ; i++)
		cout<<duc[i];
	cout<<'\n';
}

int main()
{
	ios::sync_with_stdio(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector <int> duc,tmp;
		map < vector<int>, bool> table; 
		for(int i=0 ; i<n ;i++)
		{
			int num;
			cin>>num;
			duc.push_back(num);
		}
		if(!check(duc))
		{
			table.insert(pair<vector<int>, bool>(duc,1));
			while(1)
			{
				tmp.clear();
				duc_simulate(tmp,duc);
				if(table[tmp])
				{
					cout<<"LOOP\n";
					break;
				}
				if(check(tmp))
				{
					cout<<"ZERO\n";
					break;
				}
				table[tmp]=1;
				duc=tmp;
			}
		}
		else
		{
			cout<<"ZERO\n";
		}
	} 
	return 0;
}
