#include <iostream>
#include <map>
using namespace std;

map<char,int> sound;
void init()
{
	sound['B']=sound['F']=sound['P']=sound['V']=1;
	sound['C']=sound['G']=sound['J']=sound['K']=2;
	sound['Q']=sound['S']=sound['X']=sound['Z']=2;
	sound['D']=sound['T']=3;
	sound['M']=sound['N']=5;
	sound['L']=4;
	sound['R']=6;
}

int main(int argc, char const *argv[])
{
	string in;
	init();
	while(cin>>in)
	{
		int cur=-1, l = in.length();
		for(int i=0 ; i<l ; i++)
		{
			if(sound[in[i]]!=0&&sound[in[i]]!=cur)
			{
				cout<<sound[in[i]];
			}cur=sound[in[i]];
		}cout<<"\n";
	}
	return 0;
}