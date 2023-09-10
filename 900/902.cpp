#include <iostream>
#include <map>
using namespace std;

int main()
{
	int passwdLen;
	string passwdStr;
	while(cin>>passwdLen >>passwdStr)
	{
		map<string, int> passwdMAp;
		string passwd;
		int len = passwdStr.size();
		for(int i=0 ; i<len-passwdLen ; i++)
		{
			passwd = passwdStr.substr (i,passwdLen);
			passwdMAp[passwd]+=1;
		}

		int max=-1;
		passwd="";
		map<string, int>::iterator it;
		for(it= passwdMAp.begin() ; it!=passwdMAp.end() ; it++)
		{
			if(it->second > max){
				max = it->second;
				passwd = it->first;
			}
		}cout<<passwd<<'\n';
	}
}