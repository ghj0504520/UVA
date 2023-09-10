#include<iostream>
#include<vector>
#include<map>
using namespace std;

class DJS
{
private:
	vector<int> Set;
public:
	DJS(int n)
	{
		this->Set.reserve(n);
		for (int i = 0; i < n; ++i)
		{
			Set[i] = i;
		}
	}
	void Union(int a, int b)
	{
		this->Set[ this->Find(a) ] = this->Find(b);
	}
	bool Same(int a, int b)
	{
		return this->Find(a) == this->Find(b);
	}
	int Find(int a)
	{
		return (this->Set[a] == a)? a:(this->Set[ a ]=this->Find( this->Set[ a ] ));
	}
};

int main()
{
    int N,M;
    while(cin>>N>>M)
    {
        DJS djs(N);
        map<char,int> MAP;
        vector<int> G[N];
        int id=0;
        
        string in;
        cin>>in;
        if(MAP.find(in[0])==MAP.end())
        {
            MAP[in[0]] = id++;
        }
        for(int i=1 ; i<3 ; i++)
        {
            if(MAP.find(in[i])==MAP.end())
            {
                MAP[in[i]] = id++;
            }
            djs.Union(MAP[in[0]],MAP[in[i]]);   
        }

        for(int m=0; m<M ; m++)
        {
            cin>>in;
            if(MAP.find(in[0])==MAP.end())
            {
                MAP[in[0]] = id++;
            }
            if(MAP.find(in[1])==MAP.end())
            {
                MAP[in[1]] = id++;
            }

            G[MAP[in[0]]].push_back(MAP[in[1]]);
            G[MAP[in[1]]].push_back(MAP[in[0]]);
        }

        int ans=0,setCnt=N-2;
        if(setCnt!=1)
        {
            while(1)
            {
                ans++;
                vector<int> act;
                for(int n=0 ; n<N ; n++)
                {
                    int edgeCnt=0;
                    if(!djs.Same(0,n))
                    {
                        int l = G[n].size();
                        for(int i=0 ; i<l ; i++)
                            if(djs.Same(0,G[n][i]))
                                edgeCnt++;
                        if(edgeCnt>=3)
                            act.push_back(n);
                    }
                }

                if(!act.size())
                    break;
                for(int i=0 ; i<act.size() ; i++)
                {
                    djs.Union(0,act[i]);
                    setCnt--;
                }
                if(setCnt==1)
                    break;
            }
        }

        if(setCnt==1)
        {
            cout<<"WAKE UP IN, "<<ans<<", YEARS\n";
        }else
        {
            cout<<"THIS BRAIN NEVER WAKES UP\n";
        }


    }
    return 0;
}