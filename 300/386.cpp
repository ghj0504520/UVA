#include <iostream>

using namespace std;

int main()
{
	for(int i=2 ; i<=200 ; i++)
	{
		for(int j=2 ; j<=200 ; j++)
		{
			for(int k=j ; k<=200 ; k++)
			{
				for(int m=k ; m<=200 ; m++)
				{
					if(j!=k&&k!=m&&m!=j&&(i*i*i==j*j*j+k*k*k+m*m*m))
					{
						cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<m<<")\n";
					}
				}
			}
		}
	}
	return 0;
}