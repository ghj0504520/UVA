#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		int pos=0,num;
		int data[100]={0};
		cin>>num;
		for(int i=0 ; i<num ; i++)
		{
			string cur;
			cin>>cur;
			if(cur=="LEFT")
			{
				data[i]=-1;
				pos--;
			}
			else if(cur=="RIGHT")
			{
				data[i]=1;
				pos++;
			}
			else if(cur=="SAME")
			{
				cin>>cur;
				int trace;
				cin>>trace;
				trace=data[trace-1];
				while(1)
				{
					if(trace==-1||trace==1)break;

					trace=data[trace-1];	
				}
				data[i]=trace;
				pos+=trace;
			}
		}cout<<pos<<"\n";
	}
	return 0;
}