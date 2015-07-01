#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std;

map < set<int> ,int > setID;						//injective each set and id number
vector < set<int> > cacheset;						//transfer each set to id number	
int renameID(set<int> X)							//create injective function
{
	map < set<int> ,int >::iterator it;
	it=setID.find(X);
	if(it!=setID.end())
		return it->second;
	else
	{
		cacheset.push_back(X);
		return setID[X]=cacheset.size()-1;
	}
}
/*
 * operation:
 * 
 * use renameID transfer set to id number 
 * 
 * push the id number of each set into stack
 * 
 * use id number by vector container named "cacheset" to query the size of stack's top
 * 
 */
void Push(stack <int> &inS)
{
	set <int> x;
	inS.push(renameID(x));							
	cout<<cacheset[inS.top()].size()<<'\n';
}
void Dup(stack <int> &inS)
{
	set <int> x=cacheset[inS.top()];
	inS.push(renameID(x));
	cout<<cacheset[inS.top()].size()<<'\n';
}
void Union(stack <int> &inS)
{
	set <int> x1,x2,x;
	x1=cacheset[inS.top()];
	inS.pop();
	x2=cacheset[inS.top()];
	inS.pop();
	set_union(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));  //set_union and inserter 
	inS.push(renameID(x));
	cout<<cacheset[inS.top()].size()<<'\n';
}
void Intersection(stack <int> &inS)
{
	set <int> x1,x2,x;
	x1=cacheset[inS.top()];
	inS.pop();
	x2=cacheset[inS.top()];
	inS.pop();
	set_intersection(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));   //set_intersection and inserter
	inS.push(renameID(x));
	cout<<cacheset[inS.top()].size()<<'\n';
}
void Add(stack <int> &inS)
{
	set <int> x1,x2,x;
	x1=cacheset[inS.top()];
	inS.pop();
	x2=cacheset[inS.top()];
	inS.pop();
	x=x2;
	x.insert(renameID(x1));
	inS.push(renameID(x));
	cout<<cacheset[inS.top()].size()<<'\n';
}
int main()
{
	int num;
	cin>>num;
	for(int i=0 ; i<num ; i++)
	{
		stack <int> s;
		int n;
		string cmd;
		cin>>n;
		for(int j=0 ; j<n ; j++)
		{
			cin>>cmd;
			
			if(cmd=="PUSH")Push(s);
			
			else if(cmd=="DUP")Dup(s);
			
			else if(cmd=="UNION")Union(s);
			
			else if(cmd=="INTERSECT")Intersection(s);
			
			else if(cmd=="ADD")Add(s);
		
		}cout<<"***\n";
	}
	return 0;
}
