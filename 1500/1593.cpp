#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	string line,word;
	int row=0,col=0;
	int max_len[200]={0};
	vector <string> l_word[1010];
	while(getline(cin,line))
	{
		stringstream buf(line);
		while(buf>>word)
		{
			max_len[col]=max(max_len[col],(int)word.length());
			l_word[row].push_back(word);
			col++;
		}
		row++;
		col=0;
	}
	
	for(int i=0 ; i<row ; i++)
	{
		int j=0;
		for(vector <string> ::iterator it=l_word[i].begin() ; it!=l_word[i].end()-1 ; it++)
		{
			cout<<l_word[i][j];
			for(int p=0 ; p<=max_len[j]-l_word[i][j].size() ; p++)
			{
				cout<<' ';
			}
			j++;
		}
		cout<<l_word[i][j];
		cout<<"\n";
	}
	return 0;
}
