#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int setnum,t=0;
	while(cin>>setnum,setnum)
	{
		cout<<"Scenario #"<<++t<<"\n";
		int num;
		map <int ,int> team;
		for(int i=0 ; i<setnum ; i++)
		{
			cin>>num;
			for(int j=0 ; j<num ; j++)
			{
				int n;
				cin>>n;
				team.insert(pair<int ,int>(n,i));
			}
		}
		queue <int> queline ,queteam[1010];
		string cmd;
		while(cin>>cmd)
		{
			if(cmd=="STOP")break;
			
			else
			{
				if(cmd=="ENQUEUE")
				{
					int n,teamID;
					cin>>n;
					teamID=team[n];
					if(queteam[teamID].empty())
						queline.push(teamID);
					queteam[teamID].push(n);
				}
			
				else if(cmd=="DEQUEUE")
				{
					int teamID=queline.front();
					int n=queteam[teamID].front();
					cout<<n<<'\n';
					queteam[teamID].pop();
					if(queteam[teamID].empty())
						queline.pop();
				}
			}
		}
		cout<<'\n';
	}
	return 0;
}
