#include <iostream>
#include <map>
#include <sstream>
using namespace std;
bool checkOP(string ch)
{
	return ch==">"||ch=="<"||ch==">="||ch=="<="||ch=="=";
}
int main()
{
	ios::sync_with_stdio(0);
	int p,g;
	cin>>p>>g;
	map<string,int>table;
	for(int i=0 ; i<p ;i++)
	{
		string name;
		double rate;
		int num;
		cin>>name>>rate;
		num=rate*10;
		table[name]=num;
	}
	cin.ignore();
	string guess;
	for(int i =0 ; i<g; i++)
	{
		getline(cin,guess);
		int sum=0;
		stringstream buf(guess);
		string tmp;
		buf>>tmp;
		sum+=table[tmp];
		while(buf>>tmp)
		{
			if(checkOP(tmp))break;

			else if(tmp=="+")
			{
				buf>>tmp;
				sum+=table[tmp];
			}
		}
		double ans;
		buf>>ans;
		int INTans=ans*10;
		bool correct=0;

		//cout<<sum<<" "<<INTans<<"\n\n";

		if(tmp==">" && sum > INTans)
			correct=1;
		else if(tmp=="<" && sum < INTans)
			correct=1;
		else if(tmp==">=" && sum >= INTans)
			correct=1;
		else if(tmp=="<=" && sum <= INTans)
			correct=1;
		else if(tmp=="=" && sum == INTans)
			correct=1;
		cout<<"Guess #"<<i+1;
		correct? cout<<" was correct.\n":cout<<" was incorrect.\n";
	}
	return 0;
}