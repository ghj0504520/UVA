#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>

using namespace std;

int in[20000],pos[20000],Length,IDX;
void divideString(int order[],string tmp)
{
	int num,index=0;
	stringstream buf(tmp);
	while(buf>>num)
	{
		order[index++]=num;
	}
	Length=index;
}

map<int, int>inorderIndex;
void createIndex()
{
	for(int i=0 ; i<Length ; i++)
	{
		inorderIndex[in[i]]=i;
	}
}

struct node
{
	int data;
	node *left,*right;
	
	node(){}
	node(int value)
	{
		data=value;
		left=right=NULL;
	}
};

node *buildINPOS(int Start,int End)
{
	if(Start>End || IDX<0)return NULL;

	int cur=pos[IDX--];
	int pivot=inorderIndex[cur];
	node *ptr=new node;
	ptr->data=cur;
	ptr->right=buildINPOS(pivot+1,End);
	ptr->left=buildINPOS(Start,pivot-1);
	return ptr;
}

void inorder(node *cur)
{
	if(cur)
	{
		inorder(cur->left);
		cout<<cur->data<<" ";
		inorder(cur->right);
	}
}

int Bsum,Bkey;
bool isLeaf(node *cur)
{
	return cur->left==NULL && cur->right==NULL ? 1 : 0 ;
}
void dfsSum(node *cur,int sum)
{
	if(cur)
	{
		sum+=cur->data;
		if(isLeaf(cur))
		{
			if(sum<Bsum || (sum==Bsum && cur->data<Bkey))
			{
				Bsum=sum;
				Bkey=cur->data;
			}
		}
		dfsSum(cur->left,sum);
		dfsSum(cur->right,sum);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	string tmp;
	while(getline(cin,tmp))
	{
		divideString(in,tmp);
		getline(cin,tmp);
		divideString(pos,tmp);

		createIndex();
		IDX=Length-1;
		node *RCT=buildINPOS(0,Length-1);

		//inorder(RCT);
		
		Bsum=100000000;
		Bkey=100000000;
		dfsSum(RCT,0);
		cout<<Bkey<<"\n";
	}
	return 0;
}