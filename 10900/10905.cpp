#include<iostream>
#include<algorithm>
using namespace std;
bool compare(const string& i,const string& j)
{
    return i+j  <   j+i;
}
int main()
{
	int a;
	while(cin>>a){
		if(a==0)break;
		string  data[100];
		for(int i=0;i<a;i++)
			cin>>data[i];
		sort(data,data+a,compare);
		for(int i=a-1;i>=0;i--)
			cout<<data[i] ;
		cout<<'\n';
	}
}

