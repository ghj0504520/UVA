#include <iostream>

using namespace std;

string m[110];
bool alive;

bool check(int r, int c, int n)
{
	return r>=0&&r<n&&c>=0&&c<n&& (m[r][c]=='x'||m[r][c]=='@');
}

void dfs(int r, int c, int n)
{
	//cout<<r<<c<<m[r][c]<<'\n';
	if(m[r][c]=='x')alive=1;
	m[r][c] = '.';
	for(int i=1 ; i<=n/2 ; i++)
	{
		if(check(r+i,c,n))
			dfs(r+i, c, n);
		else break;
	}
	for(int i=1 ; i<=n/2 ; i++)
	{
		if(check(r,c+i,n))
			dfs(r, c+i, n);
		else break;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int r=0 ; r<t ; r++)
	{
		int n;
		cin>>n;

		for(int i=0 ; i<n ; i++)
			cin>>m[i];
		int ans = 0;
		for(int i=0 ; i<n ; i++)
			for(int j=0 ; j<n ; j++)
			{
				alive=0;
				if(m[i][j]=='x'||m[i][j]=='@')
					dfs(i, j, n);
				if(alive)
					ans++;
			}
		cout<<"Case "<<r+1<<": "<<ans<<'\n';

		for(int i=0 ; i<n ; i++)
			m[i]="\0";
	}
	return 0;
}