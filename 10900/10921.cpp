#include <iostream>
#include <map>

using namespace std;

map<char,int>code;

void init()
{
	code.insert(std::pair<char,int>('A',2));code.insert(std::pair<char,int>('B',2));
	code.insert(std::pair<char,int>('C',2));code.insert(std::pair<char,int>('D',3));
	code.insert(std::pair<char,int>('E',3));code.insert(std::pair<char,int>('F',3));
	code.insert(std::pair<char,int>('G',4));code.insert(std::pair<char,int>('H',4));
	code.insert(std::pair<char,int>('I',4));code.insert(std::pair<char,int>('J',5));
	code.insert(std::pair<char,int>('K',5));code.insert(std::pair<char,int>('L',5));
	code.insert(std::pair<char,int>('M',6));code.insert(std::pair<char,int>('N',6));
	code.insert(std::pair<char,int>('O',6));code.insert(std::pair<char,int>('P',7));
	code.insert(std::pair<char,int>('Q',7));code.insert(std::pair<char,int>('R',7));
	code.insert(std::pair<char,int>('S',7));code.insert(std::pair<char,int>('T',8));
	code.insert(std::pair<char,int>('U',8));code.insert(std::pair<char,int>('V',8));
	code.insert(std::pair<char,int>('W',9));code.insert(std::pair<char,int>('X',9));
	code.insert(std::pair<char,int>('Y',9));code.insert(std::pair<char,int>('Z',9));
}

int main()
{
	init();
	string telnum;
	while(cin>>telnum)
	{
		int len=telnum.size();
		for(int i=0 ; i<len ; i++)
		{
			char cur=telnum[i];
			if(code.count(cur))
			{
				cout<<(char)(code[cur]+'0');
			}
			else
				cout<<cur;
		}
		cout<<"\n";
	}
	return 0;
} 