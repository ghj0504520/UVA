#include <iostream>
#include <cstring>
#define MAX 200

using namespace std;
int SUM[MAX];
bool finish;

void divideTree(int index)
{
	int val;
	cin>>val;
	if(val==-1)return ;
	SUM[index]+=val;	
	divideTree(index-1);
	divideTree(index+1);
}

void startTree()
{
	int val,mid;
	cin>>val;
	if(val==-1)
	{
		finish=1;
		return ;
	}
	mid=MAX/2;
	SUM[mid]+=val;
	divideTree(mid-1);
	divideTree(mid+1);
}

int main()
{
	int t=0;
	while(1)
	{
		finish=0;
		memset(SUM,0,sizeof(SUM));
		startTree();
		if(finish)break;
		cout<<"Case "<<++t<<":\n";
		int p=0;
		while(!SUM[p])p++;
		while(SUM[p]&&SUM[p+1])cout<<SUM[p++]<<" ";
		cout<<SUM[p];
		cout<<"\n\n";
	}
	return 0;
}