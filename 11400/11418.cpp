#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int adjMtx[1200][1200];
int parent[1200];
bool visited[1200];

int updateFlowRe(int s, int u, int v, int bottleNeck) // recursive update flow
{
	if(v == s) return bottleNeck;
	bottleNeck = updateFlowRe(s,parent[u],u,min( adjMtx[u][v], bottleNeck));
	adjMtx[u][v] -= bottleNeck;
	adjMtx[v][u] += bottleNeck;

	return bottleNeck;	
}

int updateFlowIt(int s,int t) // iterative update flow
{
	int cur=t, bottleNeck = INT_MAX;
	while(cur!=s)
	{
		bottleNeck = min(adjMtx[parent[cur]][cur],bottleNeck);
		cur = parent[cur];
	}
	for(int cur=t; cur!=s; cur=parent[cur])
	{
		adjMtx[parent[cur]][cur] -= bottleNeck;
		adjMtx[cur][parent[cur]] += bottleNeck;
	}
	return bottleNeck;
}

int main(int argc, char const *argv[])
{
	int N,num;
	cin>>N;

	int S,T,maxFlow;
	for(int t=0 ; t<N ; t++)
	{
		int num;
		cin>>num;
		
		S=0;
		maxFlow=0;

		memset(adjMtx,0,sizeof(adjMtx));
		
		map<string,int> dict;
		map<int, string> reDict;
		int wordCnt=0;

		//S(0)-> 1-groups-> 1-words-> 1-26-> T
		for(int i=0 ; i<num ; i++)
		{
			int k;
			cin>>k;
			string str;

			adjMtx[S][i+1]=1;   // from S to group with 1
			
			for(int j=0 ; j<k ; j++)
			{
				cin>>str;
				int len=str.length();
				for(int c=0 ; c<len ; c++)
					str[c] = tolower(str[c]);
				str[0] = toupper(str[0]);
				
				dict[str]= wordCnt;
				reDict[wordCnt] = str;
				wordCnt++;

				adjMtx[i+1][num+1+dict[str]]=1;  // from group to each word with 1
			}
		}

		T=num+wordCnt+26+1;
		
		for(int i=0 ; i<wordCnt ; i++)
			adjMtx[num+1+i][num+wordCnt+(reDict[i][0]-'A')+1] = 1; // from each word to alphabet with 1

		for(int i=0 ; i<26 ; i++)
			adjMtx[num+1+wordCnt+i][T] = 1;  // from each alphabet to T with 1


		// Edmonds–Karp Algorithm
		while(1)
		{
			queue<int> BFS;
			memset(parent,0, sizeof(parent));
			memset(visited,0, sizeof(visited));
			BFS.push(S);
			visited[S]=1;

			while(!BFS.empty()&&!visited[T])
			{
				int cur = BFS.front();
				BFS.pop();
				for(int next=S ; next<=T ; next++)
				{
					if(!visited[next]&&adjMtx[cur][next]>0)
					{
						BFS.push(next);
						visited[next]=1;
						parent[next] =cur;
					}
				}
			}

			if(!visited[T])break;
			maxFlow+= updateFlowIt(S,T);
		}
		
		vector<string> ans;
		for(int i=0 ; i<num ; i++)
		{
			for(int j=0 ; j<wordCnt ; j++)
			{
				if(adjMtx[num+j+1][1+i] == 1 )	// reverse is one imply from each group to word is exhaust,
					ans.push_back(reDict[j]);   // word in the group is selected
			}
		}

		sort(ans.begin(),ans.end());
		cout<<"Case #"<<t+1<<":\n";
		for(int i=0 ; i<ans.size() ; i++)
			cout<<ans[i]<<"\n";
	}

	return 0;
}