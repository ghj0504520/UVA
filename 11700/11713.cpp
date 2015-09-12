#include <iostream>

using namespace std;

bool vowel(char c)
{
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string a,b;
		cin>>a>>b;
		int al=a.size(),bl=b.size();
		if(al!=bl)
		{
			cout<<"No\n";
			continue;
		}
		bool check=1;
		for(int i=0 ; i<al ; i++)
		{
			if(a[i]!=b[i] && (!vowel(a[i])||!vowel(b[i])) )
			{
				check=0;break;
			}
		}
		check? cout<<"Yes\n" : cout<<"No\n";
	}
	return 0;
}