#include<iostream>
#include<vector>
using namespace std;

class DJS
{
private:
	vector<int> Set,Num,Cnt;
public:
	DJS(int n)
	{
		this->Set.reserve(n+n+2);
		this->Num.reserve(n+n+2);
        this->Cnt.reserve(n+n+2);
		for (int i = 0; i <= n; ++i)
		{
			Set[i] = Set[i+n] = i+n;
			Num[i] = Num[i+n] = i;
            Cnt[i] = Cnt[i+n] = 1;
		}
	}
	void Union(int a, int b)
	{
        int num=this->Num[ this->Find(a) ],cnt=this->Cnt[ this->Find(a) ];
		this->Set[ this->Find(a) ] = this->Find(b);
        this->Num[ this->Find(b) ] += num;
        this->Cnt[ this->Find(b) ] += cnt;
	}
    void Move(int a, int b)
	{
        this->Num[ this->Find(a) ] -= a;
        this->Num[ this->Find(b) ] += a;
        this->Cnt[ this->Find(a) ] -= 1;
        this->Cnt[ this->Find(b) ] += 1;

		this->Set[ a ] = this->Find(b);
	}
	bool Same(int a, int b)
	{
		return this->Find(a) == this->Find(b);
	}
	int Find(int a)
	{
		return (this->Set[a] == a)? a:(this->Set[ a ]=this->Find( this->Set[ a ] ));
	}
	int SetNum(int a)
	{
		return this->Num[this->Find(a)];
	}
    int SetCnt(int a)
	{
		return this->Cnt[this->Find(a)];
	}
};


int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        DJS djs(n);
        int cmd,a,b;
        
        while(m--)
        {
            cin>>cmd;

            if(cmd==1)
            {
                cin>>a>>b;
                if(!djs.Same(a,b))
                    djs.Union(a,b);
            }else if(cmd==2)
            {
                cin>>a>>b;
                if(!djs.Same(a,b))
                    djs.Move(a,b);
                
            }else if(cmd==3)
            {
                cin>>a;
                cout<<djs.SetCnt(a)<<" "<<djs.SetNum(a)<<"\n";
            }
        }
    }
    return 0;
}