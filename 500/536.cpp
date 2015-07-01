#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

struct node
{
	int data;
	node *left,*right;
};

map<char,int> tableindex;
void buildindex(string in,int len)
{
	for(int i=0 ; i<len ; i++)
	{
		tableindex.insert(pair<char,int>(in[i],i));
		//cout<<i<<" "<<in[i]<<'\n';
	}
}
int flag=0;
node *buildtree_PreIn(string in,string pre,int Idxstart,int Idxend)
{
	
	if(Idxstart > Idxend)return NULL;
	int rootData=pre[flag++];
	int Idx=tableindex[rootData];
	node *root=new node;
	root->data=rootData;
	
	root->left=buildtree_PreIn(in,pre,Idxstart,Idx-1);
	root->right=buildtree_PreIn(in,pre,Idx+1,Idxend);
	return root;
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%c",root->data);
		inorder(root->right);
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%c",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void posorder(node *root)
{
	if(root!=NULL)
	{
		posorder(root->left);
		posorder(root->right);
		printf("%c",root->data);
	}
}
int main()
{
	string in,pre;
	while(cin>>pre>>in)
	{
		tableindex.clear();
		flag=0;
		int len=in.size();
		buildindex(in,len);
		node *root=NULL;
		root=buildtree_PreIn(in,pre,0,len-1);
		posorder(root);
		cout<<"\n";
	}
	return 0;
}
