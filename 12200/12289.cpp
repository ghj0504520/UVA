#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=0 ; i<n ; i++)
	{
		string word;
		cin>>word;
		int len=word.size();
		if(len==5)cout<<"3\n";
		else
		{
			int table[30]={0};
			table[word[0]-'a']=1;
			table[word[1]-'a']=1;
			table[word[2]-'a']=1;
			if(table['o'-'a']+table['n'-'a']+table['e'-'a']>=2)
			{
				cout<<"1\n";
			}
			else if(table['t'-'a']+table['w'-'a']+table['o'-'a']>=2)
			{
				cout<<"2\n";
			}
		}
	}
	return 0;
}
