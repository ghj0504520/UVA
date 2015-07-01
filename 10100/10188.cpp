#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

bool check(string a,string u)
{
	int la=a.length(),lu=u.length();
	vector <int> numOrder,uOrder;
	for(int i=0 ; i<la ; i++)
		if(isdigit(a[i]))
			numOrder.push_back((int)a[i]);
	for(int i=0 ; i<lu ; i++)
		if(isdigit(u[i]))
			uOrder.push_back((int)u[i]);
			
	if(numOrder==uOrder)
		return 1;
	else
		return 0;
}

int main()
{
	int n,m,t=0;
	string ans,aln,user,uln;
	while(cin>>n,n)
	{
		ans="\0";
		user="\0";
		getchar();
		for(int i=0 ; i<n ; i++)
		{
			getline(cin,aln);
			ans+='\n'+aln;
		}
		cin>>m;
		getchar();
		for(int i=0 ; i<m ; i++)
		{
			getline(cin,uln);
			user+='\n'+uln;
		}
		cout<<"Run #"<<++t<<": ";
		if(user==ans)
			cout<<"Accepted\n";
		else
		{
			if(check(ans,user))
				cout<<"Presentation Error\n";
			else
				cout<<"Wrong Answer\n";
		}
	}
	return 0;
}
