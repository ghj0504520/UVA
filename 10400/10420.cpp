#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int num;
	map <string,int> data;
	cin>>num;
	for(int i=0 ; i<num ; i++)
	{
		string country,nothing;
		cin>>country;
		getline(cin,nothing);
		map <string,int>::iterator it;
		it=data.find(country);
		if(it==data.end())
		{
			data[country]=1;
		}
		else
		{
			data[country]++;
		}
	}
	for(map <string,int>::iterator it=data.begin();it!=data.end();it++)
	{
		cout<<it->first<<' '<<it->second<<'\n';
	}
	return 0;
}

/*                  				//not use map
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int numLine;
    while(cin>>numLine)
    {
        string name[3000];
        for(int i=0;i<numLine;i++)
        {
            string nothing;
            cin>>name[i];
            getline(cin,nothing);
        }
        sort(name,name+numLine);
        int sum;
        for(int i=0;i<numLine;i++)
        {
            sum=1;
            while(name[i]==name[i+1])
            {
                sum++;
                i++;
            }
            cout<<name[i]<<" "<<sum<<'\n';
        }
    }
    return 0;
}
*/
