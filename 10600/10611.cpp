#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int num;
	cin>>num;
	int hight[50010]={0};
	for (int i = 0; i < num; ++i)
		cin>>hight[i];
	sort(hight,hight+num);
	int ask;
	cin>>ask;
	for (int i = 0; i < ask; ++i)
	{
		int q;
		cin>>q;
		int *it1,*it2;
		it1=lower_bound(hight,hight+num,q);
		it2=upper_bound(hight,hight+num,q);
		int low=(it1-hight)-1;
		int high=(it2-hight);
		if(low==-1)
			cout<<"X ";
		else	cout<<hight[low]<<" ";

		if(hight[high]==q)high++;

		if(!hight[high])
			cout<<"X\n";
		else	cout<<hight[high]<<"\n";
	}
	return 0;
}
/*
lower_bound and upper_bound based on binary search

to lower_bound
	if find , it will return the smallest iterator of the key value
	else , it will return the iterator whose value is bigger than key value

to upper_bound
	if find , it will return the largest iterator of the key value
	else  , it will return the iterator whose value is bigger than key value

so if not found lower_bound and upper_bound will return equate value 
*/