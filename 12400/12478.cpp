#include <iostream>
#include <algorithm>

using namespace std;
string grid[20]=
{
	"obidaibkr","rkaulhisp",
	"sadiyanno","heisawhia",
	"irakibuls","mfbintrno",
	"utoyzifah","lebsynune",
	"emotiona","orshimulel",
	"bkaerftem","iadiabobo",
	"duiskiyst","alyainzyi",
	"ihawbtino","binhurfun",
	"ksnilnana","rpoasohel"
};
string name[10]=
{
	"rakibul","anindya",
	"moshiur","shiplu",
	"kabir","sunny",
	"obaida","wasi"
};
void check()
{
	for(int i=0 ; i<19 ; i++)
	{
		sort(grid[i].begin(),grid[i].end());
		cout<<i+1<<": "<<grid[i]<<"\n";
	}
	cout<<"\n\n\n";
	for(int i=0 ; i<9 ; i++)
	{
		sort(name[i].begin(),name[i].end());
		cout<<i+1<<": "<<name[i]<<"\n";
	}
}
int main()
{
	//check();
	cout<<"KABIR\n";
	return 0;
}