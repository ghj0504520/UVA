#include<iostream>
using namespace std;
int main()
{
	int own,find,ch,num;
	while(cin>>num)
	{
		while(num--){
			cin>>own>>find>>ch;

			int sum=0,p=0;
			own+=find;

			while(own>=ch)
			{
				int p=own/ch;
				sum+=p;
				own%=ch;
				own+=p;

			}cout<<sum<<'\n';
		}
	}

}
