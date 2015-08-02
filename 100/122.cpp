#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct node
{
	bool exist;
	int data;
	node *left,*right;

	node()
	{
		exist=0;
		left=right=NULL;
	}
};

class ghjtree
{
private:
	node *root;
	bool success;
	vector <int>order;
public:
	ghjtree()
	{
		root=NULL;
		root=new node;
		success=1;
		order.clear();
	}
	void setSuccess()
	{
		clear(root);
		root=NULL;
		root=new node;
		order.clear();
		success=1;
	}
	bool getSuccess()
	{
		return success;
	}
	void insert(int val, string cmd)
	{
		int len=cmd.size();
		node *cur=root;
		for(int i=0 ; i<len ; i++)
		{
			if(cmd[i]=='L')
			{
				if(cur->left==NULL)
					cur->left=new node;
				cur=cur->left;
			}
			else if(cmd[i]=='R')
			{
				if(cur->right==NULL)
					cur->right=new node;
				cur=cur->right;
			}
		}
		if(cur->exist)success=0;
		cur->data=val;
		cur->exist=1;
	}
	vector<int> BFS()
	{
		queue<node *>bfs;
		bfs.push(root);
		while(!bfs.empty())
		{
			node *cur=bfs.front();
			bfs.pop();
			if(!cur->exist)
			{
				success=0;
				return order;
			}
			else
			{
				order.push_back(cur->data);
				if(cur->left!=NULL)
				{
					bfs.push(cur->left);
				}
				if(cur->right!=NULL)
				{
					bfs.push(cur->right);
				}
			}
		}
		return order;
	}
	void clear(node* cur)
	{
		if(cur==NULL)return ;
		clear(cur->left);
		clear(cur->right);
		delete cur;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	string in;
	bool start=0;
	ghjtree tree;
	while(cin>>in)
	{
		if(in=="()")
		{
			vector<int>ans= tree.BFS();
			bool Success=tree.getSuccess();
			if(Success)
			{
				int l=ans.size();
				for(int i=0 ; i<l ; i++)
				{
					if(i>0)cout<<" ";
					cout<<ans[i];
				}
				cout<<"\n";
			}
			else
			{
				cout<<"not complete\n";
			}
			tree.setSuccess();
		}
		else
		{
			int len =in.size();
			for(int i=0 ; i<len ; i++)
			{
				if(in[i]=='('||in[i]==','||in[i]==')')in[i]=' ';
			}
			stringstream buf(in);
			int value;
			string cmd;
			buf>>value>>cmd;
			tree.insert(value,cmd);
		}
	}
	return 0;
}