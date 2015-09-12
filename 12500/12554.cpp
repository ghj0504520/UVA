#include <iostream>

using namespace std;

int main()
{
	int num;
	cin>>num;
	string name[200];
	for(int i=0 ; i<num ; i++)
		cin>>name[i];

	const string song[16]=
	{
		"Happy","birthday","to","you",
		"Happy","birthday","to","you",
		"Happy","birthday","to","Rujia",
		"Happy","birthday","to","you"
	};
	int index=0;
	for(int i=0 ; i<num ; i++)
	{
		cout<<name[i]<<": "<<song[index%16]<<"\n";
		index++;
	}
	int p=0;
	while(index%16)
	{
		cout<<name[p++]<<": "<<song[index%16]<<"\n";
		index++;
		if(p>=num)p=0;
	}


	return 0;
}