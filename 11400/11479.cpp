#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long int read;

	long long int data[3];
	while(cin>>read)
	{
		for(long long int i=0;i<read;i++)
		{

			cin>>data[0]>>data[1]>>data[2];
			sort(data,data+3);
			cout<<"Case "<<i+1<<": ";
			if(data[0]+data[1]<=data[2])
				cout<<"Invalid\n";
			else{
				if(data[0]==data[1]&&data[0]==data[2])
					cout<<"Equilateral\n";
				else 
				{
					if(data[0]==data[1]&&data[1]!=data[2])
						cout<<"Isosceles\n";
					else if(data[0]!=data[1]&&data[1]==data[2])
						cout<<"Isosceles\n";
					else 
						cout<<"Scalene\n";
				}
			}

		}
	}
}
