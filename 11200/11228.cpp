#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class DJS
{
private:
	vector<int> S;
public:
	DJS(int n)
	{
		this->S.reserve(n);
		for (int i = 0; i < n; ++i)
		{
			S[i] = i;
		}
	}
	void Union(int a, int b)
	{
		this->S[ this->Find(a) ] = this->Find(b);
	}
	bool Same(int a, int b)
	{
		return this->Find(a) == this->Find(b);
	}
	int Find(int a)
	{
		return (this->S[a] == a)? a:(this->S[ a ]=this->Find( this->S[ a ] ));
	}
};

struct coord
{
    int X,Y;
    coord(int x,int y)
    {
        this->X=x;
        this->Y=y;
    }
    double dis(const coord &a)
	{
		return sqrt((this->X-a.X)*(this->X-a.X) + (this->Y-a.Y)*(this->Y-a.Y));
	}
};

struct edge
{
    int S,T;
    double D;
    edge(int s,int t,double d)
    {
        S=s;
        T=t;
        D=d;
    }
    bool operator<(const edge& a) const {
        return this->D < a.D;
    }
};

vector<edge> E;
void kruskal(int n,int r)
{
	sort(E.begin(),E.end());
	DJS djs(n);
	int len = E.size();
    int state=1;
    double rail=0.0, road=0.0;
	for(int i=0 ; i<len ; i++)
	{
		edge cur = E[i];
		if(!djs.Same(cur.S,cur.T))
		{
			djs.Union(cur.S,cur.T);
            if(cur.D >r)
            {
                rail+=cur.D;
                state++;
            }else
            {
                road+=cur.D;
            }
		}
	}

    cout<<" "<<state<<" "<< (int)(road + 0.5) << " " << (int)(rail + 0.5) << "\n";
    return ;
}

int main()
{
    int T;
    cin>>T;
    for(int t=1 ; t<=T ; t++)
    {
        cout<<"Case #"<<t<<":";
        int n,r;
        cin>>n>>r;

        E.clear();
		vector<coord> C;

		int x,y;
		for(int i=0 ; i<n ; i++)
		{
			cin>>x>>y;
			C.push_back(coord(x,y));
		}

        for(int i=0 ; i<n ; i++)
		{
			for(int j=i+1 ; j<n ; j++)
			{
				E.push_back(edge(i,j,C[i].dis(C[j])));	
			}
		}
        kruskal(n,r);

    }
    return 0;
}