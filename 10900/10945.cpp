#include <iostream>
#include <cctype>
using namespace std;

int check(string input)
{
	int start=0,trail=input.size()-1;
	while(1)
	{
		if(start>=trail)return 1;
		
		if(!isalpha(input[start]))
		{
			start++;
			continue;
		}
		if(!isalpha(input[trail]))
		{
			trail--;
			continue;
		}
		if(tolower(input[start])==tolower(input[trail]))
		{
			start++;
			trail--;
		}
		else return 0;
	}
}
int main()
{
	string in;
	while(getline(cin,in))
	{
		if(in=="DONE")break;
		
		check(in)? cout<<"You won't be eaten!\n" : cout<<"Uh oh..\n";
	}
	return 0;
}
