#include <iostream>

using namespace std;

bool prime_table[2000000]={0};
int main()
{
	prime_table[0]=1;
	prime_table[1]=1;
	for(int i=2; i<=1000000;i++)
		if(!prime_table[i])
			for(int j=i+i;j<=1000000 ; j+=i)
				prime_table[j]=1;
	int q;
	while(cin>>q,q)
	{
		cout<<q<<" = ";
		for(int i=0 ; i<=q ; i++)
		{
			if(!prime_table[i]&&!prime_table[q-i])
			{
				cout<<i<<" + "<<q-i<<"\n";
				break;
			}
		}

	}
	return 0;
}